/**
	add dropoff zone location column to the parking violations file
	Command : spark-shell --master yarn --conf spark.ui.port=4050
*/

/*
|-- geometry: struct (nullable = true)
|    |-- coordinates: array (nullable = true)
|    |    |-- element: array (containsNull = true)
|    |    |    |-- element: array (containsNull = true)
|    |    |    |    |-- element: array (containsNull = true)
|    |    |    |    |    |-- element: double (containsNull = true)
|    |-- type: string (nullable = true)
|-- geometry_name: string (nullable = true)
|-- id: string (nullable = true)
|-- properties: struct (nullable = true)
|    |-- bbox: array (nullable = true)
|    |    |-- element: double (containsNull = true)
|    |-- borough: string (nullable = true)
|    |-- locationid: long (nullable = true)
|    |-- objectid: long (nullable = true)
|    |-- shape_area: double (nullable = true)
|    |-- shape_leng: double (nullable = true)
|    |-- zone: string (nullable = true)
|-- type: string (nullable = true)
*/

import org.apache.spark.sql.types._
import org.apache.spark.sql.functions._

/* load files */
val JSON_FILE_NAME = "taxi-zones-geojson2.json"
val CSV_FILE_NAME = "2016_yellow_trip.csv"
val csvDf = spark.read.format("csv").option("header", "true").load(CSV_FILE_NAME)
val jsonSchema = new StructType().add("geometry", StringType).add("geometry_name", StringType).add("id",StringType).add("properties", StringType).add("type", StringType)
val jsonDf = spark.read.option("type", "geojson").schema(jsonSchema).json(JSON_FILE_NAME)

// update id colum to match source id
val cleanId = udf((id: String) => {
	id.replace("nyu_2451_36743.", "")
})

// create new column in dataFrame with udf
val updatedJsonDf = jsonDf.withColumn("id", cleanId($"id"))
updatedJsonDf.select($"id").show()

// join result with csv
val updatedCsv = csvDf.join(
	updatedJsonDf, csvDf.col("DOLocationID") ===  updatedJsonDf.col("id"), "left_outer"
)

// write output csv file
updatedCsv.coalesce(1).write.mode("overwrite").csv("csv_export_taxi")

/**
	add dropoff zone location column to the parking violations file
	Command : spark-shell --master yarn --conf spark.ui.port=4050
*/

//import scala.util.parsing.json._

/* load files */
val FILE_ID = "2431-36743"
val JSON_FILE_NAME = "taxi-zones-geojson.json"
val CSV_FILE_NAME = "extract_taxi.csv"
val jsonDf = spark.read.json(JSON_FILE_NAME)
val csvDf = spark.read.format("csv").option("header", "true").load(CSV_FILE_NAME)

/*  */
val features = jsonDf.select($"features")

/* create new column in dataFrame with udf */
/*
val updatedDf = df.withColumn("dozone_location", findLocation(
	$"House Number", $"Street Name", $"Intersecting Street"
))
updatedDf.show()
*/

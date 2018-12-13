/* spark-shell --master yarn --conf spark.ui.port=4050 */

/* open csv data file */
val df = spark.read.format("csv").option("header", "true").load("extract_violations.csv")
// df.show()

val locations = df.select($"House Number", $"Street Name", $"Intersecting Street")

/* map columns to a function */
val findLocation = udf((houseNumber: String, streetName: String, intersectingStreet: String) => {
	// TODO get location from API
	houseNumber + streetName + intersectingStreet
})

val newDf = locations.withColumn("location", findLocation(
	$"House Number", $"Street Name", $"Intersecting Street"
))

/* write output csv file */
df.coalesce(1).write.csv("csv_export")

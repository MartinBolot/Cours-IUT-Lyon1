/**
	add location column to the parking violations file
	Command : spark-shell --master yarn --conf spark.ui.port=4050
*/

/* open csv data file and put it in a dataFrame */
val VIOLATIONS_FILE_2016 = "Parking_Violations_Issued_-_Fiscal_Year_2016.csv"
val VIOLATIONS_FILE_2017 = "Parking_Violations_Issued_-_Fiscal_Year_2017.csv"
val df2016 = spark.read.format("csv").option("header", "true").load(VIOLATIONS_FILE_2016)
val df2017 = spark.read.format("csv").option("header", "true").load(VIOLATIONS_FILE_2017)
val refinedDf2016 = df2016.select(
	$"Plate ID", $"Registration State", $"Issue Date", $"Violation Code",
	$"House Number", $"Street Name", $"Intersecting Street"
)
val refinedDf2017 = df2017.select(
	$"Plate ID", $"Registration State", $"Issue Date", $"Violation Code",
	$"House Number", $"Street Name", $"Intersecting Street"
)
val df = refinedDf2016.unionAll(refinedDf2017)

/* map columns to a function */
def getUrlQuery(houseNumber: String = "", streetName: String = "", intersectingStreet: String = "") : String = {
	s"${houseNumber.replace(" ","+").replace("&", "")}+,+${streetName.replace(" ", "+").replace("&", "")}+,+${intersectingStreet.replace(" ", "+").replace("&", "")}+,+NEW-YORK"
}
/* build url from query and limit */
def getLocationUrl(query: String = "", limit : Int = 0) : String = {
	s"http://178.33.122.183:2322/api/?q=${query}&limit=${limit}"
}

/* user defined function to retrieve new column value */
val findLocation = udf((houseNumber: String, streetName: String, intersectingStreet: String) => {
	scala.io.Source
		.fromURL(
			getLocationUrl(
				getUrlQuery(
					(if (houseNumber != null) houseNumber else "" ),
					(if (streetName != null) streetName else ""),
					(if (intersectingStreet != null) intersectingStreet else "")
				) , 1
			)
		)
		.mkString
})

/* create new column in dataFrame with udf */
val updatedDf = df.withColumn("location", findLocation(
	$"House Number", $"Street Name", $"Intersecting Street"
))
updatedDf.show()

/* write output csv file */
updatedDf.coalesce(1).write.mode("overwrite").csv("csv_export_violations")

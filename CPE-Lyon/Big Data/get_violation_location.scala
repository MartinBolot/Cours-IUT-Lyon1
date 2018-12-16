/**
	add location column to the parking violations file
	Command : spark-shell --master yarn --conf spark.ui.port=4050
*/

/* open csv data file and put it in a dataFrame */
val VIOLATIONS_FILE = "extract_violations.csv"
val df = spark.read.format("csv").option("header", "true").load(VIOLATIONS_FILE)

//val locations = df.select($"House Number", $"Street Name", $"Intersecting Street")

/* map columns to a function */
def getUrlQuery(houseNumber: String = "", streetName: String = "", intersectingStreet: String = "") : String = {
	s"${houseNumber.replace(" ","+")}+,+${streetName.replace(" ", "+")}+,+${intersectingStreet.replace(" ", "+")}+,+NEW-YORK"
}
/* build url from query and limit */
def getLocationUrl(query: String = "", limit : Int = 0) : String = {
	s"http://178.33.122.183:2322/api/?q=${query}&limit=${limit}"
}
/* add limitation to the result (first n results) */
def limitedParamUrl(url: String = "") : String = {
	url + "&limit=1"
}

/* user defined function to retrieve new column value */
val findLocation = udf((houseNumber: String, streetName: String, intersectingStreet: String) => {
	scala.io.Source
		.fromURL(
			limitedParamUrl(
				getLocationUrl(
					getUrlQuery(
						(if (houseNumber != null) houseNumber else "" ),
						(if (streetName != null) streetName else ""),
						(if (intersectingStreet != null) intersectingStreet else "")
					) , 1
				)
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
updatedDf.coalesce(1).write.mode("overwrite").csv("csv_export_location")

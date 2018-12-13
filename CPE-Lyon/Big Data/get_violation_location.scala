/* spark-shell --master yarn --conf spark.ui.port=4050 */

/* open csv data file */
val VIOLATIONS_FILE = "extract_violations.csv"
val df = spark.read.format("csv").option("header", "true").load(VIOLATIONS_FILE)
// df.show()

//val locations = df.select($"House Number", $"Street Name", $"Intersecting Street")

/* map columns to a function */
def getUrlQuery(houseNumber: String = "", streetName: String = "", intersectingStreet: String = "") : String = {
	s"${houseNumber.replace(" ","+")}+,+${streetName.replace(" ", "+")}+,+${intersectingStreet.replace(" ", "+")}+,+NEW-YORK"
}
def getLocationUrl(query: String = "", limit : Int = 0) : String = {
	s"http://178.33.122.183:2322/api/?q=${query}&limit=${limit}"
}
def limitedParamUrl(url: String = "") : String = {
	url + "&limit=1"
}


val findLocation = udf((houseNumber: String, streetName: String, intersectingStreet: String) => {
	// TODO get location from API
	//houseNumber + streetName + intersectingStreet
	/*scala.io.Source
		.fromURL(
			limitedParamUrl(
				getLocationUrl(getUrlQuery(houseNumber, streetName, intersectingStreet), 1)
			)
		)
		.mkString
		*/
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

val updatedDf = df.withColumn("location", findLocation(
	$"House Number", $"Street Name", $"Intersecting Street"
))
updatedDf.show()


/*
val url = "http://178.33.122.183:2322/api/?q=65+BAYARD+STREET+,+MANHATTAN+,+NEW-YORK"
val limitedAPICall = url + "&limit=1"
val result = scala.io.Source.fromURL(limitedAPICall).mkString
print(result)
*/

/* write output csv file */
updatedDf.coalesce(1).write.mode("overwrite").csv("csv_export_location")

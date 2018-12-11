/* spark-shell --master yarn --conf spark.ui.port=4050 */

val resultsDF = spark.sql("SELECT COUNT(1) FROM refine1_violations")
resultsDF.show()

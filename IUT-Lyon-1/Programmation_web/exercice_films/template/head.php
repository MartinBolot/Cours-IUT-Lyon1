<?php
	/**
	*	creates the "head" part of the html document
	*	@param string $title the title to include
	*	@return string the html "head" tag content
	*/
	function getHead($title){
		return (
			"
				<title> Films - $title </title>
				<meta charset=\"UTF-8\" />
				<link rel=\"stylesheet\" href=\"res/css/bootstrap.min.css\" type=\"text/css\" />
				<link rel=\"stylesheet\" href=\"res/css/styles.css\" type=\"text/css\" />
			"
		);
	}
?>

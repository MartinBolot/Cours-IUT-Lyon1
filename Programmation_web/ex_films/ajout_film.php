<?php
	header('Content-Type: text/html; charset=utf-8');	// declaring encoding and content-type for the page
	require_once("template/head.php");	// head
	require_once("template/menu.php");	// menu
	require_once("autoload.php");	// autoload for classes

	$cssPageClass = "ajout_film";	// defining html page class

?>
<!doctype html>
<html>
	<head>
		<?php print(getHead("Ajouter un film"));	/* printing html head tag */ ?>
	</head>
<body>
	<h1>Ajouter un film</h1>
	<?php
		// in case no entry has been submitted yet
		// display form
		if(count($_POST) === 0){
			?>
				<div id="global" class=<?php echo "\"".$cssPageClass."\"" ?> >
					<?php print(getMenu());	/* printing html menu */ ?>
					<div id="content">
						<form action="#" method="post">
							<div class="form_field">
								<label>
									<span class="label_title">Nom du film :</span>
									<input type="text" name="nom_film"/>
								</label>
							</div>
							<div class="form_field">
								<label>
									<span class="label_title">Année de sortie du film :</span>
									<input type="number" name="annee_film" value="1900"/>
								</label>
							</div>
							<div class="form_field">
								<label>
									<span class="label_title">Score du film :</span>
									<input type="number" name="score_film" value="0"/>
								</label>
							</div>
							<div class="form_field">
								<input type="submit" class="btn btn-primary"/>
							</div>
						</form>
					</div>
					<div class="form_buttons">
						<p>
							<span>
								<a href="index.php">Retour à la liste</a>
							</span>
						</p>
					</div>
				</div>
			<?php
		// in case form has already been submitted
		// handle data and display the response
		}else{
			$succesMessage = "Le film <b>'".$_POST["nom_film"]."'</b> a bien été ";	// preparing success message
			$errorMessage = "L'ajout du film a échoué";	// message to display if an error occured while inserting or update data
			$backLink = "<div class='back_link'><a class='btn btn-primary' href='ajout_film.php'>Retour</a></div>";	// html link to go back to the form page

			// if form field are stored in $_POST superglobal but nom_film is empty
			if(isset($_POST["nom_film"]) && $_POST["nom_film"] === ""){
				$errorMessage = "Erreur : le nom du film est obligatoire";
			// if form field are stored in $_POST and nom_film is not empty
			}else{
				$repository = new FilmRepository();	// creating the repository for Film objects
				$filmToAdd = new Film((string)$_POST["nom_film"], (int)$_POST["annee_film"], (float)$_POST["score_film"]);	// creatign the Film object we need to add to the database
				$filmStored = $repository->save($filmToAdd);	// saving the Film object

				// completing the messages considering the status of the request
				switch($filmStored){
					case 0 :
						$succesMessage.="ajouté";
						break;
					case 1 :
						$succesMessage.="édité";
						break;
					default:
						$succesMessage.="ajouté";
				}
			}

			?>
				<div id="global" class=<?php echo "\"".$cssPageClass."\"" ?> >
					<div class='success_confirm'>
						<?php echo(($filmStored === 2 ? $errorMessage : $succesMessage));	/* displaying error or success message */ ?>
					</div>
					<?php echo($backLink); ?>
				</div>
			<?php
		}
	?>
	</body>
</html>

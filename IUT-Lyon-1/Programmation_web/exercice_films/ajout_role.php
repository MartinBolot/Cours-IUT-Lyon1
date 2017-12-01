<?php
	header('Content-Type: text/html; charset=utf-8');	// declaring encoding and content-type for the page
	require_once("template/head.php");	// head
	require_once("template/menu.php");	// menu
	require_once("autoload.php");	// autoload for classes

	$cssPageClass = "ajout_role";	// defining html page class

?>
<!doctype html>
<html>
	<head>
		<?php print(getHead("Ajouter un role"));	/* printing html head tag */ ?>
	</head>
<body>
	<h1>Ajouter un role</h1>
	<?php
		// in case no entry has been submitted yet
		// display form
		if(count($_POST) === 0){
			$filmRepository = new FilmRepository();	//creating a repository for Film objects
			$acteurRepository = new ActeurRepository();	//creating a repository for Acteur objects
			$filmList = $filmRepository->getAll();	//retieving all Film objects
			$acteurList = $acteurRepository->getAll();	//retieving all Acteur objects
			?>
				<div id="global" class=<?php echo "\"".$cssPageClass."\"" ?> >
					<?php print(getMenu());	/* printing html menu */ ?>
					<div id="content">
						<form action="#" method="post">
							<div class="form_field">
								<label>
									<span class="label_title">Nom de l'acteur :</span>
									<select name="acteur">
										<?php
											//iterating over Acteur objects and print each one as an option
											foreach($acteurList as $acteur){
												print("<option value=".$acteur->getId().">".$acteur->getPrenom()." ".$acteur->getNom()."</option>");
											}
										?>
									</select>
								</label>
							</div>
							<div class="form_field">
								<label>
									<span class="label_title">Film :</span>
									<select name="film">
										<?php
											//iterating over Film objects and print each one as an option
											foreach($filmList as $film){
												print("<option value=".$film->getId().">".$film->getNom()."</option>");
											}
										?>
									</select>
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
			$succesMessage = "Le couple film/acteur a bien été ajouté";	// preparing success message
			$errorMessage = "L'ajout du rôle à échoué";	// message to display if an error occured while inserting or update data
			$backLink = "<div class='back_link'><a class='btn btn-primary' href='ajout_role.php'>Retour</a></div>";	// html link to go back to the form page
			$castingStored = 2;	// SQL status, defaults to error

			// if form field are stored in $_POST superglobal
			if(isset($_POST["film"]) && isset($_POST["acteur"])){
				$castingRepository = new castingRepository();	// creating the repository for Casting objects
				$castingToAdd = new Casting((int)$_POST["film"],(int)$_POST["acteur"]);	// creatign the Casting object we need to add to the database
				$castingStored = $castingRepository->save($castingToAdd);	// saving the Casting object

				//if the actor/movie couple is alreay stored in DB, update error message
				if($castingStored === 1){
					$errorMessage.=", ce casting est déjà présent dans la base";
				}
			}

			?>
				<div id="global" class=<?php echo "\"".$cssPageClass."\"" ?> >
					<div class='success_confirm'>
						<?php echo(($castingStored === 2 || $castingStored === 1 ? $errorMessage : $succesMessage)); 	/* displaying error or success message */ ?>
					</div>
					<?php echo($backLink); ?>
				</div>
			<?php
		}
	?>
	</body>
</html>

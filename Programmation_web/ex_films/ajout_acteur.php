<?php
	header('Content-Type: text/html; charset=utf-8');	// declaring encoding and content-type for the page
	require_once("template/head.php");	// head
	require_once("template/menu.php");	// menu
	require_once("autoload.php");	// autoload for classes

	$cssPageClass = "ajout_acteur";	// defining html page class

?>
<!doctype html>
<html>
	<head>
		<?php print(getHead("Ajouter un acteur"));	/* printing html head tag */ ?>
	</head>
<body>
	<h1>Ajouter un acteur</h1>
	<?php
		// in case no entry has been submitted yet
		// display form
		if(count($_POST) === 0){
			?>
				<div id="global" class=<?php echo "\"".$cssPageClass."\"" ?> >
					<?php print(getMenu()); /* printing html menu */ ?>
					<div id="content">
						<form action="#" method="post">
							<div class="form_field">
								<label>
									<span class="label_title">Nom de l'acteur :</span>
									<input type="text" name="nom_acteur"/>
								</label>
							</div>
							<div class="form_field">
								<label>
									<span class="label_title">Prenom de l'acteur :</span>
									<input type="text" name="prenom_acteur"/>
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
			$errorMessage = "L'ajout de l'acteur a échoué";	// message to display if an error occured while inserting or update data
			$backLink = "<div class='back_link'><a class='btn btn-primary' href='ajout_acteur.php'>Retour</a></div>";	// html link to go back to the form page
			$acteurStored = 2;	// SQL status, defaults to error

			// if form field are stored in $_POST superglobal
			if(isset($_POST["nom_acteur"]) && isset($_POST["prenom_acteur"])){
				// if nom_acteur is empty
				if($_POST["nom_acteur"] === ""){
					$errorMessage = "Erreur : le nom de l'acteur est obligatoire";
				// if prenom_acteur is empty
				}elseif($_POST["prenom_acteur"] === ""){
					$errorMessage = "Erreur : le prenom de l'acteur est obligatoire";
				}else{
					$repository = new ActeurRepository();	// creating the repository for Acteur objects
					$acteurToAdd = new Acteur((string)$_POST["nom_acteur"],(string)$_POST["prenom_acteur"]);	// creatign the Acteur object we need to add to the database
					$acteurStored = $repository->save($acteurToAdd);	// saving the Acteur object
					$succesMessage = "L'acteur <b>'".$_POST["prenom_acteur"]." ".$_POST["nom_acteur"]."'</b> a bien été ";	// preparing success message

					// completing the messages considering the status of the request
					switch($acteurStored){
						case 0 :
							$succesMessage.="ajouté";
							break;
						case 1 :
							$errorMessage.=", l'acteur est déjà présent dans la base";
							break;
						default:
							$succesMessage.="ajouté";
					}
				}
			}

			?>
				<div id="global" class=<?php echo "\"".$cssPageClass."\"" ?> >
					<div class='success_confirm'>
						<?php echo(($acteurStored === 2 || $acteurStored === 1 ? $errorMessage : $succesMessage)); /* displaying error or success message */ ?>
					</div>
					<?php echo($backLink); ?>
				</div>
			<?php
		}
	?>
	</body>
</html>

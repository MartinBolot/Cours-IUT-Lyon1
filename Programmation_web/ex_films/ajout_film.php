<?php
	header('Content-Type: text/html; charset=utf-8');
	require_once("template/head.php");
	require_once("template/menu.php");

	require_once("autoload.php");

	$cssPageClass = "ajout_film";

?>
<!doctype html>
<html>
	<head>
		<?php print(getHead("Ajouter un film")); ?>
	</head>
<body>
	<h1>Ajouter un film</h1>
	<?php
		// in case no entry has been submitted yet
		if(count($_POST) === 0){
			?>
				<div id="global" class=<?php echo "\"".$cssPageClass."\"" ?> >
					<?php print(getMenu()); ?>
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
		}else{
			$succesMessage = "Le film <b>'".$_POST["nom_film"]."'</b> a bien été ";
			$errorMessage = "L'ajout du film a échoué";
			$backLink = "<div class='back_link'><a class='btn btn-primary' href='ajout_film.php'>Retour</a></div>";

			if(isset($_POST["nom_film"]) && $_POST["nom_film"] === ""){
				$errorMessage = "Erreur : le nom du film est obligatoire";
			}else{
				$repository = new FilmRepository();
				$filmToAdd = new Film((string)$_POST["nom_film"], (int)$_POST["annee_film"], (float)$_POST["score_film"]);
				$filmStored = $repository->save($filmToAdd);

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
						<?php echo(($filmStored === 2 ? $errorMessage : $succesMessage)); ?>
					</div>
					<?php echo($backLink); ?>
				</div>
			<?php
		}
	?>
	</body>
</html>

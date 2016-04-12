<?php
	header('Content-Type: text/html; charset=utf-8');
	require_once("../connect_db.php");
	require_once("template/head.php");
	require_once("template/menu.php");

	require_once("autoload.php");

	$cssPageClass = "ajout_film";

	if(count($_POST)==0){
		?>
			<!doctype html>
			<html>
				<head>
					<?php print(getHead("Ajouter un film")); ?>
				</head>
				<body>
					<div id="global" class=<?php echo "\"".$cssPageClass."\"" ?> >
						<?php print(getMenu()); ?>
						<div id="content">
							<form action="" method="post">
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
					</div>
				</body>
			</html>
		<?php
	}else{
		$repository = new FilmRepository();
		$errorMessage = "";
		$succesMessage="";
		$backLink = "<div class='back_link'><a class='btn btn-primary' href='ajout_film.php'>Retour</a></div>";

		if(isset($_POST["nom_film"]) && $_POST["nom_film"]==""){
			$errorMessage = "Erreur : le nom du film est obligatoire";
		}else{

			$filmToAdd = new Film(null,$_POST["nom_film"],(int)$_POST["annee_film"],$_POST["score_film"]);
			$filmStorage = $repository->add($filmToAdd);

			switch($filmStorage){
				case 0:
					$succesMessage = "Le film <b>'".$_POST["nom_film"]."'</b> a bien été ajouté";
					break;
				case 2:
					$errorMessage = "Erreur : le film est deja present dans la base !";
					break;
				default:
					$errorMessage = "L'ajout du film a échoué";
			}

		}

		/*displaying template*/
		?>
			<!doctype html>
			<html>
				<head>
					<?php print(getHead("Ajouter un film")); ?>
				</head>
				<body>
					<div id="global" class=<?php echo "\"".$cssPageClass."\"" ?> >
						<div class='success_confirm'>
							<?php echo(($filmStorage===0 ? $succesMessage : $errorMessage)); ?>
						</div>
						<?php echo($backLink); ?>
					</div>
				</body>
			</html>
		<?php

	}
?>

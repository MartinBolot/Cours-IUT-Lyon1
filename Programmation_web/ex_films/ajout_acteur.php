<?php
	header('Content-Type: text/html; charset=utf-8');
	require_once("template/head.php");
	require_once("template/menu.php");

	require_once("autoload.php");

	$cssPageClass = "ajout_acteur";

?>
<!doctype html>
<html>
	<head>
	<?php print(getHead("Ajouter un acteur")); ?>
</head>
<body>
	<?php
		// in case no entry has been submitted yet
		if(count($_POST) === 0){
			?>
				<div id="global" class=<?php echo "\"".$cssPageClass."\"" ?> >
					<?php print(getMenu()); ?>
					<div id="content">
						<form action="" method="post">
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
		}else{
			$errorMessage = "L'ajout de l'acteur a échoué";
			$backLink = "<div class='back_link'><a class='btn btn-primary' href='ajout_acteur.php'>Retour</a></div>";
			$acteurStored = 2;

			if(isset($_POST["nom_acteur"]) && isset($_POST["prenom_acteur"])){
				if($_POST["nom_acteur"] === ""){
					$errorMessage = "Erreur : le nom de l'acteur est obligatoire";
				}elseif($_POST["prenom_acteur"] === ""){
					$errorMessage = "Erreur : le prenom de l'acteur est obligatoire";
				}else{
					$repository = new ActeurRepository();
					$acteurToAdd = new Acteur((string)$_POST["nom_acteur"],(string)$_POST["prenom_acteur"]);
					$acteurStored = $repository->save($acteurToAdd);
					$succesMessage = "L'acteur <b>'".$_POST["prenom_acteur"]." ".$_POST["nom_acteur"]."'</b> a bien été ";

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
						<?php echo(($acteurStored === 2 || $acteurStored === 1 ? $errorMessage : $succesMessage)); ?>
					</div>
					<?php echo($backLink); ?>
				</div>
			<?php
		}
	?>
	</body>
</html>

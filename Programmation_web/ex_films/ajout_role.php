<?php
	header('Content-Type: text/html; charset=utf-8');
	require_once("template/head.php");
	require_once("template/menu.php");

	require_once("autoload.php");

	$cssPageClass = "ajout_role";

?>
<!doctype html>
<html>
	<head>
		<?php print(getHead("Ajouter un role")); ?>
	</head>
<body>
	<h1>Ajouter un role</h1>
	<?php
		// in case no entry has been submitted yet
		if(count($_POST) === 0){
			$filmRepository = new FilmRepository();
			$acteurRepository = new ActeurRepository();
			$filmList = $filmRepository->getAll();
			$acteurList = $acteurRepository->getAll();
			?>
				<div id="global" class=<?php echo "\"".$cssPageClass."\"" ?> >
					<?php print(getMenu()); ?>
					<div id="content">
						<form action="#" method="post">
							<div class="form_field">
								<label>
									<span class="label_title">Nom de l'acteur :</span>
									<select name="acteur">
										<?php
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
		}else{
			$succesMessage = "Le couple film/acteur a bien été ajouté";
			$errorMessage = "L'ajout du rôle à échoué";
			$backLink = "<div class='back_link'><a class='btn btn-primary' href='ajout_role.php'>Retour</a></div>";
			$castingStored = 2;

			if(isset($_POST["film"]) && isset($_POST["acteur"])){
				$castingRepository = new castingRepository();
				$castingToAdd = new Casting((int)$_POST["film"],(int)$_POST["acteur"]);
				$castingStored = $castingRepository->save($castingToAdd);

				if($castingStored === 1){
					$errorMessage.=", ce casting est déjà présent dans la base";
				}
			}

			?>
				<div id="global" class=<?php echo "\"".$cssPageClass."\"" ?> >
					<div class='success_confirm'>
						<?php echo(($castingStored === 2 || $castingStored === 1 ? $errorMessage : $succesMessage)); ?>
					</div>
					<?php echo($backLink); ?>
				</div>
			<?php
		}
	?>
	</body>
</html>

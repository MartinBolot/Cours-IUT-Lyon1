<?php
	/* setting header */
	header('Content-Type: text/html; charset=utf-8');

	/* requiring template parts */
	require_once("template/head.php");
	require_once("template/menu.php");
	require_once("template/partials/film_row.php");
	require_once("template/partials/staging_row.php");

	/* autoloading classes */
	require_once("autoload.php");	//automaticly loads all classes

	/* getting the array of films from database */
	$filmRepository = new FilmRepository();
	$filmList = $filmRepository->getAll();
	$castingRepository = new CastingRepository();
?>

<!doctype html>
<html>
	<head>
		<?php print(getHead("Gestion des films")); ?>
	</head>
	<body>
		<h1>Affichage des films</h1>
		<div id="global">
			<?php print(getMenu()); ?>
			<div id="content">
				<?php
					if(isset($_GET["id_film"])){
						$film = $filmRepository->getFilmById((int)$_GET["id_film"]);
						echo("<h2>".($film ? $film->getNom() : "" )."</h2>");
					}
				?>
				<div class="form_table">
					<table>
						<?php
							if(isset($_GET["id_film"])){
								$acteurList = $castingRepository->getStaringActors($_GET["id_film"]);
								?>
									<tr>
										<th>Nom</th>
										<th>Prenom</th>
									</tr>
									<?php
										/* iterates over films in filmlist and display each one from row template */
										if(count($acteurList) > 0){
											foreach($acteurList as $acteur){
												print(getStagingRow($acteur));
											}
										}else{
											echo "<tr><td colspan='4'>Aucun acteur dans ce film</td></tr>";
										}
									?>
								<?php
							}else{
								?>
									<tr>
										<th>Nom</th>
										<th>Année</th>
										<th>Score</th>
										<th>Acteurs</th>
									</tr>
									<?php
										/* iterates over films in filmlist and display each one from row template */
										if(count($filmList) > 0){
											foreach($filmList as $film){
												print(getFilmRow($film));
											}
										}else{
											echo "<tr><td colspan='4'>Aucun film pour le moment</td></tr>";
										}
									?>
								<?php
							}
						?>
					</table>
				</div>
				<div class="form_buttons">
					<p>
						<?php
							if(isset($_GET["id_film"])){
								?>
									<span>
										<a href="index.php">Retour à la liste</a>
									</span>
								<?php
							}else{
								?>
									<span>
										<a class="btn btn-primary" href="ajout_film.php">Ajouter un film</a>
									</span>
									<span>
										<a class="btn btn-primary" href="ajout_acteur.php">Ajouter un acteur</a>
									</span>
									<span>
										<a class="btn btn-primary" href="ajout_role.php">Ajouter un rôle</a>
									</span>
								<?php
							}
						?>
					</p>
				</div>
			</div>
		</div>
	</body>
</html>

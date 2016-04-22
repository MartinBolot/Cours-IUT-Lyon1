<?php
    Class FilmRepository extends Repository{

        /**
        *   constructor wich queries DB for films
        *   @return void
        */
        public function __construct(){
            $this->pdoConnect = connectDb();
            $query = $this->pdoConnect->prepare("select id_film,nom_film,annee_film,score from films");
            $query->execute();
            $films = $query->fetchAll();

            foreach($films as $film){
                $filmObject = new Film(
                    $film['nom_film'],
                    $film['annee_film'],
                    $film['score']
                );
                $filmObject->setId($film['id_film']);
                array_push($this->filmArray,$filmObject);
            }
        }


        /**
        *   add a film in the database
        *   @param film a film object
        *   @return int if the update was executed correctly or not
        *       => 0 if insert was executed
        *       => 1 if update was executed
        *       => 2 if an error happend
        */
        public function save($film){
			$testQuery = $this->pdoConnect->prepare("select count(*) as nb from films where nom_film=?");
			$testQuery->execute(array($_POST["nom_film"]));

			$data = $testQuery->fetch();

			if($data["nb"] > 0){
				$query = $this->pdoConnect->prepare("update p1506898.films set annee_film =:annee,score=:score where lower(nom_film)=lower(:nom)");
				$insert = $query->execute(array(
					'nom' => $film->getNom(),
					'annee' => $film->getAnnee(),
					'score' => $film->getScore()
				));

                return ($insert ? 1 : 2);
			}else{
				$query = $this->pdoConnect->prepare("insert into p1506898.films(nom_film,annee_film,score) values(:nom,:annee,:score)");
				$insert = $query->execute(array(
					'nom' => $film->getNom(),
					'annee' => $film->getAnnee(),
					'score' => $film->getScore()
				));

                return ($insert ? 0 : 2);
			}
        }

        /**
        *   gets the actors playing in the given movie
        *   @param int $idFilm the id of the movie
        *   @return Acteur array $acteurArray an array (possibly empty) representing the result of the query
        */
        public function getStaringActors($idFilm){
            $acteurArray = array();

            if(isset($idFilm) && (int)$idFilm >= 0){
                $acteurRepository = new acteurRepository();

                $query = $this->pdoConnect->prepare("select id_acteur from casting where id_film=?");
                $query->execute(array((int)$idFilm));
                $acteurs = $query->fetchAll();

                foreach($acteurs as $acteur){
                    array_push($acteurArray,$acteurRepository->getActeurById($acteur["id_acteur"]));
                }
            }

            return $acteurArray;
        }

        /**
        *   get all films from DB
        *   @return a key=>value array containing all the films
        */
        public function getAll(){
            return $this->filmArray;
        }

        private $filmArray = array();
    }

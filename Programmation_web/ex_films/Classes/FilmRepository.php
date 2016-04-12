<?php
    require_once("../connect_db.php");

    Class FilmRepository{

        /**
        *   constructor wich queries DB for films
        */
        public function __construct(){
            $bdd = connectDb();
            $query = $bdd->prepare("select id_film,nom_film,annee_film,score from films");
            $query->execute();
            $films = $query->fetchAll();

            foreach($films as $film){
                $filmObject = new Film(
                    $film['id_film'],
                    $film['nom_film'],
                    $film['annee_film'],
                    $film['score']
                );
                array_push($this->filmArray,$filmObject);
            }
        }

        /**
        *   add a film in the database
        *   @return int status code :
        *       0 if insertion went OK
        *       1 if the object given is not a film
        *       2 if the film was already stored in DB
        *       3 if something went wrong with the insert command
        */
        public function add($film){
            if(get_class($film)==="Film"){
                $bdd = connectDb();
    			$testQuery = $bdd->prepare("select count(*) as nb from films where nom_film=?");
    			$testQuery->execute(array($_POST["nom_film"]));

    			$data = $testQuery->fetch();

    			if($data["nb"]>0){
                    return 2;
    			}else{
    				$query = $bdd->prepare("insert into p1506898.films(nom_film,annee_film,score) values(:nom,:annee,:score)");
    				$insert = $query->execute(array(
    					'nom' => $film->getNom(),
    					'annee' => $film->getAnnee(),
    					'score' => $film->getScore()
    				));

    				if($insert){
    					return 0;
    				}else{
                        return 3;
    				}
    			}
    		}else{
                throw new Exception("Erreur : l'objet fourni n'est pas un objet film correct");
                return 1;
    		}
        }

        /**
        *   get all films from DB
        *   @return a key=>value array containing all the films
        */
        public function getAllFilms(){
            return $this->filmArray;
        }

        private $filmArray = array();
        private $idMax=0;
    }

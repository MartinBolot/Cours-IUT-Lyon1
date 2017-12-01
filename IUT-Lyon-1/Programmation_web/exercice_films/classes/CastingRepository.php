<?php
    Class CastingRepository extends Repository{

            /**
            *   constructor wich queries DB for castings
            *   @return void
            */
            public function __construct(){
                $this->pdoConnect = connectDb();
                $query = $this->pdoConnect->prepare("select id_film,id_acteur from casting");
                $query->execute();
                $castings = $query->fetchAll();

                foreach($castings as $casting){
                    $castingObject = new Casting(
                        $casting['id_film'],
                        $casting['id_acteur']
                    );
                    array_push($this->castingArray,$castingObject);
                }
            }


            /**
            *   add a casting in the database
            *   @param casting a casting object
            *   @return int if the update was executed correctly or not
            *       => 0 if insert was executed
            *       => 1 if the casting is already present
            *       => 2 if an error happend
            */
            public function save($casting){
    			$testQuery = $this->pdoConnect->prepare("select count(*) as nb from casting where id_film=? and id_acteur=?");
    			$testQuery->execute(array($casting->getIdFilm(),$casting->getIdActeur()));

    			$data = $testQuery->fetch();

    			if($data["nb"] > 0){
    				return 1;
    			}else{
    				$query = $this->pdoConnect->prepare("insert into casting values(:id_film,:id_acteur)");
    				$insert = $query->execute(array(
    					'id_film' => $casting->getIdFilm(),
    					'id_acteur' => $casting->getIdActeur()
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
                    $query = $this->pdoConnect->prepare("select id_acteur,nom,prenom from casting natural join acteurs where id_film=?");
                    $query->execute(array((int)$idFilm));
                    $acteurs = $query->fetchAll();

                    foreach($acteurs as $acteur){
                        array_push($acteurArray,new Acteur($acteur["nom"],$acteur["prenom"]));
                    }
                }

                return $acteurArray;
            }

            /**
            *   get all castings from DB
            *   @return a key=>value array containing all the castings
            */
            public function getAll(){
                return $this->castingArray;
            }

            private $castingArray = array();
    }

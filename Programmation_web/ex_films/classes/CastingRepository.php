<?php
    Class CastingRepository extends Repository{

            /**
            *   constructor wich queries DB for castings
            *   @return void
            */
            public function __construct(){
                $this->pdoConnect = connectDb();
                $query = $this->pdoConnect->prepare("select id_casting,id_acteur from casting");
                $query->execute();
                $castings = $query->fetchAll();

                foreach($castings as $casting){
                    $castingObject = new Casting(
                        $casting['id_casting'],
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
    			$testQuery->execute(array($_POST["film"],$_POST["acteur"]));

    			$data = $testQuery->fetch();

    			if($data["nb"] > 0){
    				return 1;
    			}else{
    				$query = $this->pdoConnect->prepare("insert into p1506898.casting values(:id_film,:id_acteur)");
    				$insert = $query->execute(array(
    					'id_film' => $casting->getIdFilm(),
    					'id_acteur' => $casting->getIdActeur()
    				));

                    return ($insert ? 0 : 2);
    			}
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

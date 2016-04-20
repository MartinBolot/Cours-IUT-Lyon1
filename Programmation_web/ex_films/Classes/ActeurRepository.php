<?php
    Class ActeurRepository extends Repository{

        /**
        *   constructor wich queries DB for acteurs
        *   @return void
        */
        public function __construct(){
            $this->pdoConnect = connectDb();
            $query = $this->pdoConnect->prepare("select id_acteur,nom_acteur,prenom_acteur from acteurs");
            $query->execute();
            $acteurs = $query->fetchAll();

            foreach($acteurs as $acteur){
                $acteurObject = new Acteur(
                    $acteur['nom_acteur'],
                    $acteur['prenom_acteur']
                );
                $acteurObject->setId($acteur['id_acteur']);
                array_push($this->acteurArray,$acteurObject);
            }
        }


        /**
        *   add a film in the database
        *   @param film a film object
        *   @return int if the update was executed correctly or not
        *       => 0 if insert was executed
        *       => 1 if the acteur is already present
        *       => 2 if an error happend
        */
        public function save($acteur){
			$testQuery = $this->pdoConnect->prepare("select count(*) as nb from acteurs where nom_acteur=? and prenom_acteur=?");
			$testQuery->execute(array($_POST["nom_acteur"],$_POST["prenom_acteur"]));

			$data = $testQuery->fetch();

			if($data["nb"] > 0){
				return 1;
            }else{
    			$query = $this->pdoConnect->prepare("insert into p1506898.acteurs(nom_acteur,prenom_acteur) values(:nom,:prenom)");
    			$insert = $query->execute(array(
    				'nom' => $acteur->getNom(),
    				'prenom' => $acteur->getPrenom()
    			));
                return ($insert ? 0 : 2);
            }
        }

        /**
        *   get all acteurs from DB
        *   @return a key=>value array containing all the acteurs
        */
        public function getAll(){
            return $this->acteurArray;
        }

        private $acteurArray = array();
        private $idMax = 0;
    }

<?php
    Class ActeurRepository extends Repository{

        /**
        *   constructor wich queries DB for acteurs
        */
        public function __construct(){
            $this->pdoConnect = connectDb();
            $query = $this->pdoConnect->prepare("select id_acteur,nom,prenom from acteurs");
            $query->execute();
            $acteurs = $query->fetchAll();

            foreach($acteurs as $acteur){
                $acteurObject = new Acteur(
                    $acteur['nom'],
                    $acteur['prenom']
                );
                $acteurObject->setId($acteur['id_acteur']);
                array_push($this->acteurArray,$acteurObject);
            }
        }


        /**
        *   add a film in the database
        *   @param $acteur a film object
        *   @return int if the update was executed correctly or not
        *       => 0 if insert was executed
        *       => 1 if the item is already present
        *       => 2 if an error happend
        */
        public function save($acteur){
			$testQuery = $this->pdoConnect->prepare("select count(*) as nb from acteurs where nom=? and prenom=?");
			$testQuery->execute(array($acteur->getNom(),$acteur->getPrenom()));

			$data = $testQuery->fetch();

			if($data["nb"] > 0){
				return 1;
            }else{
    			$query = $this->pdoConnect->prepare("insert into acteurs(nom,prenom) values(:nom,:prenom)");
    			$insert = $query->execute(array(
    				'nom' => $acteur->getNom(),
    				'prenom' => $acteur->getPrenom()
    			));
                return ($insert ? 0 : 2);
            }
        }

        /**
        *   get an item given an id
        *   @param $id the id
        *   @return $acteur an object of type Acteur
        */
        public function getActeurById($id){
            if(isset($id) && (int)$id >= 0){
                foreach($this->acteurArray as $acteur){
                    if($acteur->getId() === $id){
                        return $acteur;
                    }
                }
            }
        }

        /**
        *   get all acteurs from DB
        *   @return a key=>value array containing all the items
        */
        public function getAll(){
            return $this->acteurArray;
        }

        private $acteurArray = array();
    }

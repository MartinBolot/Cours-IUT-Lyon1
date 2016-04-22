<?php

    Class Film{

        /**
        *   Constructor
        *   @param string $nom : title
        *   @param int $annee : year
        *   @param float $score : rating score
        */
        public function __construct($nom,$annee,$score){
            if($nom === null){
                die("Erreur : impossible de creer un film sans nom");
            }
            $this->nom = $nom;
            if(isset($annee)){
                $this->annee = $annee;
            }
            if(isset($score)){
                $this->score = $score;
            }
        }

        /**
        *   gets the value of the field nom_field
        *   @return string title
        */
        public function getNom(){
            return $this->nom;
        }
        /**
        *   gets the value of the field annee_film
        *   @return int year
        */
        public function getAnnee(){
            return $this->annee;
        }
        /**
        *   gets the value of the field score
        *   @return float score
        */
        public function getScore(){
            return $this->score;
        }
        /**
        *   gets the value of the field id_film
        *   @return int id
        */
        public function getId(){
            return $this->id;
        }

        /**
        *   sets the value of the field id_film
        *   @param int $id (must be >= 0)
        */
        public function setId($id){
            if($id >= 0){
                $this->id = (int)$id;
            }else{
                die("Erreur : un acteur doit avoir id positif");
            }
        }
        /**
        *   sets the value of the field nom_film
        *   @param string $nom
        */
        public function setNom($nom){
            $this->nom = $nom;
        }
        /**
        *   sets the value of the field annee_film
        *   @param int $annee
        */
        public function setAnnee($annee){
            $this->annee = $annee;
        }
        /**
        *   sets the value of the field score
        *   @param float score
        */
        public function setScore($score){
            $this->score = $score;
        }

        private $id;
        private $nom;
        private $annee;
        private $score;
    }

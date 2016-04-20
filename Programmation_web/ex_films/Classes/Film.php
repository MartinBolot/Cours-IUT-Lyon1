<?php

    Class Film{
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

        /* getters */
        public function getNom(){
            return $this->nom;
        }
        public function getAnnee(){
            return $this->annee;
        }
        public function getScore(){
            return $this->score;
        }
        public function getId(){
            return $this->id;
        }

        /* setters*/
        public function setId($id){
            $this->id = (int)$id;
        }
        public function setNom($nom){
            $this->nom = $nom;
        }
        public function setAnnee($annee){
            $this->annee = $annee;
        }
        public function setScore($score){
            $this->score = $score;
        }

        private $id;
        private $nom;
        private $annee;
        private $score;
    }

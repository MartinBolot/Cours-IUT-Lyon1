<?php

    Class Film{
        public function __construct($id,$nom,$annee,$score){
            if($nom===null){
                throw new Error("Impossible de creer un film sans nom");
            }
            $this->id = $id;
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

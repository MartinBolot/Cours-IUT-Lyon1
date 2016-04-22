<?php
    Class Casting{
        /**
        *   Constructor
        */
        public function __construct($id_film,$id_acteur){
            if((int)$id_film >= 0 && (int)$id_acteur >= 0){
                $this->id_film = (int)$id_film;
                $this->id_acteur = (int)$id_acteur;
            }else{
                die("Erreur : l'id du film et de l'acteur doivent être positifs");
            }
        }

        /**
        *   gets the value of the field id_film
        *   @return int the id of the movie
        */
        public function getIdFilm(){
            return $this->id_film;
        }
        /**
        *   gets the value of the field id_acteur
        *   @return int the id of the actor
        */
        public function getIdActeur(){
            return $this->id_acteur;
        }

        /**
        *   sets the value of the field id_film
        *   @param int $id_film the id of the movie
        */
        public function setIdFilm($id_film){
            if((int)$id_film >= 0){
                $this->idFilm = $id_film;
            }else{
                die("Erreur : l'id du film doit être positif");
            }
        }
        /**
        *   sets the value of the field id_acteur
        *   @param int $id_acteur the id of the actor
        */
        public function setIdActeur($id_acteur){
            if((int)$id_acteur >= 0){
                $this->id_acteur = $id_acteur;
            }else{
                die("Erreur : l'id de l'acteur doit être positif");
            }
        }

        private $id_film;
        private $id_acteur;
    }

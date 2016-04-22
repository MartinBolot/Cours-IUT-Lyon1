<?php

    abstract class Personne{
        /**
        *   gets the value of the field nom
        *   @return string name
        */
        public function getNom(){
            return $this->nom;
        }
        /**
        *   gets the value of the field prenom
        *   @return string first-name
        */
        public function getPrenom(){
            return $this->prenom;
        }
        /**
        *   gets the value of the field id
        *   @return int id
        */
        public function getId(){
            return $this->id;
        }

        /**
        *   sets the value for the field nom
        *   @param string $nom (must not be empty)
        */
        public function setNom($nom){
            if($nom && $nom !== ""){
                $this->nom = $nom;
            }else{
                die(" Erreur : un acteur doit avoir nom");
            }
        }
        /**
        *   sets the value for the field prenom
        *   @param string $prenom (must not be empty)
        */
        public function setPrenom($prenom){
            if($prenom && $prenom !== ""){
                $this->prenom = $prenom;
            }else{
                die("Erreur : un acteur doit avoir prenom");
            }
        }
        /**
        *   sets the value for the field id
        *   @param int $id (must be >= 0)
        */
        public function setId($id){
            if($id >= 0){
                $this->id = (int)$id;
            }else{
                die("Erreur : un acteur doit avoir id positif");
            }
        }

        private $id;
        private $nom;
        private $prenom;
    }

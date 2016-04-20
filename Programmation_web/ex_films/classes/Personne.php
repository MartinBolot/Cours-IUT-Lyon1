<?php

    abstract class Personne{
        /*getters*/
        public function getNom(){
            return $this->nom;
        }
        public function getPrenom(){
            return $this->prenom;
        }
        public function getId(){
            return $this->id;
        }
        /*setters*/
        public function setNom($nom){
            if($nom && $nom !== ""){
                $this->nom = $nom;
            }else{
                die(" Erreur : un acteur doit avoir nom");
            }
        }
        public function setPrenom($prenom){
            if($prenom && $prenom !== ""){
                $this->prenom = $prenom;
            }else{
                die("Erreur : un acteur doit avoir prenom");
            }
        }
        public function setId($id){
            if($id >= 0){
                $this->id = $id;
            }else{
                die("Erreur : un acteur doit avoir id positif");
            }
        }

        private $id;
        private $nom;
        private $prenom;
    }

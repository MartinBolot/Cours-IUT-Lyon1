<?php
    Class Acteur extends Personne{
        /**
        *   Constructor
        *   @param string $nom : name
        *   @param string $prenom : first-name
        */
        public function __construct($nom,$prenom){
            if($nom === null || $prenom === null){
                die("Erreur : un acteur doit avoir nom et prenom");
            }elseif($nom === "" || $prenom === ""){
                die("Erreur : un acteur doit avoir nom et prenom non-vides");
            }
            else{
                $this->setNom($nom);
                $this->setPrenom($prenom);
            }
        }
    }

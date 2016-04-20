<?php
    Class Acteur extends Personne{
        public function __construct($nom,$prenom){
            if($nom === null || $prenom === null){
                die("Erreur : un acteur doit avoir nom et prenom");
            }elseif($nom ==="" || $prenom ===""){
                die("Erreur : un acteur doit avoir nom et prenom non-vides");
            }
            else{
                $this->setNom($nom);
                $this->setPrenom($prenom);
            }
        }
    }

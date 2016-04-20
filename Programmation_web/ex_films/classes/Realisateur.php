<?php
    Class Realisateur extends Personne{
        public function __construct($nom,$prenom){
            if($nom === null || $nom !=="" || $prenom === null || $prenom !==""){
                throw new Error("Un realisateur doit avoir nom et prenom");
            }else{
                $this->nom = $nom;
                $this->prenom = $prenom;
            }
        }
    }

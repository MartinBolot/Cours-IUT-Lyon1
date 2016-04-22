<?php
    require_once("../connect_db.php");
    abstract Class Repository{
        /**
        *   save the given object in database
        *   @param (Acteur,Casting,Film) $obj
        */
        abstract public function save($obj);
        /**
        *   gets every database row for current class objects
        */
        abstract public function getAll();
        
        private $pdoConnect;
    }

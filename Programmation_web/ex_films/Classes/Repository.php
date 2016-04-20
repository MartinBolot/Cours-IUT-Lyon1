<?php
    require_once("../connect_db.php");
    abstract Class Repository{
        abstract public function save($obj);
        abstract public function getAll();
        private $pdoConnect;
    }

<?php

spl_autoload_register(function($classname)
{
    // on suppose classe dans son propre fichier portant le même nom
    // class Animal => Animal.php
    $file = __DIR__.'/Classes/'.$classname.'.php';

    // echo 'classe '.$classname.' inconnue -> chargement de '.$file."\n";
    require_once($file);
});

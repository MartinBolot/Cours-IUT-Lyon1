<?php
    function getMenu(){
        return(
            "
                <div id='menu'>
                    <ul>
                        <li><a href='gestion_film.php'> Gestion des films </a></li>
                        <li><a href='ajout_film.php'> Ajouter un film </a></li>
                        <li><a href='ajout_acteur.php'> Ajouter un acteur </a></li>
                        <li><a href='casting.php'> Gérer les castings </a></li>
                    </ul>
                </div>
            "
        );
    }
?>

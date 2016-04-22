<?php
    /**
    *   creates a html table row for a given Film object
    *   @param Film $film the movie to display
    *   @return string the html table row
    */
    function getFilmRow($film){
        if($film->getNom()){

            $id = $film->getId();
            $nom = $film->getNom();
            $annee = $film->getAnnee();
            $score = $film->getScore();

            return(
                "
                    <tr>
                        <td>". $nom ."</td>
                        <td>". ( $annee ? $annee : "" ) ."</td>
                        <td>". ( $score ? $score : "" ) ."</td>
                        <td><a href='?id_film=".$id."'>Voir</a></td>
                    </tr>
                "
            );

        }else{ return ""; }
    }
?>

<?php
    //Film row in film management table
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

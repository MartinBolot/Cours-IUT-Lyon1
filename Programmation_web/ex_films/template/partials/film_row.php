<?php
    //Film row in film management table
    function getFilmRow($film){
        if($film->getNom()){

            $nom = $film->getNom();
            $annee = $film->getAnnee();
            $score = $film->getScore();

            return(
                "
                    <tr>
                        <td>". $nom ."</td>
                        <td>". ( $annee ? $annee : "" ) ."</td>
                        <td>". ( $score ? $score : "" ) ."</td>
                        <td>Voir</td>
                    </tr>
                "
            );

        }else{ return ""; }
    }
?>

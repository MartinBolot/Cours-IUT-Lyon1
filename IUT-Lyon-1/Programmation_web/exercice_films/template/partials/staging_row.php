<?php
    /**
    *   creates a html table row for a given Acteur object
    *   @param Acteur $acteur the actor to display
    *   @return string the html table row
    */
    function getStagingRow($acteur){
        if($acteur->getNom()){

            $nom = $acteur->getNom();
            $prenom = $acteur->getPrenom();

            return(
                "
                    <tr>
                        <td>". $prenom ."</td>
                        <td>". $nom ."</td>
                    </tr>
                "
            );

        }else{ return ""; }
    }
?>

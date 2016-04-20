<?php
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

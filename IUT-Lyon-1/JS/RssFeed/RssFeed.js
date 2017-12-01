// liste des flux suggérés par défaut
var suggestedFeeds = {
    "a_livre_ouvert" : {
        "title" : "A livre ouvert",
        "url" : "http://radiofrance-podcast.net/podcast09/rss_11591.xml"
    },
    "toto": {
        "title" : "toto"
    },
    "tata" : {

    }
};

// main function
(function(){
    var submit = document.getElementById("feed_request_submit");
    var suggestedFeedsContainer =  document.getElementById("suggested_feeds");
    var suggestedFeed;
    var newButton;

    submit.addEventListener("click",getFeedFromElement);

    // boucle pour générer un bouton pour chaque entrée des flux suggérés
    for(suggestedFeed in suggestedFeeds){
        if(suggestedFeeds[suggestedFeed]){
            if(suggestedFeeds[suggestedFeed]["title"] && suggestedFeeds[suggestedFeed]["url"]){
                newButton = document.createElement("button");
                newButton.setAttribute("class","btn btn-default suggested_feed");
                newButton.setAttribute("id",suggestedFeed);
                newButton.setAttribute("data-url",suggestedFeeds[suggestedFeed]["url"]);
                newButton.innerHTML = suggestedFeeds[suggestedFeed]["title"];
                suggestedFeedsContainer.appendChild(newButton);

                // gestion du click
                newButton.addEventListener("click",getFeedFromElement);
            }
        }
    }
})();

// on récupere un flux à partir d'un élément
function getFeedFromElement(event){
    var target = event.target;
    var className = target.getAttribute("class");

    // on annule l'action par défault au cas ou on est dans un form
    event.preventDefault();

    // si on a cliqué sur l'un des flux suggérés
    if(className){
        if(className.indexOf("suggested_feed") !== -1){
            makeHttpRequest("https://crossorigin.me/" + target.getAttribute("data-url"));
        }
    // si on a chargé son propre lien
    }else{
        if(target.getAttribute("id") === "feed_request_submit"){
            makeHttpRequest("https://crossorigin.me/" + document.getElementById("feed_request_input").value);
        }
    }
}

// utilisation de "https://crossorigin.me/" devant l'url
// pour avoir les droits d'accès au flux
function makeHttpRequest(url){
    var req = new XMLHttpRequest();
    var feedDisplay = document.getElementById("feed_display");

    // on gere les changements d'état de la requête
    req.onreadystatechange = function(e){
        var interval;
        if (req.readyState === 4) {
            if(req.status === 200){
                displayFeed(feedDisplay,req.responseXML);
            }
            else{
                feedDisplay.innerHTML = "Erreur pendant le chargement du flux";
            }
        }else if(req.readyState === 1){
            feedDisplay.innerHTML = "<p>Chargement du podcast ...</p>"
        }
    };

    // on envoie la requete
    req.open('GET',url,true);
    req.send(null);
}

// affichage du flux
function displayFeed(container,feed){
    if(container){
        var format = document.getElementById("feed_request_format").value;

        // on crée les div qui vont afficher les différents éléments du flux
        var titleDiv = document.createElement("div");
        var descriptionDiv = document.createElement("div");
        var imageDiv = document.createElement("div");
        var itemsDiv = document.createElement("div");

        // on se permet de récupérer les infos en dur, elles sont censés être uniques
        var title = feed.getElementsByTagName("title")[0].innerHTML;
        var image = feed.getElementsByTagName("image")[0].getElementsByTagName("url")[0] ? feed.getElementsByTagName("image")[0].getElementsByTagName("url")[0].innerHTML : "";
        var description = feed.getElementsByTagName("description")[0].innerHTML;
        var items = feed.getElementsByTagName("item");

        // on définit la limite
        var limitInput = parseInt(document.getElementById("feed_request_limit").value);
        var limit = items.length > limitInput ? limitInput : items.length;

        // si jamais on est au format simple, créer un lecteur global
        if(parseInt(format) === 0){
            var generalAudioPlayerDiv = document.createElement("div");
            var generalAudioPlayerP = document.createElement("p");
            var generalAudioPlayer = document.createElement("audio");
            generalAudioPlayerDiv.setAttribute("id","global_audio");
            generalAudioPlayerP.setAttribute("id","global_audio_description");
            generalAudioPlayer.setAttribute("id","global_audio_player");
            generalAudioPlayer.controls = true;
        }

        // on donne des classes au conteneurs
        titleDiv.setAttribute("class","feed_title");
        imageDiv.setAttribute("class","feed_image");
        descriptionDiv.setAttribute("class","feed_description");
        itemsDiv.setAttribute("class","feed_items");

        // on récupère les éléments descriptifs du flux
        titleDiv.innerHTML = "<h3>"+title+"</h3>";
        imageDiv.innerHTML = "<img src='"+image+"' alt=''>";
        descriptionDiv.innerHTML = "<p>"+description+"</p>";
        itemsDiv.innerHTML = "<h4> Emissions </h4>";

        // on vide le conteneurs
        container.innerHTML = "";

        // on ajoute le tout à notre conteneur
        container.appendChild(titleDiv);
        container.appendChild(imageDiv);
        container.appendChild(descriptionDiv);
        if(parseInt(format) === 0){
            container.appendChild(generalAudioPlayerDiv);
            generalAudioPlayerDiv.appendChild(generalAudioPlayerP);
            generalAudioPlayerDiv.appendChild(generalAudioPlayer);
            window.addEventListener("hashchange",setAudioSource);
        }
        container.appendChild(itemsDiv);

        if(parseInt(format) === 0){
            for(var i = 0; i < limit; i++){
                displayFeedItem(itemsDiv,items[i],i,false);
            }
        }else if(parseInt(format) === 1){
            for(var i = 0; i < limit; i++){
                displayFeedItem(itemsDiv,items[i],i,true);
            }
        }
    }else{
        throw new Error("A container must be set to display the feed");
    }
}

// affichage d'un item d'un flux
function displayFeedItem(itemContainer,item,index,hasOwnPlayer){
    var containingDiv = document.createElement("div");
    var titleHeader = document.createElement("h5");
    var descriptionP = document.createElement("p");
    var media = document.createElement("audio");
    var audioLink = document.createElement("a");
    var hr = document.createElement("hr");

    var audioUrl = item.getElementsByTagName("enclosure")[0].getAttribute("url");

    titleHeader.innerHTML = item.getElementsByTagName("title")[0].innerHTML;
    descriptionP.innerHTML = item.getElementsByTagName("description")[0].innerHTML;

    if(hasOwnPlayer){
        media.src = audioUrl;
        media.controls = true;
    }else{
        audioLink.setAttribute("href","#" + index);
        audioLink.setAttribute("id","podcast_id_" + index);
        audioLink.setAttribute("data-url",audioUrl);
    }

    containingDiv.setAttribute("class","podcast");
    itemContainer.appendChild(containingDiv);

    // set title or title + link
    titleHeader.setAttribute("id","description_" + index);
    if(hasOwnPlayer){
        containingDiv.appendChild(titleHeader);
    }else{
        audioLink.appendChild(titleHeader);
        containingDiv.appendChild(audioLink);
    }

    containingDiv.appendChild(descriptionP);

    // set media
    if(hasOwnPlayer){
        containingDiv.appendChild(media);
    }

    containingDiv.appendChild(hr);

}

// change podcast on hash changed
function setAudioSource(event){
    // on récupère le hash sans le "#"
    var hash = window.location.hash.slice(1);
    var globalAudioPlayer = document.getElementById("global_audio_player");
    var globalAudioDescription = document.getElementById("global_audio_description");
    if(parseInt(hash) >= 0){
        var element = document.getElementById("podcast_id_" + hash);
        var description = document.getElementById("description_" + hash);
        if(element){
            globalAudioPlayer.src = element.getAttribute("data-url");
        }
        if(description){
            globalAudioDescription.innerHTML = description.innerHTML;
        }
    }
}

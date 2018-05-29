# Atelier1
## Questions
### 1) Qu’est-ce que le pattern MVC ? Quels avantages présente-t-il ?
Le pattern MVC repose sur la séparation entre trois entités : le modèle, la vue et le contrôleur.
Le principe est de séparer son code en fonction de responsabilités :
- le modèle contient le code liées aux données,
- la vue contient le code en charge de l'affichage
- le ou les contrôleurs ont pour rôle de faire le lien entre le modèle et la vue

### 2) Qu’est-ce que le Web dynamique ? pourquoi est-il intéressant ?
Le Web Dynamique est un type d'application client/serveur qui s'adapte en fonction du client.

### 3) Comment sont récupérés les fichiers par le Web Browser en Web statique ? Quels sont les avantages d’utiliser du Web Statique avec des services REST ?
En Web statique, les fichiers sont récupérés directement au format HTML par le Web Browser.
Si on utilise le Web Statique avec des Web Services REST :
- On peut (doit) se passer d'un système de session, on est indépendant de l'utilisateur
- Nos services sont réutilisables facilement
- Pas de JSP à compiler, plus rapide

### 4) Comment fonctionne l’AJAX ?
AJAX est une API JavaScript qui fonctionne dans le navigateur et permet d'émettre et recevoir des requêtes HTTP sans recharger la page Web.

### 5) Qu’est-ce que JEE ?
Une spécification de Java à implémenter qui offre des fonctionnalités étendues par rapport à Java SE.
JEE définit un ensemble d'APIs (interfaces de programmation) permettant de gérer notamment des serveurs web, des accès bases de données et mappings relationnel-objet (BDD <-> Classes).

### 6) Comment fonctionne un serveur JEE ?
**Source poly :**
1. <span style="color:aqua">Client</span> -> <span style="color:green">Serveur HTTP</span>
2. <span style="color:green">Serveur HTTP</span> -> <span style="color:pink">JSP</span>
3. <span style="color:pink">JSP</span> -> <span style="color:red">Moteur de Servlet</span>
4. <span style="color:red">Moteur de Servlet</span> <-> <span style="color:violet">Lib JEE</span>
5. <span style="color:red">Moteur de Servlet</span> -> <span style="color:green">Serveur HTTP</span>
6. <span style="color:green">Serveur HTTP</span> -> <span style="color:aqua">Client</span>

### 7) Qu’est-ce qu’un Web Container en JEE ?
**Source poly :**

Il s'agit d'un logiciel qui va gérer l'organisation des servlets :
- Instanciation des classes nécessaires à l’application
- Compilation à la volée des pages JSP

### 8) Que représente les Servlet dans JEE ?
Une unité de prise en charge de message HTTP (retourne du code - html, texte, xml, ...)

### 9) Qu’est-ce que JSP ?
Il s'agit d'une norme de codage java qui permet de génére de manière dynamique des pages HTML pour le navigateur

### 10) Quel est le cycle de vie d’un JSP ?
**Source poly :**

Les JSP sont basées sur la technologie des Servlets
- Le cycle de vie d'une JSP est le même que celui d'une Servlet

La différence : les fichiers JSP sont compilés sous forme de Servlets
- Au premier appel
- Recompilés à chaque modification du code source


1. Appel JSP
2. Parsing JSP
3. Transformation JSP -> Servlet
4. Comilation du Servlet
5. Instanciation du Servlet

### 11) Qu’est-ce que les expressions EL ?
Variables en mémoire partagé (espace commun => SessionScope) par les différentes classes java (et JSP) pour générer dynamiquement du contenu

### 12) Que permettent de faire les expressions EL ?
Avoir un contenu servi dynamiquement, accéder à des objets Java pour générer de l'information

### 13) Qu’apporte JSTL aux JSP ?
JavaServer Pages Standard Tag Library (extension pour JSP) apporte des opérations courantes :
- boucles
- condition
- gestion de la localisation (langues)

### 14) Qu’est-ce qu’un Javabean ?
Une classe qui va pouvoir être partagée en mémoire vers une JSP par exemple

### 15) Quels sont ces propriétés/contraintes ?
- Elle doit avoir un constructeur vide
- Les getters doivent êter normalisés pour utiliser la notation "object.attribute" (pas d'accès direct)

**Source poly  :**
- Constructeur sans paramètre
- Doit être sérialisable (implements Serializable)
- Propriétés normalisées: attribut=nom, méthode d’accès getNom(), setNom(String s)

### 16) Comment utilise-t-on les Javabean avec les JSP ?
Grâce à la variable *SessionScope* (portée de la session, espace mémoire partagée) dans les JSP

### 17) Que permet de faire JDBC ?
Le lien (connexion) avec une base de données
Permet d’invoquer des requêtes SQL depuis un programme
Java

### 18) Quelle est la différence entre Statement et PrepareStatement ?
*Statement* représente une requête statique. *PrepareStatement* représente une requête préparée. Une requête préparée prend en paramètre des variables.
Cela permet de construire une requête dynamiquement en sachant quels types de données composeront la requête. C'est une défense essentielle contre l'injection SQL.

# Atelier 2
## Questions
### 1) Qu’est ce que des Services Web Full Rest ? Quelles sont les contraintes imposées par ce type de service ?
Il s'agit de services Web qui respecent intégralement les principes REST. La principale contraite est la partie StateLess, soit sans état.

### 2) Qu’est ce qu’un gestionnaire de dépendance ? Maven est-il le seul ? Quel est l’avantage d’utiliser un gestionnaire de dépendances ? Quelles sont les grandes étapes de fonctionnement de Maven ?
Un gestionnaire de dépendance permet de déclarer, gérer et partager les dépendances logicielles d'un projet.
Maven n'est pas le seul outil, Gradle est un autre exemple.
Avantages d'un gestion gestionnaire de dépendances :
- Pouvoir découpler le code source de l'application du code tiers.
- Faciliter le processus de mise à jour et de récupération dans le cadre de l'utilisation d'une bibliothèque externe par exemple.
- Amélorer la capacité du code à être sous gestionnaire de version.

Etapes de fonctionnement de Maven :
1. Déclaration des dépendance dans un fichier pom.xml
2. Installation de Maven
3. Installation du projet chez chaque développeur


### 3) Qu’est ce qu’une application classique Entreprise Java Application ? Donner un exemple d’usage avec web service, JSP, JavaBean, EJB et JMS.

### 4) Qu’est ce que Spring ? qu’apporte Spring boot vis-à-vis de Spring ?
Spring est un framework qui facilite les développements autour de JEE.
Spring Boot apporte des configurations par défaut ainsi que des utilitaires pour facilier la mise en oeuvre d'une application Spring.

### 5) Qu’est ce que Spring Boot ? Quels sont les points communs/différences entre JEE et Spring Boot ?
Spring Boot est un framework de développement pour faciliter la création d'application JEE avec Spring.
JEE est une spécification alors que Spring Boot est un ensemble d'outils. Les deux permettent de faciliter grandement la création d'une application Java orientée services.

### 6) Qu’est ce qu’une annotation ? Quels apports présentent les Annotations ?
Une annotation est une métadonnée liée à une méthode (la plupart du temps) ou a tout autre entité java (classe, attributs, ...)
Elles permettent à la fois d'informer l'utilisateur, mais aussi de donner des directives à un outil qui parse le code

### 7) Comment fait-on pour créer un Web Service Rest avec Spring Boot ?
**Source poly  :**

On crée un contrôleur dans lequel on place des méthodes annotées pour indiquer :
- *@Path* : Une URI Relative indiquant quelle Classe, Méthode Java sera déclenchée
- *@GET / @POST / @PUT @DELETE / @ HEAD* : Méthode http sur laquelle la méthode java sera déclenchée
- *@PathParam* : Elément de l'URI pouvant être exlpoité par une méthode java
- *@QueryParam* : Type de paramètre pouvant être extrait de la requête
- *@Consumes* : Définit le MIME media type pouvant être consomé par la méthode java

### 8) Qu’est ce qu’un container de Servlet ? Comment fonctionne un container de Servlet ?
Un container de servlet est un logiciel qui intercepte les requêtes HTTP et les redirige vers les servlets java. Apache Tomcat est un exemple de container de Servlet.
Le moteur de Servlet va recevoir une requête HTTP transférée depuis Apache par exemple (serveur) puis va la transférer vers le service requis pour accéder à la ressource demandée puis la renvoyer en retour.

Selon Wikipédia :
L'architecture du logiciel se compose ainsi :
- Un serveur (server), soit tomcat en cours d'exécution
  - Des services, intermédiaires collectant différents canaux de transmissions vers un traitement
    - Un moteur (engine), qui pour chaque service traite les requêtes des collecteurs et renvoie les réponses
  - Des hôtes (host), qui relient une adresse réseau avec le serveur
  - Des connecteurs (connector), qui interprètent un canal et protocole de communication réseau à disposition des clients. Le connecteur HTTP est le plus typique
  - Des contextes (context), qui sont les applications web


### 9) Expliquer la philosophie « Convention over Configuration » de Spring boot ?
Spring Boot part du principe qu'il vaut mieux générer automatiquement les configurations pour qu'une application aie un fonctionnement standard de base.
C'est la "Convention", on prend ce que l'utilisateur va probablement vouloir.
On laisse alors l'utilisateur configurer les détails qui l'intéressent. C'est la "Configuration", que Sprint Boot laisse à la discrétion de l'utilisateur.

### 10) Expliquer ce qu’il se passe lors de l’exécution «SpringApplication.run(App.class,args) »
**Source docs.spring.io**

https://docs.spring.io/spring-boot/docs/current/api/org/springframework/boot/SpringApplication.html

Classe qui peut être utilisée pour lancer une application Spring depuis une méthode "main" Java. Par défaut la classe va exécuter les étapes suivantes pour lancer l'application :
- Créer un *ApplicationContext* adéquat (en fonction de la classe passée en argument)
- Enregister une *CommandLinePropertySource* pour exposer les arguments passés en ligne de commande en tant que propriétés Spring
- Recharger le contexte de l'application, chargeant ainsi tous les *Beans* singleton
- Déclancher tous les *Beans* de type *CommandLineRunner*

### 11) Qu’est ce qu’un DAO ? En quoi est-ce intéressant d’utiliser ce pattern ? Qu’est ce qu’un Singleton ?
Un DAO est un objet servant pour l'accès au données. Il est intéressant d'utiliser ce pattern pour gérer niveau code les données en base.
Un Singleton est une classe qui ne peut instancier qu'un seul objet.

### 12) Que permet de réaliser les Entity dans Spring boot ? Est-ce spécifique à SpringBoot ?
Les Entity permettent de lier des classes à des tables en base de données.
Ce n'est pas spécifique à Spring Boot, plusieurs autres framework proposent un comportement simlaire en Java et autre langages.
C'est une problématique récurente dans la conception logicielle.

### 13) Combien d’instances avez-vous crées lors de l’usage de «Service » en Spring boot? Pourquoi ?
Une seul instance, car on ne souhaite pas accéder aux données de manière concurente.

### 14) Que fournit le CRUD Repository de Spring boot ? Que sont les CRUD ?
Le répository fournit les fonctions de création, lecture, mise à jour et suppression des données.
Les CRUD sont les opérations en base de données qu'on pourrait rapprocher de la DML en SQL (Data Manipulation Language : SELECT, UPDATE, INSERT, DELETE)

### 15) Qui réalise l’implémentation de la méthode findByProperty lors de la création d’un repository en Spring Boot ?
On crée un repository qui étend le CrudRepository, c'est donc le CrudRepository qui se charge de l'implémentation de cette méthode.

### 15) Comment gère -t-on les relations One To One, One to Many et Many to Many avec JPA ?
On utilise les annotations

### 16) Qu’est ce qu’une Architecture SOA ? Qu’est ce qu’une architecture Micro Service ? Il y a-t-il d’autres architectures existantes ? Quels sont leurs avantages/inconvénients ?

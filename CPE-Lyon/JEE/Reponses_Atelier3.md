# Atelier 3
## Questions
### 1) Quelle est la différence entre un test fonctionnel et un test unitaire ? A quoi sert la couverture de code ?
Dans un test fonctionnel on vérifie que l'application fonctionne comme elle devrait.
Dans un test unitaire, on vérifie que chaque méthode créée renvoie la valeur attendue en avec les paramètres choisis.
La couverture de code sert à vérifier que les tests unitaires couvrent bien toutes les méthodes codées.

### 2) Qu’est ce qu’un test de non régression ? à quoi sert-t-il ?
Un test de régression compare les fonctionnalités actuelles à celles de la dernière version stable connue.
Un test de non-régression permet de vérifier que l'application reste stable après l'ajout de nouvelles fonctionnalités.

### 3) Expliquer le principe de développement « test driven » ?
On code en "test-driven" quand on écrit les test avant de développer les classes.
On considère qu'en codant puis en testant son code, un développeur aura naturellement tendance à tester les cas qu'il connait, qui fonctionnent.
En commançant par écrire les tests, on a plus de chances (ne connaissant pas le code) de soulever des problèmes indatendus à corriger et donc de mieux couvrir son code.

### 4) Quels intérêts présentent les micros services comparés aux architecture SOA ?
Services autonomes, indépendants du langage utilisé, de la plateforme. Meilleure optimisation des ressources lors d'une montée en charges par exemple.

### 5) Quelles sont les différences entre les micros services et le SOA ? Quel intérêt présente l’usage de docker et des micro-services ?
Dans le SOA on a une application avec plusieurs services sur le même serveur. Dans le cas des micro-services chaque services utilise un serveur et une base de données séparés.
Docker permet de compartimenter les micro-services et de les tester avec un environnement virtuel indépendant à chaque fois.

### 6)Qu’est-ce que docker ? En quoi diffère-t-il des méthodes de virtualisation dites classiques (vmware, virtualbox) ?
Docker est un outil de virtualisation.
Il diffère de VMware par exemple, dans le sens où il n'émule pas un OS mais sa place à plus haut niveau pour isoler un environnement sur n'importe quel système Linux.

### 7) Quelle organisation en équipe permet la mise en œuvre de micro services ?
On pourra imaginer pour la création de micro services un répartition où chaque membre de l'équipe réalise son propre micro-service.
Il faudra par la suite gérer la communication entre micro-services, mais cela permet de répartir les fonctionnalités entre les membres d'une équipe.

### 8) Que permet de faire l’outil Sonar ?
Il permet d'analyser le code et les tests pour connaitre les parties du code qui ne sont pas testées.

### 9) Qu’est ce que l’intégration continue ? Quels avantages/contraintes présentent cette organisation ?
Intégration continue = intégrer du code dans l'environnement au fur et à mesure du codage.
Avantage = beaucoup d'automatisation
contraintes = organisation et risque de crash de l'application

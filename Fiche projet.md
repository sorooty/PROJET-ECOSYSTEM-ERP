1 
 
 
 
 
 
 Mise en place d’un ERP de gestion scolaire en milieu rural 
 Extension : Digitalisation du système de pointage des élèves de l’ISJA 
 
Etablissement : ISJA 
Etablissement en cours de projet : Le bon samaritain 
 
 
 
 
                                   
Concepteur du projet 
Lazare Ndiaye 
 
2 
 
                                    Contexte 
Les écoles adoptent de plus en plus la technologie pour améliorer 
leurs programmes éducatifs et leur efficacité administrative, les 
systèmes ERP apparaissent aussi comme une solution efficace. Ces 
systèmes offrent une plateforme unifiée qui simplifie les opérations 
complexes d’un établissement scolaire, en facilitant leur gestion et en 
améliorant la productivité globale.  
Au niveau des zones rurales, l’utilisation des ERP étant complexe du 
fait des limites sur le plan financier, la mise en place d’une application 
accessible ou adaptée aux réalités s’impose. 
 
                                Problématique 
   Peut-on mettre en place un ERP adapté aux  écoles rurales ? 
 
                                 Objectifs - Concevoir un ERP de gestion d’une école française fraichement 
crée au niveau du Cap skring - Digitaliser le système de pointage (entrée et sortie) des élèves de 
l’ISJA Dakar. 
                            Exigences 
                  Exigence règlementaire - N’utilisez pas l’interface d’une ERP préexistante 
                             Exigences techniques - Valider les livrables attendus - Modéliser et coder en C++ une application graphique, 
interrogeant une base de données, en respectant les standards de 
conception Poo. 
                   Exigences normatives - PDCA 
Eléments d’entrée: Echanges par courriel 
3 
4 
 
  
 
 
 
 
 
 
 
Postulat 1 : Description de l’école du bon samaritain 
Actuellement, l’école compte 8 salles de classes réparties à deux niveaux 
Seconde A (31 élèves) 
Seconde  B (29 élèves) 
Sixième A : 39 élèves 
Sixième B : 38 élèves  
Concernant la gestion administrative, nous avons quatre bureaux :  - Un pour le professeur - Un pour le CPE - Un pour la comptabilité - Un pour les informaticiens - Un attribué au service de nettoyage  
Nous avons construit deux box pour les surveillants. 
Ultérieurement, nous mettrons en place un laboratoire pour les travaux 
pratiques.  
Le processus marketing et communication est externalisé. 
5 
Boucle PDCA1 : Faire l’approche par processus 
Livrables attendus 
Liv 1 : Faire la cartographie des processus de cet établissement 
Liv 2 : Formulaire questionnaires ayant comme cible Monsieur Lazare Ndiaye, 
proviseur de l’école du bon samaritain 
Liv 3 : Analyse des besoins, suite à l’entretien avec le proviseur de l’EBS 
Boucle PDCA 2 : Valider un modèle et faire la gamme de 
fabrication. 
Livrables attendus 
Liv 4 : Formulaire questionnaires avec comme cible Monsieur Niasse, CPE 
(modéliser à partir du fonctionnement de pronote)  
Liv 5 : Gamme de fabrication du projet en tenant compte des informations 
suivantes : 
Environnement de travail 
 IDE : Visual Studio 
 AGL : Visual Paradigm (ou assimilé) + Analyse 
SI (ou assimilé) 
 Langage : C++ 
 Système de gestion de bases de données 
relationnelles : SQL Server (conseillé), mySql, 
Oracle,..... 
Intégration continue : Git HUB 
Forme normale : 3ème forme normale 
Architecture logicielle : Ihm – Services – Composants 
 Modélisation des données 
 Dictionnaires des données 
 MCD 
 MLD 
Modélisation de l’application 
Diagramme de classes 
   Diagramme de cas d’utilisation Diagramme de 
séquences 
 Créer un personnel 
6 
  
   Modifier un personnel 
 Supprimer un personnel 
 Afficher un personnel 
Diagramme d’activité (Gestion d’un personnel) 
  Utilisation des pointeurs de fonctions pour la gestion des 
simulations 
 Gestion de la mémoire pour les objets déréférencés 
Utilisation de classes de mappages pour fournir les requêtes 
SQL 
Tests Unitaires sur la séquence (Créer un personnel) 
7 
Postulat 3 : Cahier de charge 
Gestion élève   - EDT : matières, nombre d’heures, professeur - Notes - Salle de classe - Heures d’entrée et de sortie de l’école 
Gestion des classes - Numéro de classe - Heures de cours - Nombre de place - Disponibilité  
Gestion de la vie scolaire - Absences  - Retard - Retenue 
Gestion des professeurs - Noms de professeur - Cahier de texte - Matières  
Gestion des parents - Validation du paiement - Réunion 
8 
Boucle PDCA 3 : Faire le lean management projet 
Liv 6  Définir le cycle de vie du projet 
Liv7   Etablir les différentes phases du projet avec gant Project 
Liv 8  Faire l’analyse fonctionnelle des besoins 
Postulat  4 
Eléments de sortie 
Concevoir un ERP de gestion de l’école le bon samaratain 
qui prend en charge les classes, les élèves, les professeurs et 
les parents. 
9 
  
Eléments d’entréé 
Monsieur Olivier Georges, proviseur de l’ISJA vous sollicite afin de mettre en 
place un système de digitalisation du  système de pointage des élèves. Ce 
dispositif renforcera les acquis  du carnet de liaison des élèves.  
Le référent de ce projet est l’informaticien de l’ISJA, Jean Marcel Tine. 
Boucle PDCA 4 : Optimiser le dispositif de pointage des élèves 
Livrables attendus 
Liv 8 : Rapport d’entretien avec le Proviseur de l’ISJA 
Liv 9 : Rapport d’entretien avec M. Jean Marcel Tine.  
Liv 10 : Proposition d’un cahier de charges  
Eléments de sortie 
ERP de gestion des entrées et sorties des élèves de l’ISJA, 
en phase de test. 
10 
11 
 
   Evaluation individuelle                                   Evaluation collective 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
# Documentation Technique - ERP de Gestion Scolaire

## 📑 Table des matières

1. [Introduction](#introduction)
2. [Architecture du Projet](#architecture-du-projet)
3. [Base de données](#base-de-données)
4. [Conception Orientée Objet](#conception-orientée-objet)
5. [Implémentation](#implémentation)
6. [Interface Utilisateur](#interface-utilisateur)
7. [Gestion des Utilisateurs et des Parents](#gestion-des-utilisateurs-et-des-parents)
8. [Gestion des Factures et Paiements](#gestion-des-factures-et-paiements)

## Introduction

Le projet consiste en un ERP (Enterprise Resource Planning) de gestion scolaire développé pour répondre aux besoins spécifiques des écoles en milieu rural, avec une extension pour la digitalisation du système de pointage des élèves.

### Objectifs principaux

- Gestion complète des élèves, classes, professeurs et matières
- Système de pointage numérique
- Gestion des notes et évaluations
- Suivi de la vie scolaire

## Architecture du Projet

### Structure des dossiers

```
project/
├── src/
│   ├── main.cpp
│   ├── models/           # Classes métier
│   │   ├── Utilisateur.cpp
│   │   ├── Eleve.cpp
│   │   ├── Classe.cpp
│   │   ├── Matiere.cpp
│   │   ├── Note.cpp
│   │   ├── Absence.cpp
│   │   ├── Retard.cpp
│   │   ├── Communication.cpp
│   │   └── Pointage.cpp
│   ├── dao/             # Couche d'accès aux données
│   │   ├── UtilisateurDAO.cpp
│   │   ├── ClasseDAO.cpp
│   │   ├── MatiereDAO.cpp
│   │   ├── NoteDAO.cpp
│   │   ├── AbsenceDAO.cpp
│   │   ├── RetardDAO.cpp
│   │   ├── CommunicationDAO.cpp
│   │   └── PointageDAO.cpp
│   ├── services/        # Logique métier
│   │   ├── UserService.cpp
│   │   ├── ClassService.cpp
│   │   └── NotificationService.cpp
│   └── database/        # Gestion de la base de données
│       └── databaseConnection.cpp
├── include/
│   ├── models/          # Headers des classes métier
│   ├── dao/             # Headers DAO
│   ├── services/        # Headers des services
│   └── database/        # Headers de la base de données
│       └── databaseConnection.hpp
└── docs/                # Documentation

```

**Explication :** 

- **src/** : Contient le code source principal de l'application.
  - **models/** : Contient les classes représentant les entités du système.
  - **dao/** : Contient les classes responsables de l'accès aux données.
  - **services/** : Contient la logique métier, séparant les opérations complexes des DAO.
  - **database/** : Contient la gestion de la connexion à la base de données.

- **include/** : Contient les fichiers d'en-tête pour les différentes parties du code, organisés de manière similaire à `src/`.

- **docs/** : Contient la documentation du projet.

 Avantages Principaux

1. **Organisation Claire**
    - Chaque fichier a un rôle précis
    - Facile de trouver où modifier le code
2. **Maintenance Facilitée**
    - Modification d'une partie sans toucher aux autres
    - Tests plus simples
3. **Sécurité Améliorée**
    - Validation des données à plusieurs niveaux
    - Accès contrôlé à la base de données


## Comment ça fonctionne ?

### Exemple d'une opération typique :

```
1. L'utilisateur veut créer un compte
   ↓
2. Le modèle Utilisateur vérifie les données
   ↓
3. UtilisateurDAO prépare la requête SQL
   ↓
4. DatabaseConnection exécute la requête
   ↓
5. Le résultat remonte la chaîne

```

## En Résumé

- Les **Models** définissent la structure des données
- Les **DAO** gèrent l'accès à la base de données
- La **DatabaseConnection** centralise les opérations MySQL
- Chaque partie a un rôle distinct et communique avec les autres de manière organisée

C'est comme une usine où chaque service a son rôle précis et collabore avec les autres de manière ordonnée.

Cette structure est conçue pour séparer clairement les différentes responsabilités du code, facilitant ainsi la maintenance et l'évolution du projet. 


### 1. Modèles

Les modèles représentent les entités principales du système. Chaque modèle est défini par une classe C++ avec des attributs et des méthodes spécifiques. Le projet est organisé en plusieurs modules, chacun responsable d'une partie spécifique du système. Voici un aperçu des principaux composants :

- **Utilisateur** : Représente un utilisateur du système avec des attributs comme `nom`, `prenom`, `login`, `type`, etc. Les méthodes incluent des getters et setters, ainsi que des méthodes de validation.

  **Commentaire :** La classe `Utilisateur` est essentielle car elle gère les informations de base de chaque utilisateur du système. Les méthodes de validation assurent que les données utilisateur sont correctes avant d'être enregistrées.

- **Classe** : Représente une classe scolaire avec des attributs comme `nom`, `niveau`, `anneeScolaire`, etc. Les méthodes permettent de gérer les élèves inscrits et de vérifier la capacité de la classe.

  **Commentaire :** La gestion des classes est cruciale pour organiser les élèves et les cours. Les méthodes associées aident à maintenir l'intégrité des données concernant les inscriptions.

- **Matiere** : Représente une matière enseignée avec des attributs comme `nom`, `description`, `coefficient`, etc. Les méthodes incluent des getters, setters, et une méthode de validation.

  **Commentaire :** La classe `Matiere` permet de gérer les informations sur les matières enseignées, ce qui est fondamental pour le suivi académique.

- **Absence** : Représente une absence d'un élève avec des attributs comme `eleveId`, `dateDebut`, `dateFin`, etc. Les méthodes permettent de vérifier la validité de l'absence.

  **Commentaire :** La gestion des absences est importante pour le suivi de la présence des élèves et pour la communication avec les parents.

- **Retard** : Représente un retard d'un élève avec des attributs comme `eleveId`, `dateRetard`, `heureArrivee`, etc. Les méthodes incluent la validation du retard.

  **Commentaire :** Le suivi des retards aide à identifier les problèmes de ponctualité et à prendre des mesures correctives.

- **Communication** : Représente une communication entre utilisateurs avec des attributs comme `type`, `titre`, `contenu`, etc. Les méthodes permettent de gérer les destinataires et de valider la communication.

  **Commentaire :** La classe `Communication` facilite l'échange d'informations entre les utilisateurs, ce qui est essentiel pour la coordination et la gestion des événements scolaires.

- **Note** : Représente une note attribuée à un élève pour une matière spécifique, avec des attributs comme `note`, `coefficient`, `typeEvaluation`, etc. Les méthodes incluent des getters, setters, et une méthode de validation.

  **Commentaire :** La classe `Note` est essentielle pour le suivi académique des élèves, permettant de calculer les moyennes et d'évaluer les performances.

- **Reunion** : Représente une réunion scolaire avec des attributs comme `titre`, `dateReunion`, `heureDebut`, `typeReunion`, etc. Les méthodes permettent de gérer les participants et de valider les détails de la réunion.

  **Commentaire :** La gestion des réunions est cruciale pour la coordination entre les enseignants, les parents et l'administration.

- **Pointage** : Représente le pointage d'un élève avec des attributs comme `datePointage`, `heureArrivee`, `heureDepart`, etc. Les méthodes incluent la validation du pointage et la gestion des retards.

  **Commentaire :** Le système de pointage aide à suivre la présence des élèves et à identifier les retards.

- **Enseignement** : Représente l'enseignement d'une matière par un professeur à une classe, avec des attributs comme `idProfesseur`, `idMatiere`, `idClasse`, etc. Les méthodes permettent de gérer l'association entre les professeurs, les matières et les classes.

  **Commentaire :** La classe `Enseignement` est essentielle pour organiser les cours et les responsabilités des enseignants.

### 2. DAO (Data Access Object)

Les DAO sont responsables de l'interaction avec la base de données. Chaque DAO fournit des méthodes pour effectuer des opérations CRUD (Create, Read, Update, Delete) sur les entités correspondantes.

- **UtilisateurDAO** : Gère les opérations de base de données pour les utilisateurs, comme l'ajout, la modification, la suppression, et la recherche par nom.

  **Commentaire :** Le DAO pour les utilisateurs permet de centraliser et d'abstraire l'accès aux données, ce qui simplifie les modifications futures de la base de données.

- **ClasseDAO** : Gère les opérations de base de données pour les classes, y compris l'inscription et la désinscription des élèves.

  **Commentaire :** Ce DAO assure que les opérations sur les classes sont effectuées de manière cohérente et sécurisée.

- **MatiereDAO** : Gère les opérations de base de données pour les matières, y compris l'ajout et la modification des matières.

  **Commentaire :** La gestion des matières via un DAO permet de maintenir une base de données propre et bien structurée.

- **AbsenceDAO** : Gère les opérations de base de données pour les absences, y compris l'ajout et la justification des absences.

  **Commentaire :** Ce DAO est crucial pour le suivi des absences et pour générer des rapports précis.

- **RetardDAO** : Gère les opérations de base de données pour les retards, y compris l'ajout et la justification des retards.

  **Commentaire :** La gestion des retards via un DAO permet de suivre efficacement les problèmes de ponctualité.

- **CommunicationDAO** : Gère les opérations de base de données pour les communications, y compris l'ajout et la gestion des destinataires.

  **Commentaire :** Ce DAO facilite la gestion des communications internes, ce qui est essentiel pour une bonne coordination.

- **NoteDAO** : Gère les opérations de base de données pour les notes, y compris l'ajout, la modification et la suppression des notes.

  **Commentaire :** Ce DAO est crucial pour le suivi des performances académiques et la génération de bulletins.

- **ReunionDAO** : Gère les opérations de base de données pour les réunions, y compris l'ajout et la gestion des participants.

  **Commentaire :** La gestion des réunions via un DAO permet de planifier efficacement les événements scolaires.

- **PointageDAO** : Gère les opérations de base de données pour le pointage, y compris l'enregistrement des arrivées et des départs.

  **Commentaire :** Ce DAO facilite le suivi de la présence des élèves et la gestion des retards.

- **EnseignementDAO** : Gère les opérations de base de données pour les enseignements, y compris l'association des professeurs aux matières et aux classes.

  **Commentaire :** La gestion des enseignements via un DAO assure une organisation claire des cours et des responsabilités des enseignants.

### 3. Main

Le fichier `main.cpp` contient le point d'entrée du programme. Il gère l'affichage des menus et la navigation entre les différentes fonctionnalités du système.

**Commentaire :** Le fichier `main.cpp` est le cœur de l'application, orchestrant les interactions entre les différentes parties du système.

### Patterns de conception utilisés

1. **Singleton** : Pour la connexion à la base de données

   **Commentaire :** Le pattern Singleton garantit qu'il n'y a qu'une seule instance de connexion à la base de données, ce qui évite les conflits et optimise les ressources.

2. **DAO (Data Access Object)** : Pour l'abstraction de la couche données

   **Commentaire :** Le pattern DAO permet de séparer la logique de l'application de l'accès aux données, facilitant ainsi la maintenance et l'évolution du code.

3. **MVC** : Séparation des responsabilités

   **Commentaire :** Le pattern MVC (Modèle-Vue-Contrôleur) est utilisé pour structurer l'application de manière à séparer les données, la logique de l'application et l'interface utilisateur, ce qui améliore la modularité et la testabilité du code.

## Modèles - Version Tableau

| Modèle       | Attributs Principaux                                                                 | Méthodes Principales                                  | Commentaire                                                                                   |
|--------------|--------------------------------------------------------------------------------------|-------------------------------------------------------|-----------------------------------------------------------------------------------------------|
| **Utilisateur** | `id`, `nom`, `prenom`, `login`, `type`                                              | `verifierDroits(action)`, `estValide()`               | Gère les informations de base de chaque utilisateur.                                          |
| **Eleve**       | `idEleve`, `classeId`                                                               | `getters/setters`, `inscrireClasse(classeId)`         | Représente un élève et gère son inscription en classe.                                        |
| **Professeur**  | `idProfesseur`, `matieres`                                                          | `getters/setters`, `ajouterMatiere(matiereId)`        | Gère les matières enseignées par un professeur.                                               |
| **Admin**       | `idAdmin`                                                                           | `gererUtilisateurs()`, `gererSysteme()`               | Gère les utilisateurs et le système.                                                          |
| **Parent**      | `idParent`, `enfantsIds`                                                            | `getters/setters`, `ajouterEnfant(eleveId)`           | Gère les informations des parents et leur association avec les élèves.                        |
| **Classe**      | `id`, `nom`, `niveau`                                                               | `ajouterEleve(eleveId)`, `estValide()`                | Représente une classe scolaire et gère les élèves inscrits.                                   |
| **Pointage**    | `id`, `eleveId`, `datePointage`, `heureArrivee`, `heureDepart`, `statut`, `commentaire`, `validateurId` | `estValide()`, `estRetard()`                          | Gère le pointage des élèves et identifie les retards.                                         |
| **Absence**     | `id`, `eleveId`, `dateDebut`, `dateFin`, `justifie`, `motif`                        | `estValide()`                                         | Gère les absences des élèves et leur justification.                                           |
| **Retard**      | `id`, `eleveId`, `dateRetard`, `heureArrivee`, `dureeMinutes`, `justifie`, `motif`, `validateurId` | `estValide()`                                         | Gère les retards des élèves et leur justification.                                            |
| **Retenue**     | `id`, `eleveId`, `dateRetenue`, `heureDebut`, `heureFin`, `motif`, `professeurId`, `statut`, `commentaire` | `estValide()`                                         | Gère les retenues des élèves et leur organisation.                                            |
| **Communication** | `id`, `typeCommunication`, `titre`, `contenu`, `dateEnvoi`, `expediteurId`, `importance`, `pieceJointe`, `destinatairesIds` | `ajouterDestinataire(int)`, `retirerDestinataire(int)`, `estValide()` | Facilite l'échange d'informations entre les utilisateurs.                                     |
| **Facture**     | `id`, `eleveId`, `montantTotal`, `dateEmission`, `dateEcheance`, `statut`          | `ajouterPaiement(Paiement paiement)`, `estValide()`   | Gère les factures des élèves et leur statut de paiement.                                      |
| **Paiement**    | `id`, `factureId`, `montant`, `datePaiement`, `methodePaiement`                    | `estValide()`                                         | Gère les paiements effectués pour les factures.                                               |



## Base de données

### Configuration MySQL

- `Host:` localhost
- `Port:` 3306
- `Nom de la Base de données:` “***test_ecolsystem”***
- `Utilisateur`: root

### Classes principales et leurs tables

### Table `utilisateurs`

```sql
CREATE TABLE utilisateurs (
    id_utilisateur INT PRIMARY KEY AUTO_INCREMENT,
    nom VARCHAR(50) NOT NULL,
    prenom VARCHAR(50) NOT NULL,
    login VARCHAR(50) UNIQUE NOT NULL,
    type_utilisateur ENUM('eleve', 'professeur', 'admin') NOT NULL,
    actif BOOLEAN DEFAULT TRUE
);

```

### Table `classes`

```sql
CREATE TABLE classes (
    id_classe INT PRIMARY KEY AUTO_INCREMENT,
    nom_classe VARCHAR(50) NOT NULL,
    niveau VARCHAR(20) NOT NULL,
    annee_scolaire VARCHAR(9) NOT NULL,
    professeur_principal INT,
    FOREIGN KEY (professeur_principal) REFERENCES utilisateurs(id_utilisateur)
);

```

### Table `matieres`

```sql
CREATE TABLE matieres (
    id_matiere INT PRIMARY KEY AUTO_INCREMENT,
    nom VARCHAR(50) NOT NULL,
    description TEXT,
    coefficient INT DEFAULT 1,
    volume_horaire INT DEFAULT 0
);

```

### Table `enseignements`

```sql
CREATE TABLE enseignements (
    id_enseignement INT PRIMARY KEY AUTO_INCREMENT,
    id_professeur INT,
    id_matiere INT,
    id_classe INT,
    FOREIGN KEY (id_professeur) REFERENCES utilisateurs(id_utilisateur),
    FOREIGN KEY (id_matiere) REFERENCES matieres(id_matiere),
    FOREIGN KEY (id_classe) REFERENCES classes(id_classe)
);

```

### Table `inscriptions`

```sql
CREATE TABLE inscriptions (
    id_inscription INT PRIMARY KEY AUTO_INCREMENT,
    id_eleve INT,
    id_classe INT,
    date_inscription DATE DEFAULT '2024-12-01',
    statut ENUM('actif', 'inactif') DEFAULT 'actif',
    FOREIGN KEY (id_eleve) REFERENCES utilisateurs(id_utilisateur),
    FOREIGN KEY (id_classe) REFERENCES classes(id_classe)
);

```

### Table `notes`

```sql
CREATE TABLE notes (
    id_note INT PRIMARY KEY AUTO_INCREMENT,
    id_eleve INT,
    id_matiere INT,
    id_professeur INT,
    note DECIMAL(4,2),
    coefficient INT DEFAULT 1,
    type_evaluation VARCHAR(50),
    date_evaluation DATE,
    commentaire TEXT,
    FOREIGN KEY (id_eleve) REFERENCES utilisateurs(id_utilisateur),
    FOREIGN KEY (id_matiere) REFERENCES matieres(id_matiere),
    FOREIGN KEY (id_professeur) REFERENCES utilisateurs(id_utilisateur)
);

```

### Table `absences`

```sql
CREATE TABLE absences (
    id_absence INT PRIMARY KEY AUTO_INCREMENT,
    id_eleve INT,
    date_debut DATETIME,
    date_fin DATETIME,
    justifie BOOLEAN DEFAULT FALSE,
    motif TEXT,
    FOREIGN KEY (id_eleve) REFERENCES utilisateurs(id_utilisateur)
);

```

### Table `pointage`

```sql
CREATE TABLE pointage (
    id_pointage INT PRIMARY KEY AUTO_INCREMENT,
    id_eleve INT,
    date_pointage DATE NOT NULL,
    heure_arrivee TIME,
    heure_depart TIME,
    statut VARCHAR(20) DEFAULT 'présent',
    commentaire TEXT,
    validateur_id INT,
    FOREIGN KEY (id_eleve) REFERENCES utilisateurs(id_utilisateur),
    FOREIGN KEY (validateur_id) REFERENCES utilisateurs(id_utilisateur)
);

```

### Table `retenues`

```sql
CREATE TABLE retenues (
    id_retenue INT PRIMARY KEY AUTO_INCREMENT,
    id_eleve INT,
    date_retenue DATE NOT NULL,
    heure_debut TIME NOT NULL,
    heure_fin TIME NOT NULL,
    motif TEXT,
    id_professeur INT,
    statut ENUM('programmée', 'effectuée', 'annulée') DEFAULT 'programmée',
    commentaire TEXT,
    FOREIGN KEY (id_eleve) REFERENCES utilisateurs(id_utilisateur),
    FOREIGN KEY (id_professeur) REFERENCES utilisateurs(id_utilisateur)
);

```

### Table `reunions`

```sql
CREATE TABLE reunions (
    id_reunion INT PRIMARY KEY AUTO_INCREMENT,
    titre VARCHAR(255) NOT NULL,
    date_reunion DATE NOT NULL,
    heure_debut TIME NOT NULL,
    heure_fin TIME NOT NULL,
    type_reunion ENUM('parents-professeurs', 'conseil_classe', 'administrative') NOT NULL,
    salle VARCHAR(50),
    description TEXT,
    organisateur_id INT,
    FOREIGN KEY (organisateur_id) REFERENCES utilisateurs(id_utilisateur)
);

```

### Table `eleve_parent`

```sql
CREATE TABLE eleve_parent (
    id_eleve INT,
    id_parent INT,
    PRIMARY KEY (id_eleve, id_parent),
    FOREIGN KEY (id_eleve) REFERENCES utilisateurs(id_utilisateur),
    FOREIGN KEY (id_parent) REFERENCES utilisateurs(id_utilisateur)
);

```

### Table `factures`

```sql
CREATE TABLE factures (
    id_facture INT PRIMARY KEY AUTO_INCREMENT,
    id_eleve INT,
    montant_total DECIMAL(10,2) NOT NULL,
    date_emission DATE NOT NULL,
    date_echeance DATE NOT NULL,
    statut ENUM('payée', 'en attente', 'en retard') DEFAULT 'en attente',
    FOREIGN KEY (id_eleve) REFERENCES utilisateurs(id_utilisateur)
);

```

### Table `paiements`

```sql
CREATE TABLE paiements (
    id_paiement INT PRIMARY KEY AUTO_INCREMENT,
    id_facture INT,
    montant DECIMAL(10,2) NOT NULL,
    date_paiement DATE NOT NULL,
    methode_paiement VARCHAR(50),
    FOREIGN KEY (id_facture) REFERENCES factures(id_facture)
);

```

## Conception Orientée Objet

### Définitions et Notions de Base

La programmation orientée objet (POO) est un paradigme de programmation qui utilise des "objets" pour représenter des données et des méthodes. Les objets sont des instances de classes, qui définissent des attributs (données) et des méthodes (fonctions) pour manipuler ces données.

#### Principes Fondamentaux

1. **Encapsulation** : Regrouper les données et les méthodes qui les manipulent dans une seule unité, la classe. Cela permet de cacher les détails internes et de protéger l'intégrité des données.

2. **Héritage** : Permettre à une classe de dériver d'une autre classe, héritant ainsi de ses attributs et méthodes. Cela favorise la réutilisation du code.

3. **Polymorphisme** : Permettre à des objets de différents types d'être traités comme des objets du même type, grâce à des interfaces communes.

4. **Abstraction** : Fournir une interface simplifiée pour interagir avec des objets complexes, en cachant les détails d'implémentation.

### Principes SOLID appliqués

1. **Single Responsibility** : Chaque classe doit avoir une seule responsabilité ou raison de changer.

```cpp
// Exemple de classes avec responsabilité unique
class Utilisateur {
    // Gère uniquement les informations utilisateur
};

class UtilisateurDAO {
    // Gère uniquement l'accès aux données utilisateur
};
```

2. **Open/Closed** : Les classes doivent être ouvertes à l'extension mais fermées à la modification.

```cpp
// Exemple de classes ouvertes à l'extension
class Note {
    virtual bool estValide() const {
        // Implémentation de la validation de la note
    }
};
```

### Hiérarchie des Classes

#### Diagramme de Classes - Utilisateur et Types d'Utilisateurs

```mermaid
classDiagram
    class Utilisateur {
        -int id
        -string nom
        -string prenom
        -string login
        -string type
        +verifierDroits(string action) bool
        +estValide() bool
    }

    class Eleve {
        -int idEleve
        -int classeId
        +getters/setters()
        +inscrireClasse(int classeId) bool
    }

    class Professeur {
        -int idProfesseur
        -list<int> matieres
        +getters/setters()
        +ajouterMatiere(int matiereId) bool
    }

    class Admin {
        -int idAdmin
        +gererUtilisateurs() void
        +gererSysteme() void
    }

    class Parent {
        -int idParent
        -list<int> enfantsIds
        +getters/setters()
        +ajouterEnfant(int eleveId) bool
    }

    Utilisateur <|-- Eleve
    Utilisateur <|-- Professeur
    Utilisateur <|-- Admin
    Utilisateur <|-- Parent
```

#### Diagramme de Classes - Classe et Eleve

```mermaid
classDiagram
    class Classe {
        -int id
        -string nom
        -string niveau
        +ajouterEleve(int eleveId) bool
        +estValide() bool
    }

    class Eleve {
        -int idEleve
        -int classeId
        +getters/setters()
        +inscrireClasse(int classeId) bool
    }

    Classe "1" --> "*" Eleve
```

#### Gestion de la Présence et Discipline - Pointage, Absence, Retard, Retenue

```mermaid
classDiagram
    class Pointage {
        -int id
        -int eleveId
        -string datePointage
        -string heureArrivee
        -string heureDepart
        -string statut
        -string commentaire
        -int validateurId
        +estValide() bool
        +estRetard() bool
    }

    class Absence {
        -int id
        -int eleveId
        -string dateDebut
        -string dateFin
        -bool justifie
        -string motif
        +estValide() bool
    }

    class Retard {
        -int id
        -int eleveId
        -string dateRetard
        -string heureArrivee
        -int dureeMinutes
        -bool justifie
        -string motif
        -int validateurId
        +estValide() bool
    }

    class Retenue {
        -int id
        -int eleveId
        -string dateRetenue
        -string heureDebut
        -string heureFin
        -string motif
        -int professeurId
        -string statut
        -string commentaire
        +estValide() bool
    }

    Pointage "*" --> "1" Eleve
    Absence "*" --> "1" Eleve
    Retard "*" --> "1" Eleve
    Retenue "*" --> "1" Eleve
```

#### Diagramme de Classes - Communication

```mermaid
classDiagram
    class Communication {
        -int id
        -string typeCommunication
        -string titre
        -string contenu
        -string dateEnvoi
        -int expediteurId
        -string importance
        -string pieceJointe
        -vector<int> destinatairesIds
        +ajouterDestinataire(int) bool
        +retirerDestinataire(int) bool
        +estValide() bool
    }

    Communication "*" --> "1" Utilisateur : expediteur
    Communication "*" --> "*" Utilisateur : destinataires
```

#### Diagramme de Classes - Paiement et Factures

```mermaid
classDiagram
    class Paiement {
        -int id
        -int factureId
        -float montant
        -string datePaiement
        -string methodePaiement
        +estValide() bool
    }

    class Facture {
        -int id
        -int eleveId
        -float montantTotal
        -string dateEmission
        -string dateEcheance
        -string statut
        +ajouterPaiement(Paiement paiement) bool
        +estValide() bool
    }

    Facture "1" --> "*" Paiement
    Facture "*" --> "1" Eleve
```

## Implémentation

### Connexion à la base de données

Le pattern Singleton est utilisé pour garantir une unique instance de connexion :

```cpp
class DatabaseConnection {
private:
    static DatabaseConnection* instance;
    DatabaseConnection();

public:
    static DatabaseConnection* getInstance();
    bool executeQuery(const std::string& query);
};

```

### Gestion des utilisateurs

La classe `UtilisateurDAO` gère toutes les opérations CRUD :

```cpp
class UtilisateurDAO {
public:
    bool ajouter(const Utilisateur& user);
    std::vector<Utilisateur> getAll();
    Utilisateur* getById(int id);
    bool modifier(const Utilisateur& user);
};

```

### Système de pointage

Le système de pointage est géré par la classe `PointageDAO` :

```cpp
class PointageDAO {
public:
    bool enregistrerArrivee(int eleveId, const std::string& heure);
    bool enregistrerDepart(int eleveId, const std::string& heure);
    std::vector<Pointage> getPointagesJour(const std::string& date);
};

```

## Interface Utilisateur

### Menu Principal

*[Capture d'écran à insérer]*

Description : Interface principale permettant l'accès aux différentes fonctionnalités :

- Gestion des utilisateurs
- Gestion des classes
- Gestion des matières
- Gestion des notes
- Système de pointage

### Gestion des Utilisateurs

*[Capture d'écran à insérer]*

Fonctionnalités :

- Création d'utilisateurs
- Modification des informations
- Activation/désactivation de comptes
- Recherche et filtrage

### Système de Pointage

*[Capture d'écran à insérer]*

Fonctionnalités :

- Enregistrement des entrées/sorties
- Consultation des retards
- Génération de rapports

---

## Gestion des Utilisateurs et des Parents

### Gestion des Utilisateurs

*[Capture d'écran à insérer]*

Fonctionnalités :

- Création d'utilisateurs
- Modification des informations
- Activation/désactivation de comptes
- Recherche et filtrage

### Gestion des Parents

*[Capture d'écran à insérer]*

Fonctionnalités :

- Ajout de parents
- Gestion des enfants
- Suivi des absences
- Communication avec les parents

## Gestion des Factures et Paiements

### Gestion des Factures

*[Capture d'écran à insérer]*

Fonctionnalités :

- Émission des factures
- Suivi des paiements
- Gestion des échéances

### Gestion des Paiements

*[Capture d'écran à insérer]*

Fonctionnalités :

- Traitement des paiements
- Suivi des paiements
- Gestion des méthodes de paiement

---




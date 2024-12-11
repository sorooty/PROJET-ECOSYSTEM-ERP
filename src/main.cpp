#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "../include/dao/UtilisateurDAO.hpp"
#include "../include/dao/ClasseDAO.hpp"
#include "../include/dao/MatiereDAO.hpp"
#include "../include/dao/PointageDAO.hpp"
#include "../include/dao/NoteDAO.hpp"
#include "../include/dao/CommunicationDAO.hpp"
#include "../include/dao/EnseignementDAO.hpp"

// Fonction pour afficher le menu principal
void afficherMenuPrincipal() {
    std::cout << "\n=== SYSTÈME DE GESTION SCOLAIRE ===" << std::endl;
    std::cout << "1. Gestion des utilisateurs" << std::endl;
    std::cout << "2. Gestion des classes" << std::endl;
    std::cout << "3. Gestion des matières" << std::endl;
    std::cout << "4. Gestion des notes" << std::endl;
    std::cout << "5. Gestion des absences" << std::endl;
    std::cout << "6. Gestion du pointage" << std::endl;
    std::cout << "7. Gestion des communications" << std::endl;  // Nouvelle option
    std::cout << "8. Gestion des enseignements" << std::endl;
    std::cout << "0. Quitter" << std::endl;
    std::cout << "Choix : ";
}

// Fonction pour afficher le menu des utilisateurs
void afficherMenuUtilisateurs() {
    std::cout << "\n=== GESTION DES UTILISATEURS ===" << std::endl;
    std::cout << "1. Ajouter un utilisateur" << std::endl;
    std::cout << "2. Afficher tous les utilisateurs" << std::endl;
    std::cout << "3. Rechercher par type" << std::endl;
    std::cout << "4. Rechercher par nom" << std::endl;
    std::cout << "5. Activer/Désactiver un utilisateur" << std::endl;
    std::cout << "6. Statistiques" << std::endl;
    std::cout << "7. Vérifier les droits d'un utilisateur" << std::endl;
    std::cout << "0. Retour au menu principal" << std::endl;
    std::cout << "Choix : ";
}

// Fonction pour afficher le menu des classes
void afficherMenuClasses() {
    std::cout << "\n=== GESTION DES CLASSES ===" << std::endl;
    std::cout << "1. Créer une classe" << std::endl;
    std::cout << "2. Afficher toutes les classes" << std::endl;
    std::cout << "3. Modifier une classe" << std::endl;
    std::cout << "4. Inscrire un élève" << std::endl;
    std::cout << "5. Désinscrire un élève" << std::endl;
    std::cout << "6. Liste des élèves d'une classe" << std::endl;
    std::cout << "7. Statistiques de classe" << std::endl;
    std::cout << "0. Retour au menu principal" << std::endl;
    std::cout << "Choix : ";
}

// Fonction pour afficher le menu des matières
void afficherMenuMatieres() {
    std::cout << "\n=== GESTION DES MATIÈRES ===" << std::endl;
    std::cout << "1. Ajouter une matière" << std::endl;
    std::cout << "2. Afficher toutes les matières" << std::endl;
    std::cout << "3. Modifier une matière" << std::endl;
    std::cout << "4. Supprimer une matière" << std::endl;
    std::cout << "5. Gestion des professeurs par matière" << std::endl;
    std::cout << "6. Voir les matières d'une classe" << std::endl;
    std::cout << "7. Gérer les coefficients" << std::endl;
    std::cout << "0. Retour au menu principal" << std::endl;
    std::cout << "Choix : ";
}

// Fonction pour afficher le menu des matières par professeur
void afficherMenuMatieresProfesseur() {
    std::cout << "\n=== GESTION DES MATIÈRES PAR PROFESSEUR ===" << std::endl;
    std::cout << "1. Voir mes matières enseignées" << std::endl;
    std::cout << "2. Voir les professeurs d'une matière" << std::endl;
    std::cout << "3. Assigner une matière à un professeur" << std::endl;
    std::cout << "4. Retirer une matière à un professeur" << std::endl;
    std::cout << "5. Voir l'emploi du temps par matière" << std::endl;
    std::cout << "0. Retour au menu des matières" << std::endl;
    std::cout << "Choix : ";
}

// Fonction pour afficher les statistiques utilisateurs
void afficherStatistiquesUtilisateurs(UtilisateurDAO& userDAO) {
    std::cout << "\n=== STATISTIQUES ===" << std::endl;
    std::cout << "Nombre d'élèves : " << userDAO.compterParType("eleve") << std::endl;
    std::cout << "Nombre de professeurs : " << userDAO.compterParType("professeur") << std::endl;
    std::cout << "Nombre d'administrateurs : " << userDAO.compterParType("admin") << std::endl;
}

// Fonction pour afficher le menu de pointage
void afficherMenuPointage() {
    std::cout << "\n=== GESTION DU POINTAGE ===" << std::endl;
    std::cout << "1. Enregistrer une arrivée" << std::endl;
    std::cout << "2. Enregistrer un départ" << std::endl;
    std::cout << "3. Consulter les pointages du jour" << std::endl;
    std::cout << "4. Consulter les retards" << std::endl;
    std::cout << "5. Rapport de présence par période" << std::endl;
    std::cout << "0. Retour au menu principal" << std::endl;
    std::cout << "Choix : ";
}

// Fonction pour afficher le menu des notes
void afficherMenuNotes() {
    std::cout << "\n=== GESTION DES NOTES ===" << std::endl;
    std::cout << "1. Ajouter une note" << std::endl;
    std::cout << "2. Modifier une note" << std::endl;
    std::cout << "3. Consulter les notes d'un élève" << std::endl;
    std::cout << "4. Calculer la moyenne d'un élève" << std::endl;
    std::cout << "5. Calculer la moyenne de classe" << std::endl;
    std::cout << "0. Retour au menu principal" << std::endl;
    std::cout << "Choix : ";
}

void afficherMenuCommunications() {
    std::cout << "\n=== GESTION DES COMMUNICATIONS ===" << std::endl;
    std::cout << "1. Créer une communication" << std::endl;
    std::cout << "2. Voir toutes les communications" << std::endl;
    std::cout << "3. Voir mes communications non lues" << std::endl;
    std::cout << "4. Marquer comme lu" << std::endl;
    std::cout << "5. Supprimer une communication" << std::endl;
    std::cout << "6. Gérer les destinataires" << std::endl;
    std::cout << "0. Retour au menu principal" << std::endl;
    std::cout << "Choix : ";
}

// Ajouter la fonction pour le menu des enseignements
void afficherMenuEnseignements() {
    std::cout << "\n=== GESTION DES ENSEIGNEMENTS ===" << std::endl;
    std::cout << "1. Attribuer un enseignement" << std::endl;
    std::cout << "2. Voir les enseignements par professeur" << std::endl;
    std::cout << "3. Voir les enseignements par classe" << std::endl;
    std::cout << "4. Voir les enseignements par matière" << std::endl;
    std::cout << "5. Supprimer un enseignement" << std::endl;
    std::cout << "0. Retour au menu principal" << std::endl;
    std::cout << "Choix : ";
}

int main() {
    try {
        int choixPrincipal;

        do {
            afficherMenuPrincipal();
            std::cin >> choixPrincipal;
            std::cin.ignore(10000, '\n');

            switch(choixPrincipal) {
                case 1: {  // Gestion des utilisateurs
                    UtilisateurDAO userDAO;
                    int choixUser;

                    do {
                        afficherMenuUtilisateurs();
                        std::cin >> choixUser;
                        std::cin.ignore(10000, '\n');

                        switch(choixUser) {
                            case 1: {  // Ajouter un utilisateur
                                std::string nom, prenom, email, type, motDePasse;

                                std::cout << "Nom : ";
                                std::getline(std::cin, nom);

                                std::cout << "Prénom : ";
                                std::getline(std::cin, prenom);

                                std::cout << "Email : ";
                                std::getline(std::cin, email);

                                std::cout << "Type (admin/professeur/eleve) : ";
                                std::getline(std::cin, type);

                                std::cout << "Mot de passe : ";
                                std::getline(std::cin, motDePasse);

                                Utilisateur nouvelUtilisateur(nom, prenom, email, type);
                                nouvelUtilisateur.setLogin(motDePasse);

                                if (userDAO.ajouter(nouvelUtilisateur)) {
                                    std::cout << "Utilisateur ajouté avec succès!" << std::endl;
                                } else {
                                    std::cout << "Erreur lors de l'ajout de l'utilisateur." << std::endl;
                                }
                                break;
                            }

                            case 2: {  // Afficher tous les utilisateurs
                                auto utilisateurs = userDAO.getAll();
                                if(utilisateurs.empty()) {
                                    std::cout << "Aucun utilisateur trouvé." << std::endl;
                                } else {
                                    std::cout << "\n=== LISTE DES UTILISATEURS ===" << std::endl;
                                    for(const auto& user : utilisateurs) {
                                        std::cout << "ID: " << user.getId()
                                                << " | Nom: " << user.getNom()
                                                << " " << user.getPrenom()
                                                << " | Type: " << user.getType()
                                                << " | Login: " << user.getLogin()
                                                << std::endl;
                                    }
                                }
                                break;
                            }

                            case 3: {  // Rechercher par type
                                std::string type;
                                std::cout << "Type à rechercher (admin/professeur/eleve) : ";
                                std::getline(std::cin, type);

                                auto utilisateurs = userDAO.rechercherParType(type);
                                if(utilisateurs.empty()) {
                                    std::cout << "Aucun utilisateur trouvé de type " << type << std::endl;
                                } else {
                                    std::cout << "\n=== UTILISATEURS DE TYPE " << type << " ===" << std::endl;
                                    for(const auto& user : utilisateurs) {
                                        std::cout << "ID: " << user.getId()
                                                << " | " << user.getNom()
                                                << " " << user.getPrenom()
                                                << std::endl;
                                    }
                                }
                                break;
                            }

                            case 4: {  // Rechercher par nom
                                std::string nom;
                                std::cout << "Nom à rechercher : ";
                                std::getline(std::cin, nom);

                                auto utilisateurs = userDAO.rechercherParNom(nom);
                                if(utilisateurs.empty()) {
                                    std::cout << "Aucun utilisateur trouvé avec le nom " << nom << std::endl;
                                } else {
                                    std::cout << "\n=== RÉSULTATS DE LA RECHERCHE ===" << std::endl;
                                    for(const auto& user : utilisateurs) {
                                        std::cout << "ID: " << user.getId()
                                                << " | " << user.getNom()
                                                << " " << user.getPrenom()
                                                << " | " << user.getType()
                                                << std::endl;
                                    }
                                }
                                break;
                            }

                            case 5: {  // Activer/Désactiver un utilisateur
                                int userId;
                                std::cout << "ID de l'utilisateur : ";
                                std::cin >> userId;
                                std::cin.ignore(10000, '\n');

                                Utilisateur* user = userDAO.getById(userId);
                                if(user) {
                                    bool nouveauStatut = !user->estActif();
                                    user->setActif(nouveauStatut);
                                    if(userDAO.modifier(*user)) {
                                        std::cout << "Statut modifié avec succès! L'utilisateur est maintenant "
                                                << (nouveauStatut ? "actif" : "inactif") << std::endl;
                                    } else {
                                        std::cout << "Erreur lors de la modification du statut." << std::endl;
                                    }
                                    delete user;
                                } else {
                                    std::cout << "Utilisateur non trouvé." << std::endl;
                                }
                                break;
                            }

                            case 6: {  // Statistiques
                                afficherStatistiquesUtilisateurs(userDAO);
                                break;
                            }

                            case 7: {  // Vérifier les droits
                                int userId;
                                std::cout << "ID de l'utilisateur : ";
                                std::cin >> userId;
                                std::cin.ignore(10000, '\n');

                                Utilisateur* user = userDAO.getById(userId);
                                if(user) {
                                    std::cout << "\nDroits de l'utilisateur " << user->getNomComplet() << " :" << std::endl;
                                    std::cout << "Type : " << user->getType() << std::endl;
                                    std::cout << "Statut : " << (user->estActif() ? "Actif" : "Inactif") << std::endl;
                                    delete user;
                                } else {
                                    std::cout << "Utilisateur non trouvé." << std::endl;
                                }
                                break;
                            }

                            case 0:
                                std::cout << "Retour au menu principal" << std::endl;
                                break;

                            default:
                                std::cout << "Option invalide!" << std::endl;
                        }
                    } while(choixUser != 0);
                    break;
                }

                case 2: {  // Gestion des classes
                    ClasseDAO classeDAO;
                    UtilisateurDAO userDAO;  // Pour la gestion des professeurs et élèves
                    int choixClasse;

                    do {
                        afficherMenuClasses();
                        std::cin >> choixClasse;
                        std::cin.ignore(10000, '\n');

                        switch(choixClasse) {
                            case 1: {  // Créer une classe
                                std::string nom, niveau, anneeScolaire, sallePrincipale;
                                int profPrincipalId, capaciteMax;

                                std::cout << "Nom de la classe : ";
                                std::getline(std::cin, nom);

                                std::cout << "Niveau (ex: 6ème, 5ème...) : ";
                                std::getline(std::cin, niveau);

                                std::cout << "Année scolaire (ex: 2023-2024) : ";
                                std::getline(std::cin, anneeScolaire);

                                std::cout << "ID du professeur principal : ";
                                std::cin >> profPrincipalId;

                                std::cout << "Capacité maximale : ";
                                std::cin >> capaciteMax;
                                std::cin.ignore(10000, '\n');

                                std::cout << "Salle principale : ";
                                std::getline(std::cin, sallePrincipale);

                                Classe nouvelleClasse(nom, niveau, anneeScolaire);
                                nouvelleClasse.setProfesseurPrincipalId(profPrincipalId);
                                nouvelleClasse.setCapaciteMax(capaciteMax);
                                nouvelleClasse.setSallePrincipale(sallePrincipale);

                                if (classeDAO.ajouter(nouvelleClasse)) {
                                    std::cout << "Classe créée avec succès!" << std::endl;
                                } else {
                                    std::cout << "Erreur lors de la création de la classe." << std::endl;
                                }
                                break;
                            }

                            case 2: {  // Afficher toutes les classes
                                auto classes = classeDAO.getAll();
                                if(classes.empty()) {
                                    std::cout << "Aucune classe trouvée." << std::endl;
                                } else {
                                    std::cout << "\n=== LISTE DES CLASSES ===" << std::endl;
                                    for(const auto& classe : classes) {
                                        std::cout << "ID: " << classe.getId()
                                                << " | Nom: " << classe.getNom()
                                                << " | Niveau: " << classe.getNiveau()
                                                << " | Année: " << classe.getAnneeScolaire()
                                                << " | Salle: " << classe.getSallePrincipale()
                                                << std::endl;
                                    }
                                }
                                break;
                            }

                            case 3: {  // Modifier une classe
                                int classeId;
                                std::cout << "ID de la classe à modifier : ";
                                std::cin >> classeId;
                                std::cin.ignore(10000, '\n');

                                Classe* classe = classeDAO.getById(classeId);
                                if (classe) {
                                    std::string nom, niveau, sallePrincipale;
                                    int capaciteMax;

                                    std::cout << "Nouveau nom (Enter pour garder '" << classe->getNom() << "') : ";
                                    std::getline(std::cin, nom);
                                    if (!nom.empty()) classe->setNom(nom);

                                    std::cout << "Nouveau niveau (Enter pour garder '" << classe->getNiveau() << "') : ";
                                    std::getline(std::cin, niveau);
                                    if (!niveau.empty()) classe->setNiveau(niveau);

                                    std::cout << "Nouvelle salle principale (Enter pour garder '" << classe->getSallePrincipale() << "') : ";
                                    std::getline(std::cin, sallePrincipale);
                                    if (!sallePrincipale.empty()) classe->setSallePrincipale(sallePrincipale);

                                    std::cout << "Nouvelle capacité maximale (0 pour garder " << classe->getCapaciteMax() << ") : ";
                                    std::cin >> capaciteMax;
                                    if (capaciteMax > 0) classe->setCapaciteMax(capaciteMax);

                                    if (classeDAO.modifier(*classe)) {
                                        std::cout << "Classe modifiée avec succès!" << std::endl;
                                    } else {
                                        std::cout << "Erreur lors de la modification de la classe." << std::endl;
                                    }
                                    delete classe;
                                } else {
                                    std::cout << "Classe non trouvée." << std::endl;
                                }
                                break;
                            }

                            case 4: {  // Inscrire un élève
                                int classeId, eleveId;
                                std::cout << "ID de la classe : ";
                                std::cin >> classeId;
                                std::cout << "ID de l'élève : ";
                                std::cin >> eleveId;

                                if (classeDAO.inscrireEleve(classeId, eleveId)) {
                                    std::cout << "Élève inscrit avec succès!" << std::endl;
                                } else {
                                    std::cout << "Erreur lors de l'inscription de l'élève." << std::endl;
                                }
                                break;
                            }

                            case 5: {  // Désinscrire un élève
                                int classeId, eleveId;
                                std::cout << "ID de la classe : ";
                                std::cin >> classeId;
                                std::cout << "ID de l'élève : ";
                                std::cin >> eleveId;

                                if (classeDAO.desinscrireEleve(classeId, eleveId)) {
                                    std::cout << "Élève désinscrit avec succès!" << std::endl;
                                } else {
                                    std::cout << "Erreur lors de la désinscription de l'élève." << std::endl;
                                }
                                break;
                            }

                            case 6: {  // Liste des élèves d'une classe
                                int classeId;
                                std::cout << "ID de la classe : ";
                                std::cin >> classeId;

                                auto eleves = classeDAO.getElevesClasse(classeId);
                                if(eleves.empty()) {
                                    std::cout << "Aucun élève trouvé dans cette classe." << std::endl;
                                } else {
                                    std::cout << "\n=== ÉLÈVES DE LA CLASSE ===" << std::endl;
                                    for(const auto& eleve : eleves) {
                                        std::cout << "ID: " << eleve.getId()
                                                << " | " << eleve.getNom()
                                                << " " << eleve.getPrenom()
                                                << std::endl;
                                    }
                                }
                                break;
                            }

                            case 7: {  // Statistiques de classe
                                int classeId;
                                std::cout << "ID de la classe : ";
                                std::cin >> classeId;

                                Classe* classe = classeDAO.getById(classeId);
                                if (classe) {
                                    auto eleves = classeDAO.getElevesClasse(classeId);  // Changé de getEleves
                                    std::cout << "\n=== STATISTIQUES DE LA CLASSE ===" << std::endl;
                                    std::cout << "Nombre d'élèves : " << eleves.size() << std::endl;
                                    std::cout << "Capacité maximale : " << classe->getCapaciteMax() << std::endl;
                                    std::cout << "Places disponibles : " << (classe->getCapaciteMax() - eleves.size()) << std::endl;
                                    delete classe;
                                } else {
                                    std::cout << "Classe non trouvée." << std::endl;
                                }
                                break;
                            }
                                                            case 0:
                                std::cout << "Retour au menu principal" << std::endl;
                                break;

                            default:
                                std::cout << "Option invalide!" << std::endl;
                        }
                    } while(choixClasse != 0);
                    break;
                }

                case 3: {  // Gestion des matières
                    MatiereDAO matiereDAO;
                    UtilisateurDAO userDAO;
                    int choixMatiere;

                    do {
                        afficherMenuMatieres();
                        std::cin >> choixMatiere;
                        std::cin.ignore(10000, '\n');

                        switch(choixMatiere) {
                            case 1: {  // Ajouter une matière
                                std::string nom, description;
                                int coefficient, volumeHoraire;

                                std::cout << "Nom de la matière : ";
                                std::getline(std::cin, nom);

                                std::cout << "Description : ";
                                std::getline(std::cin, description);

                                std::cout << "Coefficient : ";
                                while(!(std::cin >> coefficient) || coefficient <= 0) {
                                    std::cout << "Veuillez entrer un coefficient valide (> 0) : ";
                                    std::cin.clear();
                                    std::cin.ignore(10000, '\n');
                                }

                                std::cout << "Volume horaire (en heures) : ";
                                while(!(std::cin >> volumeHoraire) || volumeHoraire <= 0) {
                                    std::cout << "Veuillez entrer un volume horaire valide (> 0) : ";
                                    std::cin.clear();
                                    std::cin.ignore(10000, '\n');
                                }
                                std::cin.ignore(10000, '\n');

                                Matiere nouvelleMatiere(nom, description, coefficient, volumeHoraire);
                                if (nouvelleMatiere.estValide()) {
                                    if (matiereDAO.ajouter(nouvelleMatiere)) {
                                        std::cout << "Matière ajoutée avec succès!" << std::endl;
                                    } else {
                                        std::cout << "Erreur lors de l'ajout de la matière." << std::endl;
                                    }
                                } else {
                                    std::cout << "Données de matière invalides" << std::endl;
                                }
                                break;
                            }
                            case 2: {  // Afficher toutes les matières
                                auto matieres = matiereDAO.getAll();
                                if(matieres.empty()) {
                                    std::cout << "Aucune matière trouvée." << std::endl;
                                } else {
                                    std::cout << "\n=== LISTE DES MATIÈRES ===" << std::endl;
                                    for(const auto& m : matieres) {
                                        std::cout << "ID: " << m.getId()
                                                << " | " << m.getNom()
                                                << " | Coef: " << m.getCoefficient()
                                                << " | Volume: " << m.getVolumeHoraire() << "h"
                                                << std::endl;
                                    }
                                }
                                break;
                            }

                            case 3: {  // Modifier une matière
                                int matiereId;
                                std::cout << "ID de la matière à modifier : ";
                                std::cin >> matiereId;
                                std::cin.ignore(10000, '\n');

                                Matiere* matiere = matiereDAO.getById(matiereId);
                                if (matiere) {
                                    std::string nom, description;
                                    int coefficient, volumeHoraire;

                                    std::cout << "Nouveau nom (Enter pour garder '" << matiere->getNom() << "') : ";
                                    std::getline(std::cin, nom);
                                    if (!nom.empty()) matiere->setNom(nom);

                                    std::cout << "Nouvelle description (Enter pour garder actuelle) : ";
                                    std::getline(std::cin, description);
                                    if (!description.empty()) matiere->setDescription(description);

                                    std::cout << "Nouveau coefficient (0 pour garder " << matiere->getCoefficient() << ") : ";
                                    std::cin >> coefficient;
                                    if (coefficient > 0) matiere->setCoefficient(coefficient);

                                    std::cout << "Nouveau volume horaire (0 pour garder " << matiere->getVolumeHoraire() << ") : ";
                                    std::cin >> volumeHoraire;
                                    if (volumeHoraire > 0) matiere->setVolumeHoraire(volumeHoraire);

                                    if (matiereDAO.modifier(*matiere)) {
                                        std::cout << "Matière modifiée avec succès!" << std::endl;
                                    } else {
                                        std::cout << "Erreur lors de la modification de la matière." << std::endl;
                                    }
                                    delete matiere;
                                } else {
                                    std::cout << "Matière non trouvée." << std::endl;
                                }
                                break;
                            }

                            case 4: {  // Supprimer une matière
                                int matiereId;
                                std::cout << "ID de la matière à supprimer : ";
                                std::cin >> matiereId;

                                if (matiereDAO.supprimer(matiereId)) {
                                    std::cout << "Matière supprimée avec succès!" << std::endl;
                                } else {
                                    std::cout << "Erreur lors de la suppression de la matière." << std::endl;
                                }
                                break;
                            }

                            case 5: {  // Gestion des professeurs par matière
                                int choixProfMatiere;
                                do {
                                    afficherMenuMatieresProfesseur();
                                    std::cin >> choixProfMatiere;
                                    std::cin.ignore(10000, '\n');

                                    switch(choixProfMatiere) {
                                        case 1: {  // Voir mes matières enseignées
                                            int profId;
                                            std::cout << "ID du professeur : ";
                                            std::cin >> profId;

                                            auto matieres = matiereDAO.getMatieresParProfesseur(profId);
                                            if(matieres.empty()) {
                                                std::cout << "Aucune matière enseignée trouvée." << std::endl;
                                            } else {
                                                std::cout << "\n=== MATIÈRES ENSEIGNÉES ===" << std::endl;
                                                for(const auto& m : matieres) {
                                                    std::cout << "- " << m.getNom()
                                                            << " (Coef: " << m.getCoefficient()
                                                            << ", Volume: " << m.getVolumeHoraire() << "h)"
                                                            << std::endl;
                                                }
                                            }
                                            break;
                                        }

                                        case 2: {  // Voir les professeurs d'une matière
                                            int matiereId;
                                            std::cout << "ID de la matière : ";
                                            std::cin >> matiereId;

                                            auto professeurs = userDAO.getProfesseursParMatiere(matiereId);
                                            if(professeurs.empty()) {
                                                std::cout << "Aucun professeur assigné à cette matière." << std::endl;
                                            } else {
                                                std::cout << "\n=== PROFESSEURS DE LA MATIÈRE ===" << std::endl;
                                                for(const auto& p : professeurs) {
                                                    std::cout << "- " << p.getNomComplet() << std::endl;
                                                }
                                            }
                                            break;
                                        }

                                        case 3: {  // Assigner une matière à un professeur
                                            int profId, matiereId;
                                            std::string anneeScolaire;

                                            std::cout << "ID du professeur : ";
                                            std::cin >> profId;
                                            std::cout << "ID de la matière : ";
                                            std::cin >> matiereId;
                                            std::cin.ignore(10000, '\n');
                                            std::cout << "Année scolaire (ex: 2023-2024) : ";
                                            std::getline(std::cin, anneeScolaire);

                                            if (matiereDAO.assignerProfesseur(matiereId, profId, anneeScolaire)) {
                                                std::cout << "Matière assignée avec succès!" << std::endl;
                                            } else {
                                                std::cout << "Erreur lors de l'assignation de la matière." << std::endl;
                                            }
                                            break;
                                        }

                                        case 4: {  // Retirer une matière à un professeur
                                            int profId, matiereId;
                                            std::cout << "ID du professeur : ";
                                            std::cin >> profId;
                                            std::cout << "ID de la matière : ";
                                            std::cin >> matiereId;

                                            if (matiereDAO.retirerProfesseur(matiereId, profId)) {
                                                std::cout << "Matière retirée avec succès!" << std::endl;
                                            } else {
                                                std::cout << "Erreur lors du retrait de la matière." << std::endl;
                                            }
                                            break;
                                        }

                                        case 5: {  // Voir l'emploi du temps par matière
                                            int matiereId;
                                            std::cout << "ID de la matière : ";
                                            std::cin >> matiereId;

                                            std::cout << "Fonctionnalité à implémenter avec le module d'emploi du temps." << std::endl;
                                            break;
                                        }

                                        case 0:
                                            std::cout << "Retour au menu des matières" << std::endl;
                                            break;

                                        default:
                                            std::cout << "Option invalide!" << std::endl;
                                    }
                                } while(choixProfMatiere != 0);
                                break;
                            }

                            case 6: {  // Voir les matières d'une classe
                                int classeId;
                                std::cout << "ID de la classe : ";
                                std::cin >> classeId;

                                auto matieres = matiereDAO.getMatieresParClasse(classeId);
                                if(matieres.empty()) {
                                    std::cout << "Aucune matière trouvée pour cette classe." << std::endl;
                                } else {
                                    std::cout << "\n=== MATIÈRES DE LA CLASSE ===" << std::endl;
                                    for(const auto& m : matieres) {
                                        std::cout << "- " << m.getNom()
                                                << " (Coef: " << m.getCoefficient()
                                                << ", Volume: " << m.getVolumeHoraire() << "h)"
                                                << std::endl;
                                    }
                                }
                                break;
                            }

                            case 7: {  // Gérer les coefficients
                                int matiereId, nouveauCoef;
                                std::cout << "ID de la matière : ";
                                std::cin >> matiereId;

                                Matiere* matiere = matiereDAO.getById(matiereId);
                                if (matiere) {
                                    std::cout << "Coefficient actuel : " << matiere->getCoefficient() << std::endl;
                                    std::cout << "Nouveau coefficient : ";
                                    std::cin >> nouveauCoef;

                                    if (nouveauCoef > 0) {
                                        matiere->setCoefficient(nouveauCoef);
                                        if (matiereDAO.modifier(*matiere)) {
                                            std::cout << "Coefficient modifié avec succès!" << std::endl;
                                        } else {
                                            std::cout << "Erreur lors de la modification du coefficient." << std::endl;
                                        }
                                    } else {
                                        std::cout << "Le coefficient doit être supérieur à 0." << std::endl;
                                    }
                                    delete matiere;
                                } else {
                                    std::cout << "Matière non trouvée." << std::endl;
                                }
                                break;
                            }

                            case 0:
                                std::cout << "Retour au menu principal" << std::endl;
                                break;

                            default:
                                std::cout << "Option invalide!" << std::endl;
                        }
                    } while(choixMatiere != 0);
                    break;
                }

                case 4: {  // Gestion des notes
                    NoteDAO noteDAO;
                    int choixNotes;
                    do {
                        afficherMenuNotes();
                        std::cin >> choixNotes;

                        switch(choixNotes) {
                            case 1: {  // Ajouter une note
                                int eleveId, matiereId, professeurId, coefficient;
                                double valeur;
                                std::string type, commentaire;

                                std::cout << "ID de l'élève : ";
                                std::cin >> eleveId;
                                std::cout << "ID de la matière : ";
                                std::cin >> matiereId;
                                std::cout << "ID du professeur : ";
                                std::cin >> professeurId;
                                std::cout << "Note (sur 20) : ";
                                std::cin >> valeur;
                                std::cout << "Coefficient : ";
                                std::cin >> coefficient;
                                std::cin.ignore();
                                std::cout << "Type d'évaluation : ";
                                std::getline(std::cin, type);

                                std::cout << "Date d'évaluation (YYYY-MM-DD, vide pour aujourd'hui) : ";
                                std::string dateEval;
                                std::getline(std::cin, dateEval);

                                std::cout << "Commentaire (facultatif) : ";
                                std::getline(std::cin, commentaire);

                                // Gestion de la date
                                std::string dateFinale;
                                if (dateEval.empty()) {
                                    time_t now = time(0);
                                    struct tm* ltm = localtime(&now);
                                    std::stringstream dateStr;
                                    dateStr << std::put_time(ltm, "%Y-%m-%d");
                                    dateFinale = dateStr.str();
                                } else {
                                    dateFinale = dateEval;
                                }

                                Note note(eleveId, matiereId, professeurId, valeur, coefficient, type);
                                note.setDateEvaluation(dateFinale);
                                note.setCommentaire(commentaire);

                                if (noteDAO.ajouter(note)) {
                                    std::cout << "Note ajoutée avec succès!" << std::endl;
                                } else {
                                    std::cout << "Erreur lors de l'ajout de la note." << std::endl;
                                }
                                break;
                            }

                            case 3: {  // Consulter les notes
                                int eleveId;
                                std::cout << "ID de l'élève : ";
                                std::cin >> eleveId;

                                auto notes = noteDAO.getNotesEleve(eleveId);
                                std::cout << "\nNotes de l'élève :" << std::endl;
                                std::cout << "Matière\tNote\tCoef\tType\tDate\tCommentaire" << std::endl;
                                for (const auto& note : notes) {
                                    std::cout << note.getMatiereId() << "\t"
                                             << note.getValeur() << "\t"
                                             << note.getCoefficient() << "\t"
                                             << note.getTypeEvaluation() << "\t"
                                             << note.getDateEvaluation() << "\t"
                                             << (note.getCommentaire().empty() ? "-" : note.getCommentaire())
                                             << std::endl;
                                }
                                break;
                            }

                            case 4: {  // Moyenne d'un élève
                                int eleveId, matiereId;
                                std::cout << "ID de l'élève : ";
                                std::cin >> eleveId;
                                std::cout << "ID de la matière (0 pour moyenne générale) : ";
                                std::cin >> matiereId;

                                double moyenne = noteDAO.getMoyenneEleve(eleveId, matiereId);
                                std::cout << "Moyenne : " << moyenne << "/20" << std::endl;
                                break;
                            }

                            case 0:
                                std::cout << "Retour au menu principal" << std::endl;
                                break;

                            default:
                                std::cout << "Option invalide!" << std::endl;
                        }
                    } while(choixNotes != 0);
                    break;
                }

                case 6: {
                    PointageDAO pointageDAO;
                    int choixPointage;
                    do {
                        afficherMenuPointage();
                        std::cin >> choixPointage;

                        switch(choixPointage) {
                            case 1: {
                                // Enregistrer une arrivée
                                int eleveId;
                                std::cout << "ID de l'élève : ";
                                std::cin >> eleveId;

                                // Obtenir l'heure actuelle
                                time_t now = time(0);
                                struct tm* ltm = localtime(&now);
                                std::stringstream heureArrivee;
                                heureArrivee << std::setfill('0')
                                           << std::setw(2) << ltm->tm_hour << ":"
                                           << std::setw(2) << ltm->tm_min << ":"
                                           << std::setw(2) << ltm->tm_sec;

                                if (pointageDAO.enregistrerArrivee(eleveId, heureArrivee.str())) {
                                    std::cout << "Arrivée enregistrée avec succès!" << std::endl;
                                } else {
                                    std::cout << "Erreur lors de l'enregistrement de l'arrivée." << std::endl;
                                }
                                break;
                            }

                            case 2: {
                                // Enregistrer un départ
                                int eleveId;
                                std::cout << "ID de l'élève : ";
                                std::cin >> eleveId;

                                time_t now = time(0);
                                struct tm* ltm = localtime(&now);
                                std::stringstream heureDepart;
                                heureDepart << std::setfill('0')
                                          << std::setw(2) << ltm->tm_hour << ":"
                                          << std::setw(2) << ltm->tm_min << ":"
                                          << std::setw(2) << ltm->tm_sec;

                                if (pointageDAO.enregistrerDepart(eleveId, heureDepart.str())) {
                                    std::cout << "Départ enregistré avec succès!" << std::endl;
                                } else {
                                    std::cout << "Erreur lors de l'enregistrement du départ." << std::endl;
                                }
                                break;
                            }

                            case 3: {
                                // Consulter les pointages du jour
                                time_t now = time(0);  // Déclaration de now
                                struct tm* ltm = localtime(&now);

                                // Formater la date du jour
                                std::stringstream dateStr;
                                dateStr << std::put_time(ltm, "%Y-%m-%d");

                                std::vector<Pointage> pointages = pointageDAO.getPointagesJour(dateStr.str());

                                std::cout << "\nPointages du jour :" << std::endl;
                                std::cout << "ID\tÉlève\tArrivée\tDépart\tStatut" << std::endl;
                                for (const Pointage& p : pointages) {  // Spécifier le type explicitement
                                    std::cout << p.getId() << "\t"
                                            << p.getEleveId() << "\t"
                                            << p.getHeureArrivee() << "\t"
                                            << p.getHeureDepart() << "\t"
                                            << p.getStatut() << std::endl;
                                }
                                break;
                            }

                            case 4: {
                                // Consulter les retards
                                int eleveId;
                                std::cout << "ID de l'élève (0 pour tous) : ";
                                std::cin >> eleveId;

                                std::vector<Pointage> retards;
                                if (eleveId > 0) {
                                    retards = pointageDAO.getRetardsEleve(eleveId);
                                } else {
                                    // Utiliser la date du jour
                                    time_t now = time(0);
                                    struct tm* ltm = localtime(&now);
                                    std::stringstream dateStr;
                                    dateStr << std::put_time(ltm, "%Y-%m-%d");

                                    // Utiliser getPointagesJour au lieu de getRetardsJour
                                    retards = pointageDAO.getPointagesJour(dateStr.str());
                                }

                                std::cout << "\nListe des retards :" << std::endl;
                                for (const Pointage& r : retards) {
                                    if (r.estRetard()) {  // Vérifier si c'est un retard
                                        std::cout << "Élève ID: " << r.getEleveId()
                                                 << " - Heure d'arrivée: " << r.getHeureArrivee()
                                                 << std::endl;
                                    }
                                }
                                break;
                            }

                            case 5: {
                                // Rapport de présence par période
                                std::string dateDebut, dateFin;
                                std::cout << "Date de début (YYYY-MM-DD) : ";
                                std::cin >> dateDebut;
                                std::cout << "Date de fin (YYYY-MM-DD) : ";
                                std::cin >> dateFin;

                                // TODO: Implémenter la génération de rapport
                                std::cout << "Fonctionnalité en cours de développement." << std::endl;
                                break;
                            }

                            case 0:
                                std::cout << "Retour au menu principal" << std::endl;
                                break;

                            default:
                                std::cout << "Option invalide!" << std::endl;
                        }
                    } while(choixPointage != 0);
                    break;
                }


                case 7: {  // Gestion des communications
                    CommunicationDAO communicationDAO;
                    int choixComm;

                    do {
                        afficherMenuCommunications();
                        std::cin >> choixComm;
                        std::cin.ignore(10000, '\n');

                        switch(choixComm) {
                            case 1: {  // Créer une communication
                                std::string type, titre, contenu;
                                int expediteurId;

                                std::cout << "Type (annonce/message/notification) : ";
                                std::getline(std::cin, type);

                                std::cout << "Titre : ";
                                std::getline(std::cin, titre);

                                std::cout << "Contenu : ";
                                std::getline(std::cin, contenu);

                                std::cout << "ID de l'expéditeur : ";
                                std::cin >> expediteurId;
                                std::cin.ignore(10000, '\n');

                                Communication comm(type, titre, contenu, expediteurId);

                                std::cout << "Importance (normale/importante/urgente) : ";
                                std::string importance;
                                std::getline(std::cin, importance);
                                comm.setImportance(importance);

                                // Gestion des destinataires
                                std::cout << "Ajouter des destinataires (0 pour terminer) :" << std::endl;
                                int destinataireId;
                                do {
                                    std::cout << "ID destinataire : ";
                                    std::cin >> destinataireId;
                                    if (destinataireId > 0) {
                                        comm.ajouterDestinataire(destinataireId);
                                    }
                                } while (destinataireId != 0);

                                if (communicationDAO.ajouter(comm)) {
                                    std::cout << "Communication créée avec succès!" << std::endl;
                                } else {
                                    std::cout << "Erreur lors de la création de la communication." << std::endl;
                                }
                                break;
                            }

                            case 2: {  // Voir toutes les communications
                                auto communications = communicationDAO.getAll();
                                if(communications.empty()) {
                                    std::cout << "Aucune communication trouvée." << std::endl;
                                } else {
                                    std::cout << "\n=== LISTE DES COMMUNICATIONS ===" << std::endl;
                                    for(const auto& comm : communications) {
                                        std::cout << "ID: " << comm.getId() << std::endl
                                                << "Type: " << comm.getType() << std::endl
                                                << "Titre: " << comm.getTitre() << std::endl
                                                << "Date: " << comm.getDateEnvoi() << std::endl
                                                << "Importance: " << comm.getImportance() << std::endl
                                                << "------------------------" << std::endl;
                                    }
                                }
                                break;
                            }

                            case 3: {  // Voir mes communications non lues
                                int utilisateurId;
                                std::cout << "Votre ID utilisateur : ";
                                std::cin >> utilisateurId;

                                auto nonLues = communicationDAO.getCommunicationsNonLues(utilisateurId);
                                if(nonLues.empty()) {
                                    std::cout << "Aucune communication non lue." << std::endl;
                                } else {
                                    std::cout << "\n=== COMMUNICATIONS NON LUES ===" << std::endl;
                                    for(const auto& comm : nonLues) {
                                        std::cout << "ID: " << comm.getId() << std::endl
                                                << "Titre: " << comm.getTitre() << std::endl
                                                << "------------------------" << std::endl;
                                    }
                                }
                                break;
                            }

                            case 4: {  // Marquer comme lu
                                int commId, userId;
                                std::cout << "ID de la communication : ";
                                std::cin >> commId;
                                std::cout << "Votre ID utilisateur : ";
                                std::cin >> userId;

                                if (communicationDAO.marquerCommeLue(commId, userId)) {
                                    std::cout << "Communication marquée comme lue." << std::endl;
                                } else {
                                    std::cout << "Erreur lors du marquage de la communication." << std::endl;
                                }
                                break;
                            }

                            case 5: {  // Supprimer une communication
                                int commId;
                                std::cout << "ID de la communication à supprimer : ";
                                std::cin >> commId;

                                if (communicationDAO.supprimer(commId)) {
                                    std::cout << "Communication supprimée avec succès!" << std::endl;
                                } else {
                                    std::cout << "Erreur lors de la suppression." << std::endl;
                                }
                                break;
                            }

                            case 0:
                                std::cout << "Retour au menu principal" << std::endl;
                                break;

                            default:
                                std::cout << "Option invalide!" << std::endl;
                        }
                    } while(choixComm != 0);
                    break;
                }
                case 8: {  // Gestion des enseignements
                    EnseignementDAO enseignementDAO;
                    int choixEns;

                    do {
                        afficherMenuEnseignements();
                        std::cin >> choixEns;
                        std::cin.ignore(10000, '\n');

                        switch(choixEns) {
                            case 1: {  // Attribuer un enseignement
                                int profId, matId, classeId;
                                std::cout << "ID du professeur : ";
                                std::cin >> profId;
                                std::cout << "ID de la matière : ";
                                std::cin >> matId;
                                std::cout << "ID de la classe : ";
                                std::cin >> classeId;

                                Enseignement ens(profId, matId, classeId);
                                if (enseignementDAO.ajouter(ens)) {
                                    std::cout << "Enseignement ajouté avec succès!" << std::endl;
                                } else {
                                    std::cout << "Erreur lors de l'ajout de l'enseignement." << std::endl;
                                }
                                break;
                            }

                            case 2: {  // Voir les enseignements par professeur
                                int profId;
                                std::cout << "ID du professeur : ";
                                std::cin >> profId;

                                std::vector<Enseignement> enseignements = enseignementDAO.getByProfesseur(profId);
                                if(enseignements.empty()) {
                                    std::cout << "Aucun enseignement trouvé pour ce professeur." << std::endl;
                                } else {
                                    std::cout << "\n=== ENSEIGNEMENTSDU PROFESSEUR ===" << std::endl;
                                    for(const Enseignement& ens : enseignements) {
                                        std::cout << "Matière ID: " << ens.getMatiereId()
                                                << " | Classe ID: " << ens.getClasseId()
                                                << std::endl;
                                    }
                                }
                                break;
                            }

                            case 3: {  // Voir les enseignements par classe
                                int classeId;
                                std::cout << "ID de la classe : ";
                                std::cin >> classeId;

                                std::vector<Enseignement> enseignements = enseignementDAO.getByClasse(classeId);
                                if(enseignements.empty()) {
                                    std::cout << "Aucun enseignement trouvé pour cette classe." << std::endl;
                                } else {
                                    std::cout << "\n=== ENSEIGNEMENTS DELA CLASSE ===" << std::endl;
                                    for(const Enseignement& ens : enseignements) {
                                        std::cout << "Professeur ID: " << ens.getProfesseurId()
                                                << " | Matière ID: " << ens.getMatiereId()
                                                << std::endl;
                                    }
                                }
                                break;
                            }

                            case 4: {  // Voir les enseignements par matière
                                int matiereId;
                                std::cout << "ID de la matière : ";
                                std::cin >> matiereId;

                                std::vector<Enseignement> enseignements = enseignementDAO.getByMatiere(matiereId);
                                if(enseignements.empty()) {
                                    std::cout << "Aucun enseignement trouvé pour cette matière." << std::endl;
                                } else {
                                    std::cout << "\n=== ENSEIGNEMENTS DELA MATIÈRE ===" << std::endl;
                                    for(const Enseignement& ens : enseignements) {
                                        std::cout << "Professeur ID: " << ens.getProfesseurId()
                                                << " | Classe ID: " << ens.getClasseId()
                                                << std::endl;
                                    }
                                }
                                break;
                            }

                            case 5: {  // Supprimer un enseignement
                                int ensId;
                                std::cout << "ID de l'enseignement à supprimer : ";
                                std::cin >> ensId;

                                if (enseignementDAO.supprimer(ensId)) {
                                    std::cout << "Enseignement supprimé avec succès!" << std::endl;
                                } else {
                                    std::cout << "Erreur lors de la suppression de l'enseignement." << std::endl;
                                }
                                break;
                            }

                            case 0:
                                std::cout << "Retour au menu principal" << std::endl;
                                break;

                            default:
                                std::cout << "Option invalide!" << std::endl;
                        }
                    } while(choixEns != 0);
                    break;
                }
                case 0:
                    std::cout << "Au revoir!" << std::endl;
                    break;

                default:
                    std::cout << "Option invalide!" << std::endl;
            }

        } while(choixPrincipal != 0);

    } catch (const std::exception& e) {
        std::cout << "Erreur: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

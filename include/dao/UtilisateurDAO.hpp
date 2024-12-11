#ifndef UTILISATEURDAO_HPP
#define UTILISATEURDAO_HPP

#include <vector>
#include "../models/Utilisateur.hpp"
#include "../models/Matiere.hpp"
#include "../DatabaseConnection.hpp"

class UtilisateurDAO {
private:
    DatabaseConnection* db;

public:
    UtilisateurDAO();

    // Corriger les noms des méthodes selon votre implémentation
    bool inscrireEleve(int classeId, int eleveId);  // au lieu de ajouterEleve
    bool desinscrireEleve(int classeId, int eleveId);  // au lieu de retirerEleve
    std::vector<Utilisateur> getElevesClasse(int classeId);  // au lieu de getEleves

    // Méthodes CRUD
    bool ajouter(const Utilisateur& user);
    std::vector<Utilisateur> getAll();
    Utilisateur* getById(int id);
    bool modifier(const Utilisateur& user);
    bool supprimer(int id);

    // Méthodes de recherche
    std::vector<Utilisateur> rechercherParType(const std::string& type);
    std::vector<Utilisateur> rechercherParNom(const std::string& nom);

    // Méthodes de gestion du statut
    bool activerUtilisateur(int id);
    bool desactiverUtilisateur(int id);

    // Méthodes statistiques
    int compterParType(const std::string& type);

    // Nouvelles méthodes pour la gestion des matières
    bool assignerMatiereAProfesseur(int profId, int matiereId);
    bool retirerMatiereAProfesseur(int profId, int matiereId);
    std::vector<Matiere> getMatieresEnseignees(int profId);
    std::vector<Utilisateur> getProfesseursParMatiere(int matiereId);


};

#endif

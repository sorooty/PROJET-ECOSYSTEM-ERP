#ifndef MATIEREDAO_HPP
#define MATIEREDAO_HPP

#include <vector>
#include "../models/Matiere.hpp"
#include "../DatabaseConnection.hpp"

class MatiereDAO {
private:
    DatabaseConnection* db;

public:
    MatiereDAO();

    // Méthodes CRUD
    bool ajouter(const Matiere& matiere);
    std::vector<Matiere> getAll();
    Matiere* getById(int id);
    bool modifier(const Matiere& matiere);
    bool supprimer(int id);

    // Méthodes de gestion des professeurs
    bool assignerProfesseur(int matiereId, int profId, const std::string& anneeScolaire);
    bool retirerProfesseur(int matiereId, int profId);

    // Méthodes de recherche
    std::vector<Matiere> getMatieresParClasse(int classeId);
    std::vector<Matiere> getMatieresParProfesseur(int profId);

    // Méthodes de gestion classe-matière
    bool ajouterMatiereClasse(int classeId, int matiereId, int profId, int volumeHoraire);
    bool modifierVolumeHoraire(int classeId, int matiereId, int nouveauVolume);
};

#endif

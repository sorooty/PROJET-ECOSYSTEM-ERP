#ifndef CLASSEDAO_HPP
#define CLASSEDAO_HPP

#include <vector>
#include <string>
#include "../models/Classe.hpp"
#include "../models/Utilisateur.hpp"
#include "../databaseConnection.hpp"

class ClasseDAO {
private:
    DatabaseConnection* db;

public:
    // Constructeur et destructeur
    ClasseDAO();
    ~ClasseDAO();

    // Méthodes CRUD de base
    bool ajouter(const Classe& classe);
    bool modifier(const Classe& classe);  // Déclaré une seule fois
    bool supprimer(int id);
    Classe* getById(int id);
    std::vector<Classe> getAll();

    // Méthodes de gestion des élèves
    bool inscrireEleve(int classeId, int eleveId);
    bool desinscrireEleve(int classeId, int eleveId);  // Déclaré une seule fois
    std::vector<Utilisateur> getElevesClasse(int classeId);

    // Autres méthodes utiles
    bool verifierCapacite(int classeId);
    int compterEleves(int classeId);
    bool estInscrit(int classeId, int eleveId);
    std::vector<Classe> getClassesParNiveau(const std::string& niveau);
    std::vector<Classe> getClassesParAnnee(const std::string& anneeScolaire);
};

#endif // CLASSEDAO_HPP

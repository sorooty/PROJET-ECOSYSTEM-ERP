#ifndef POINTAGEDAO_HPP
#define POINTAGEDAO_HPP

#include "../models/Pointage.hpp"
#include "../DatabaseConnection.hpp"
#include <vector>

class PointageDAO {
private:
    DatabaseConnection* db;

public:
    PointageDAO();

    // Méthodes CRUD
    bool ajouter(const Pointage& pointage);
    bool modifier(const Pointage& pointage);
    bool supprimer(int id);
    Pointage* getById(int id);
    std::vector<Pointage> getAll();

    // Méthodes spécifiques
    bool enregistrerArrivee(int eleveId, const std::string& heure);
    bool enregistrerDepart(int eleveId, const std::string& heure);
    std::vector<Pointage> getPointagesEleve(int eleveId, const std::string& dateDebut, const std::string& dateFin);
    std::vector<Pointage> getRetardsEleve(int eleveId);
    int compterRetardsPeriode(int eleveId, const std::string& dateDebut, const std::string& dateFin);
    std::vector<Pointage> getPointagesJour(const std::string& date);
};

#endif

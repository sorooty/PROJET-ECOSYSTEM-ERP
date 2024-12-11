#ifndef RETARDDAO_HPP
#define RETARDDAO_HPP

#include "../models/Retard.hpp"
#include "../DatabaseConnection.hpp"
#include <vector>

class RetardDAO {
private:
    DatabaseConnection* db;

public:
    RetardDAO();

    // Méthodes CRUD adaptées
    bool ajouter(const Retard& retard);
    bool supprimer(int id);
    std::vector<Retard> getAll();
    
    // Méthodes spécifiques
    std::vector<Retard> getRetardsEleve(int eleveId);
    std::vector<Retard> getRetardsNonJustifies();
    bool justifierRetard(int retardId, const std::string& motif, int validateurId);
    int compterRetardsEleve(int eleveId, const std::string& dateDebut, const std::string& dateFin);
};

#endif 
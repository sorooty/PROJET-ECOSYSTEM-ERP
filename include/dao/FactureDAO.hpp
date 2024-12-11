#ifndef FACTUREDAO_HPP
#define FACTUREDAO_HPP

#include "../models/Facture.hpp"
#include "../DatabaseConnection.hpp"
#include <vector>

class FactureDAO {
private:
    DatabaseConnection* db;

public:
    FactureDAO();

    // Méthodes CRUD
    bool ajouter(const Facture& facture);
    bool modifier(const Facture& facture);
    bool supprimer(int id);
    Facture* getById(int id);
    std::vector<Facture> getAll();

    // Méthodes spécifiques
    std::vector<Facture> getFacturesEleve(int eleveId);
    std::vector<Facture> getFacturesImpayees();
    bool mettreAJourStatut(int factureId, const std::string& statut);
    double getTotalDu(int eleveId);
};

#endif 
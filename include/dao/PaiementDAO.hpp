#ifndef PAIEMENTDAO_HPP
#define PAIEMENTDAO_HPP

#include "../models/Paiement.hpp"
#include "../DatabaseConnection.hpp"
#include <vector>

class PaiementDAO {
private:
    DatabaseConnection* db;

public:
    PaiementDAO();

    // Méthodes CRUD
    bool ajouter(const Paiement& paiement);
    bool modifier(const Paiement& paiement);
    bool supprimer(int id);
    Paiement* getById(int id);
    std::vector<Paiement> getAll();

    // Méthodes spécifiques
    std::vector<Paiement> getPaiementsParFacture(int factureId);
    double getTotalPaiementsFacture(int factureId);
};

#endif 
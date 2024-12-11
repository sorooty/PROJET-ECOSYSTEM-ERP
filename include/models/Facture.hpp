#ifndef FACTURE_HPP
#define FACTURE_HPP

#include <string>

class Facture {
private:
    int id;
    int eleveId;
    double montantTotal;
    std::string dateEmission;
    std::string dateEcheance;
    std::string statut;  // 'payée', 'en attente', 'en retard'

public:
    Facture(int eleveId, double montantTotal, 
            const std::string& dateEmission, const std::string& dateEcheance);

    // Getters
    int getId() const { return id; }
    int getEleveId() const { return eleveId; }
    double getMontantTotal() const { return montantTotal; }
    std::string getDateEmission() const { return dateEmission; }
    std::string getDateEcheance() const { return dateEcheance; }
    std::string getStatut() const { return statut; }

    // Setters
    void setId(int id) { this->id = id; }
    void setStatut(const std::string& statut) { this->statut = statut; }

    // Validation
    bool estValide() const;
};

#endif 
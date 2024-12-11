#ifndef PAIEMENT_HPP
#define PAIEMENT_HPP

#include <string>

class Paiement {
private:
    int id;
    int factureId;
    double montant;
    std::string datePaiement;
    std::string methodePaiement;

public:
    Paiement(int factureId, double montant, 
             const std::string& datePaiement, const std::string& methodePaiement);

    // Getters
    int getId() const { return id; }
    int getFactureId() const { return factureId; }
    double getMontant() const { return montant; }
    std::string getDatePaiement() const { return datePaiement; }
    std::string getMethodePaiement() const { return methodePaiement; }

    // Setters
    void setId(int id) { this->id = id; }

    // Validation
    bool estValide() const;
};

#endif 
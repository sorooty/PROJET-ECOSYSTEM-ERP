#include "../../include/models/Paiement.hpp"

Paiement::Paiement(int factureId, double montant, 
                   const std::string& datePaiement, const std::string& methodePaiement)
    : factureId(factureId),
      montant(montant),
      datePaiement(datePaiement),
      methodePaiement(methodePaiement) {
    id = 0;
}

bool Paiement::estValide() const {
    return factureId > 0 && 
           montant > 0 && 
           !datePaiement.empty() && 
           !methodePaiement.empty();
}
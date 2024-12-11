#include "../../include/models/Facture.hpp"

Facture::Facture(int eleveId, double montantTotal, 
                 const std::string& dateEmission, const std::string& dateEcheance)
    : eleveId(eleveId),
      montantTotal(montantTotal),
      dateEmission(dateEmission),
      dateEcheance(dateEcheance) {
    id = 0;
    statut = "en attente";  // Statut par défaut
}

bool Facture::estValide() const {
    return eleveId > 0 && 
           montantTotal > 0 && 
           !dateEmission.empty() && 
           !dateEcheance.empty() &&
           (statut == "en attente" || 
            statut == "payée" || 
            statut == "en retard");
}
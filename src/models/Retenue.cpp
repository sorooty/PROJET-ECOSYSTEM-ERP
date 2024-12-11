#include "../../include/models/Retenue.hpp"

Retenue::Retenue(int eleveId, const std::string& dateRetenue,
                 const std::string& heureDebut, const std::string& heureFin)
    : eleveId(eleveId),
      dateRetenue(dateRetenue),
      heureDebut(heureDebut),
      heureFin(heureFin),
      statut("programmée")
{
    id = 0;
    professeurId = 0;
}

bool Retenue::estValide() const {
    return eleveId > 0 && 
           !dateRetenue.empty() && 
           !heureDebut.empty() && 
           !heureFin.empty() && 
           heureDebut < heureFin;
} 
#include "../../include/models/Retard.hpp"

Retard::Retard(int eleveId, const std::string& dateRetard,
               const std::string& heureArrivee, int dureeMinutes)
    : eleveId(eleveId),
      dateRetard(dateRetard),
      heureArrivee(heureArrivee),
      dureeMinutes(dureeMinutes),
      justifie(false)
{
    id = 0;
    validateurId = 0;
}

bool Retard::estValide() const {
    return eleveId > 0 && 
           !dateRetard.empty() && 
           !heureArrivee.empty() && 
           dureeMinutes > 0;
} 
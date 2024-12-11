#include "../../include/models/Pointage.hpp"

Pointage::Pointage(int eleveId, const std::string& datePointage)
    : eleveId(eleveId),
      datePointage(datePointage),
      statut("présent")
{
    id = 0;
    validateurId = 0;
}

bool Pointage::estValide() const {
    return eleveId > 0 && !datePointage.empty();
}

bool Pointage::estRetard() const {
    // Heure limite d'arrivée (par exemple 8h00)
    const std::string HEURE_LIMITE = "08:00:00";
    return !heureArrivee.empty() && heureArrivee > HEURE_LIMITE;
}

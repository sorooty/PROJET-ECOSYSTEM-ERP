#include "../../include/models/Absence.hpp"

Absence::Absence(int eleveId, const std::string& dateDebut, const std::string& dateFin)
    : eleveId(eleveId),
      dateDebut(dateDebut),
      dateFin(dateFin),
      justifie(false)
{
    id = 0;
}

bool Absence::estValide() const {
    return eleveId > 0 && 
           !dateDebut.empty() && 
           !dateFin.empty() && 
           dateDebut <= dateFin;
}

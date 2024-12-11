#include "../../include/models/Note.hpp"

Note::Note(int eleveId, int matiereId, int professeurId, double valeur,
           int coefficient, const std::string& type)
    : eleveId(eleveId),
      matiereId(matiereId),
      professeurId(professeurId),
      valeur(valeur),
      coefficient(coefficient),
      typeEvaluation(type)
{
    id = 0;
}

bool Note::estValide() const {
    return eleveId > 0 &&
           matiereId > 0 &&
           professeurId > 0 &&
           valeur >= 0 &&
           valeur <= 20 &&
           coefficient > 0;
}

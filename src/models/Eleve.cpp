#include "../../include/models/Eleve.hpp"

Eleve::Eleve(const std::string& nom, const std::string& prenom,
             const std::string& login, const std::string& motDePasse,
             const std::string& email, const std::string& dateNaissance)
    : Utilisateur(nom, prenom, login, motDePasse, email, "eleve"),
      dateNaissance(dateNaissance) {
    this->idEleve = 0;
    this->classeId = 0;
    this->parentId = 0;
}

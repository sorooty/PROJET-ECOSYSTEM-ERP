#ifndef ELEVE_HPP
#define ELEVE_HPP

#include "Utilisateur.hpp"
#include <string>

class Eleve : public Utilisateur {
private:
    int idEleve;
    int classeId;
    int parentId;
    std::string dateNaissance;
    std::string dateInscription;

public:
    Eleve(const std::string& nom, const std::string& prenom,
          const std::string& login, const std::string& motDePasse,
          const std::string& email, const std::string& dateNaissance);

    // Getters
    int getIdEleve() const { return idEleve; }
    int getClasseId() const { return classeId; }
    int getParentId() const { return parentId; }
    std::string getDateNaissance() const { return dateNaissance; }
    std::string getDateInscription() const { return dateInscription; }

    // Setters
    void setIdEleve(int id) { this->idEleve = id; }
    void setClasseId(int id) { this->classeId = id; }
    void setParentId(int id) { this->parentId = id; }
    void setDateInscription(const std::string& date) { this->dateInscription = date; }
};

#endif

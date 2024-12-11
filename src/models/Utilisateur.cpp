#include "../../include/models/Utilisateur.hpp"

// Constructeurs
Utilisateur::Utilisateur() : id(0), actif(true) {}

Utilisateur::Utilisateur(const std::string& nom, const std::string& prenom,
                        const std::string& login, const std::string& type)
    : id(0), nom(nom), prenom(prenom), login(login), type(type), actif(true) {}

// Getters
int Utilisateur::getId() const { return id; }
std::string Utilisateur::getNom() const { return nom; }
std::string Utilisateur::getPrenom() const { return prenom; }
std::string Utilisateur::getLogin() const { return login; }
std::string Utilisateur::getType() const { return type; }
std::string Utilisateur::getDateCreation() const { return dateCreation; }
bool Utilisateur::estActif() const { return actif; }
std::string Utilisateur::getNomComplet() const { return nom + " " + prenom; }

// Setters
void Utilisateur::setId(int id) { this->id = id; }
void Utilisateur::setNom(const std::string& nom) { this->nom = nom; }
void Utilisateur::setPrenom(const std::string& prenom) { this->prenom = prenom; }
void Utilisateur::setLogin(const std::string& login) { this->login = login; }
void Utilisateur::setType(const std::string& type) { this->type = type; }
void Utilisateur::setDateCreation(const std::string& date) { this->dateCreation = date; }
void Utilisateur::setActif(bool actif) { this->actif = actif; }

// Autres méthodes
bool Utilisateur::verifierDroits(const std::string& action) const {
    // Implémentation de la vérification des droits
    if (type == "admin") return true;
    // Ajoutez d'autres règles selon vos besoins
    return false;
}

bool Utilisateur::estValide() const {
    return !nom.empty() && !prenom.empty() && !login.empty() && !type.empty();
}

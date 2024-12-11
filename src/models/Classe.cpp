#include "../../include/models/Classe.hpp"

Classe::Classe(const std::string& nom, const std::string& niveau,
               const std::string& anneeScolaire)
    : nom(nom),
      niveau(niveau),
      anneeScolaire(anneeScolaire),
      capaciteMax(35)
{
    id = 0;
    professeurPrincipalId = 0;
}

// Getters
int Classe::getId() const { return id; }
std::string Classe::getNom() const { return nom; }
std::string Classe::getNiveau() const { return niveau; }
std::string Classe::getAnneeScolaire() const { return anneeScolaire; }
int Classe::getProfesseurPrincipalId() const { return professeurPrincipalId; }
int Classe::getCapaciteMax() const { return capaciteMax; }
std::string Classe::getSallePrincipale() const { return sallePrincipale; }
const std::vector<int>& Classe::getElevesIds() const { return elevesIds; }

// Setters
void Classe::setId(int id) { this->id = id; }
void Classe::setNom(const std::string& nom) { this->nom = nom; }
void Classe::setNiveau(const std::string& niveau) { this->niveau = niveau; }
void Classe::setAnneeScolaire(const std::string& annee) { this->anneeScolaire = annee; }
void Classe::setProfesseurPrincipalId(int id) { this->professeurPrincipalId = id; }
void Classe::setCapaciteMax(int capacite) { this->capaciteMax = capacite; }
void Classe::setSallePrincipale(const std::string& salle) { this->sallePrincipale = salle; }

// Méthodes de gestion des élèves
bool Classe::ajouterEleve(int eleveId) {
    if (estPleine()) return false;

    // Vérifier si l'élève n'est pas déjà dans la classe
    for (int id : elevesIds) {
        if (id == eleveId) return false;
    }

    elevesIds.push_back(eleveId);
    return true;
}

bool Classe::retirerEleve(int eleveId) {
    for (auto it = elevesIds.begin(); it != elevesIds.end(); ++it) {
        if (*it == eleveId) {
            elevesIds.erase(it);
            return true;
        }
    }
    return false;
}

bool Classe::estPleine() const {
    return elevesIds.size() >= static_cast<size_t>(capaciteMax);
}

int Classe::getNombreEleves() const {
    return elevesIds.size();
}

bool Classe::estValide() const {
    return !nom.empty() &&
           !niveau.empty() &&
           !anneeScolaire.empty() &&
           capaciteMax > 0;
}

std::string Classe::toString() const {
    return nom + " (" + niveau + ") - " + anneeScolaire;
}

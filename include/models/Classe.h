#ifndef CLASSE_HPP
#define CLASSE_HPP

#include <string>
#include <vector>
#include "Utilisateur.hpp"

class Classe {
private:
    int id;
    std::string nom;
    std::string niveau;
    std::string anneeScolaire;
    int professeurPrincipalId;
    std::vector<int> elevesIds;

public:
    Classe(const std::string& nom, const std::string& niveau,
           const std::string& anneeScolaire);

    // Getters
    int getId() const { return id; }
    std::string getNom() const { return nom; }
    std::string getNiveau() const { return niveau; }
    std::string getAnneeScolaire() const { return anneeScolaire; }
    int getProfesseurPrincipalId() const { return professeurPrincipalId; }

    // Setters
    void setId(int id) { this->id = id; }
    void setNom(const std::string& nom) { this->nom = nom; }
    void setNiveau(const std::string& niveau) { this->niveau = niveau; }
    void setAnneeScolaire(const std::string& annee) { this->anneeScolaire = annee; }
    void setProfesseurPrincipalId(int id) { this->professeurPrincipalId = id; }

    // Méthodes spécifiques
    bool ajouterEleve(int eleveId);
    bool retirerEleve(int eleveId);
    const std::vector<int>& getEleves() const { return elevesIds; }
};

#endif

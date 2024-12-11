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
    int capaciteMax;
    std::string sallePrincipale;
    std::vector<int> elevesIds;

public:
    // Constructeur
    Classe(const std::string& nom, const std::string& niveau,
           const std::string& anneeScolaire);

    // Getters
    int getId() const;
    std::string getNom() const;
    std::string getNiveau() const;
    std::string getAnneeScolaire() const;
    int getProfesseurPrincipalId() const;
    int getCapaciteMax() const;
    std::string getSallePrincipale() const;
    const std::vector<int>& getElevesIds() const;

    // Setters
    void setId(int id);
    void setNom(const std::string& nom);
    void setNiveau(const std::string& niveau);
    void setAnneeScolaire(const std::string& annee);
    void setProfesseurPrincipalId(int id);
    void setCapaciteMax(int capacite);
    void setSallePrincipale(const std::string& salle);

    // Méthodes de gestion des élèves
    bool ajouterEleve(int eleveId);
    bool retirerEleve(int eleveId);
    bool estPleine() const;
    int getNombreEleves() const;

    // Méthodes de validation
    bool estValide() const;
    std::string toString() const;
};

#endif

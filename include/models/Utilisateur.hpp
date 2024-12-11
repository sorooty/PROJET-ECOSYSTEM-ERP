#ifndef UTILISATEUR_HPP
#define UTILISATEUR_HPP

#include <string>

class Utilisateur {
private:
    int id;
    std::string nom;
    std::string prenom;
    std::string login;
    std::string type;
    std::string dateCreation;  // Ajout du champ dateCreation
    bool actif;

public:
    // Constructeurs
    Utilisateur();
    Utilisateur(const std::string& nom, const std::string& prenom,
                const std::string& login, const std::string& type);

    // Getters - déclaration seulement, pas d'implémentation ici
    int getId() const;
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getLogin() const;
    std::string getType() const;
    std::string getDateCreation() const;  // Ajout du getter
    bool estActif() const;
    std::string getNomComplet() const;

    // Setters - déclaration seulement, pas d'implémentation ici
    void setId(int id);
    void setNom(const std::string& nom);
    void setPrenom(const std::string& prenom);
    void setLogin(const std::string& login);
    void setType(const std::string& type);
    void setDateCreation(const std::string& date);  // Ajout du setter
    void setActif(bool actif);

    // Autres méthodes
    bool verifierDroits(const std::string& action) const;
    bool estValide() const;
};

#endif // UTILISATEUR_HPP

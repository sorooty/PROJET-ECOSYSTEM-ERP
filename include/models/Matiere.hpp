#ifndef MATIERE_HPP
#define MATIERE_HPP

#include <string>
#include <vector>

class Matiere {
private:
    int id;
    std::string nom;
    std::string description;
    int coefficient;
    int volumeHoraire;

public:
    // Constructeur
    Matiere(const std::string& nom, const std::string& description = "",
            int coefficient = 1, int volumeHoraire = 0);

    // Getters
    int getId() const;
    std::string getNom() const;
    std::string getDescription() const;
    int getCoefficient() const;
    int getVolumeHoraire() const;

    // Setters
    void setId(int id);
    void setNom(const std::string& nom);
    void setDescription(const std::string& description);
    void setCoefficient(int coefficient);
    void setVolumeHoraire(int volume);

    // Méthodes de validation
    bool estValide() const;
    std::string toString() const;
};

#endif

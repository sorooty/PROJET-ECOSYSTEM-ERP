// include/models/Enseignement.hpp
#ifndef ENSEIGNEMENT_HPP
#define ENSEIGNEMENT_HPP

#include <string>

class Enseignement {
private:
    int id;
    int professeurId;
    int matiereId;
    int classeId;

public:
    // Constructeur
    Enseignement(int professeurId, int matiereId, int classeId);

    // Getters
    int getId() const;
    int getProfesseurId() const;
    int getMatiereId() const;
    int getClasseId() const;

    // Setters
    void setId(int newId);
    void setProfesseurId(int newProfesseurId);
    void setMatiereId(int newMatiereId);
    void setClasseId(int newClasseId);

    // Méthodes utilitaires
    bool estValide() const;
    std::string toString() const;
};

#endif

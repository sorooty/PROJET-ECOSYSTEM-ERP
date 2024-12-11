 // include/models/Reunion.hpp
#ifndef REUNION_HPP
#define REUNION_HPP

#include <string>
#include <vector>

class Reunion {
private:
    int id;
    std::string titre;
    std::string dateReunion;
    std::string heureDebut;
    std::string heureFin;
    std::string typeReunion;
    std::string salle;
    std::string description;
    int organisateurId;
    std::vector<int> participants;

public:
    // Constructeur
    Reunion(const std::string& titre, const std::string& dateReunion,
           const std::string& heureDebut, const std::string& heureFin,
           const std::string& typeReunion);

    // Getters
    int getId() const { return id; }
    std::string getTitre() const { return titre; }
    std::string getDateReunion() const { return dateReunion; }
    // ... autres getters

    // Setters
    void setId(int id) { this->id = id; }
    void setSalle(const std::string& salle) { this->salle = salle; }
    // ... autres setters

    // Méthodes de gestion des participants
    void ajouterParticipant(int participantId);
    void retirerParticipant(int participantId);
    const std::vector<int>& getParticipants() const { return participants; }

    // Validation
    bool estValide() const;
};

#endif
#ifndef POINTAGE_HPP
#define POINTAGE_HPP

#include <string>

class Pointage {
private:
    int id;
    int eleveId;
    std::string datePointage;
    std::string heureArrivee;
    std::string heureDepart;
    std::string statut;
    std::string commentaire;
    int validateurId;

public:
    Pointage(int eleveId, const std::string& datePointage);

    // Getters
    int getId() const { return id; }
    int getEleveId() const { return eleveId; }
    std::string getDatePointage() const { return datePointage; }
    std::string getHeureArrivee() const { return heureArrivee; }
    std::string getHeureDepart() const { return heureDepart; }
    std::string getStatut() const { return statut; }
    std::string getCommentaire() const { return commentaire; }
    int getValidateurId() const { return validateurId; }

    // Setters
    void setId(int id) { this->id = id; }
    void setHeureArrivee(const std::string& heure) { this->heureArrivee = heure; }
    void setHeureDepart(const std::string& heure) { this->heureDepart = heure; }
    void setStatut(const std::string& statut) { this->statut = statut; }
    void setCommentaire(const std::string& commentaire) { this->commentaire = commentaire; }
    void setValidateurId(int id) { this->validateurId = id; }

    // Méthodes de validation
    bool estValide() const;
    bool estRetard() const;
};

#endif

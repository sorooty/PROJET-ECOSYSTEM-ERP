#ifndef RETENUE_HPP
#define RETENUE_HPP

#include <string>

class Retenue {
private:
    int id;
    int eleveId;
    std::string dateRetenue;
    std::string heureDebut;
    std::string heureFin;
    std::string motif;
    int professeurId;
    std::string statut;  // programmée, effectuée, annulée
    std::string commentaire;

public:
    Retenue(int eleveId, const std::string& dateRetenue,
            const std::string& heureDebut, const std::string& heureFin);

    // Getters
    int getId() const { return id; }
    int getEleveId() const { return eleveId; }
    std::string getDateRetenue() const { return dateRetenue; }
    std::string getHeureDebut() const { return heureDebut; }
    std::string getHeureFin() const { return heureFin; }
    std::string getMotif() const { return motif; }
    int getProfesseurId() const { return professeurId; }
    std::string getStatut() const { return statut; }
    std::string getCommentaire() const { return commentaire; }

    // Setters
    void setId(int id) { this->id = id; }
    void setMotif(const std::string& motif) { this->motif = motif; }
    void setProfesseurId(int id) { this->professeurId = id; }
    void setStatut(const std::string& statut) { this->statut = statut; }
    void setCommentaire(const std::string& commentaire) { this->commentaire = commentaire; }

    // Validation
    bool estValide() const;
};

#endif 
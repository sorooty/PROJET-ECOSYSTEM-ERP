// include/models/Communication.hpp
#ifndef COMMUNICATION_HPP
#define COMMUNICATION_HPP

#include <string>
#include <vector>

class Communication {
private:
    int id;
    std::string type;        // 'annonce', 'message', 'notification'
    std::string titre;
    std::string contenu;
    std::string dateEnvoi;
    int expediteurId;
    std::string importance;  // 'normale', 'importante', 'urgente'
    std::string pieceJointe;
    std::vector<int> destinataires;

public:
    Communication(const std::string& type, const std::string& titre,
                 const std::string& contenu, int expediteurId);

    // Getters
    int getId() const { return id; }
    std::string getType() const { return type; }
    std::string getTitre() const { return titre; }
    std::string getContenu() const { return contenu; }
    std::string getDateEnvoi() const { return dateEnvoi; }
    int getExpediteurId() const { return expediteurId; }
    std::string getImportance() const { return importance; }
    std::string getPieceJointe() const { return pieceJointe; }
    const std::vector<int>& getDestinataires() const { return destinataires; }

    // Setters
    void setId(int id) { this->id = id; }
    void setImportance(const std::string& importance) { this->importance = importance; }
    void setPieceJointe(const std::string& pieceJointe) { this->pieceJointe = pieceJointe; }
    void setDateEnvoi(const std::string& dateEnvoi) { this->dateEnvoi = dateEnvoi; }

    // Gestion des destinataires
    void ajouterDestinataire(int destinataireId);
    void retirerDestinataire(int destinataireId);

    // Validation
    bool estValide() const;
};

#endif

// include/dao/CommunicationDAO.hpp
#ifndef COMMUNICATIONDAO_HPP
#define COMMUNICATIONDAO_HPP

#include "../models/Communication.hpp"
#include "../DatabaseConnection.hpp"
#include <vector>

class CommunicationDAO {
private:
    DatabaseConnection* db;

public:
    CommunicationDAO();

    // Méthodes CRUD
    bool ajouter(const Communication& communication);
    bool modifier(const Communication& communication);
    bool supprimer(int id);
    Communication* getById(int id);
    std::vector<Communication> getAll();

    // Méthodes spécifiques
    bool marquerCommeLue(int communicationId, int utilisateurId);
    std::vector<Communication> getCommunicationsNonLues(int utilisateurId);
    std::vector<Communication> getCommunicationsParType(const std::string& type);
    std::vector<Communication> getCommunicationsParImportance(const std::string& importance);
    bool ajouterDestinataire(int communicationId, int destinataireId);
    std::vector<int> getDestinataires(int communicationId);
};

#endif

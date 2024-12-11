// include/dao/EnseignementDAO.hpp
#ifndef ENSEIGNEMENTDAO_HPP
#define ENSEIGNEMENTDAO_HPP

#include "../models/Enseignement.hpp"
#include "../DatabaseConnection.hpp"
#include <vector>

class EnseignementDAO {
private:
    DatabaseConnection* db;

public:
    EnseignementDAO();

    bool ajouter(const Enseignement& enseignement);
    bool supprimer(int id);
    std::vector<Enseignement> getByProfesseur(int professeurId);
    std::vector<Enseignement> getByClasse(int classeId);
    std::vector<Enseignement> getByMatiere(int matiereId);
    bool existe(int professeurId, int matiereId, int classeId);
};

#endif
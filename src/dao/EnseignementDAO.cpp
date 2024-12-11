// src/dao/EnseignementDAO.cpp
#include "../../include/dao/EnseignementDAO.hpp"
#include <sstream>

EnseignementDAO::EnseignementDAO() {
    db = DatabaseConnection::getInstance();
}

bool EnseignementDAO::ajouter(const Enseignement& enseignement) {
    if (!enseignement.estValide()) return false;

    // Vérifier si l'enseignement existe déjà
    if (existe(enseignement.getProfesseurId(),
              enseignement.getMatiereId(),
              enseignement.getClasseId())) {
        return false;
    }

    std::stringstream ss;
    ss << "INSERT INTO enseignements (id_professeur, id_matiere, id_classe) "
       << "VALUES (" << enseignement.getProfesseurId() << ", "
       << enseignement.getMatiereId() << ", "
       << enseignement.getClasseId() << ")";

    return db->executeQuery(ss.str());
}

bool EnseignementDAO::existe(int professeurId, int matiereId, int classeId) {
    std::stringstream ss;
    ss << "SELECT COUNT(*) FROM enseignements WHERE "
       << "id_professeur = " << professeurId << " AND "
       << "id_matiere = " << matiereId << " AND "
       << "id_classe = " << classeId;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row = mysql_fetch_row(result);
            int count = std::stoi(row[0]);
            mysql_free_result(result);
            return count > 0;
        }
    }
    return false;
}

bool EnseignementDAO::supprimer(int id) {
    std::stringstream ss;
    ss << "DELETE FROM enseignements WHERE id_enseignement = " << id;
    return db->executeQuery(ss.str());
}



std::vector<Enseignement> EnseignementDAO::getByProfesseur(int professeurId) {
    std::vector<Enseignement> enseignements;
    std::stringstream ss;
    ss << "SELECT * FROM enseignements WHERE id_professeur = " << professeurId;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Enseignement ens(
                    std::stoi(row[1]), // professeurId
                    std::stoi(row[2]), // matiereId
                    std::stoi(row[3])  // classeId
                );
                ens.setId(std::stoi(row[0]));
                enseignements.push_back(ens);
            }
            mysql_free_result(result);
        }
    }
    return enseignements;
}

std::vector<Enseignement> EnseignementDAO::getByClasse(int classeId) {
    std::vector<Enseignement> enseignements;
    std::stringstream ss;
    ss << "SELECT * FROM enseignements WHERE id_classe = " << classeId;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Enseignement ens(
                    std::stoi(row[1]), // professeurId
                    std::stoi(row[2]), // matiereId
                    std::stoi(row[3])  // classeId
                );
                ens.setId(std::stoi(row[0]));
                enseignements.push_back(ens);
            }
            mysql_free_result(result);
        }
    }
    return enseignements;
}

std::vector<Enseignement> EnseignementDAO::getByMatiere(int matiereId) {
    std::vector<Enseignement> enseignements;
    std::stringstream ss;
    ss << "SELECT * FROM enseignements WHERE id_matiere = " << matiereId;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Enseignement ens(
                    std::stoi(row[1]), // professeurId
                    std::stoi(row[2]), // matiereId
                    std::stoi(row[3])  // classeId
                );
                ens.setId(std::stoi(row[0]));
                enseignements.push_back(ens);
            }
            mysql_free_result(result);
        }
    }
    return enseignements;
}

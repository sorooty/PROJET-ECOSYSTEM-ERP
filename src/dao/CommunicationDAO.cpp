// src/dao/CommunicationDAO.cpp
#include "../../include/dao/CommunicationDAO.hpp"
#include <sstream>

CommunicationDAO::CommunicationDAO() {
    db = DatabaseConnection::getInstance();
}

bool CommunicationDAO::ajouter(const Communication& communication) {
    if (!communication.estValide()) return false;

    std::stringstream ss;
    ss << "INSERT INTO communications (type_communication, titre, contenu, "
       << "expediteur_id, importance, piece_jointe) VALUES ('"
       << communication.getType() << "', '"
       << communication.getTitre() << "', '"
       << communication.getContenu() << "', "
       << communication.getExpediteurId() << ", '"
       << communication.getImportance() << "', '"
       << communication.getPieceJointe() << "')";

    return db->executeQuery(ss.str());
}

bool CommunicationDAO::supprimer(int id) {
    std::stringstream ss;
    ss << "DELETE FROM communications WHERE id_communication = " << id;
    return db->executeQuery(ss.str());
}

std::vector<Communication> CommunicationDAO::getAll() {
    std::vector<Communication> communications;
    std::string query = "SELECT * FROM communications ORDER BY date_envoi DESC";

    if (db->executeQuery(query)) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Communication comm(
                    row[1],  // type
                    row[2],  // titre
                    row[3],  // contenu
                    std::stoi(row[5])  // expediteur_id
                );
                comm.setId(std::stoi(row[0]));
                comm.setDateEnvoi(row[4]);
                comm.setImportance(row[6]);
                if (row[7]) comm.setPieceJointe(row[7]);

                communications.push_back(comm);
            }
            mysql_free_result(result);
        }
    }
    return communications;
}

std::vector<Communication> CommunicationDAO::getCommunicationsNonLues(int utilisateurId) {
    std::vector<Communication> communications;
    std::stringstream ss;
    ss << "SELECT c.* FROM communications c "
       << "INNER JOIN destinataires_communication dc "
       << "ON c.id_communication = dc.id_communication "
       << "WHERE dc.id_utilisateur = " << utilisateurId
       << " AND dc.lu = FALSE";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Communication comm(
                    row[1], row[2], row[3], std::stoi(row[5])
                );
                comm.setId(std::stoi(row[0]));
                comm.setDateEnvoi(row[4]);
                comm.setImportance(row[6]);
                if (row[7]) comm.setPieceJointe(row[7]);

                communications.push_back(comm);
            }
            mysql_free_result(result);
        }
    }
    return communications;
}

bool CommunicationDAO::marquerCommeLue(int communicationId, int utilisateurId) {
    std::stringstream ss;
    ss << "UPDATE destinataires_communication SET "
       << "lu = TRUE, date_lecture = CURRENT_TIMESTAMP "
       << "WHERE id_communication = " << communicationId
       << " AND id_utilisateur = " << utilisateurId;

    return db->executeQuery(ss.str());
}

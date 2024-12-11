// src/dao/ReunionDAO.cpp
#include "../../include/dao/ReunionDAO.hpp"
#include <sstream>

ReunionDAO::ReunionDAO() {
    db = DatabaseConnection::getInstance();
}

bool ReunionDAO::ajouter(const Reunion& reunion) {
    if (!reunion.estValide()) return false;

    std::stringstream ss;
    ss << "INSERT INTO reunions (titre, date_reunion, heure_debut, "
       << "heure_fin, type_reunion, salle, description, organisateur_id) VALUES ('"
       << reunion.getTitre() << "', '"
       << reunion.getDateReunion() << "', '"
       << reunion.getHeureDebut() << "', '"
       << reunion.getHeureFin() << "', '"
       << reunion.getTypeReunion() << "', '"
       << reunion.getSalle() << "', '"
       << reunion.getDescription() << "', "
       << reunion.getOrganisateurId() << ")";

    if (!db->executeQuery(ss.str())) return false;

    // Ajouter les participants
    for (int participantId : reunion.getParticipants()) {
        if (!ajouterParticipant(reunion.getId(), participantId)) {
            return false;
        }
    }

    return true;
}

bool ReunionDAO::modifier(const Reunion& reunion) {
    if (!reunion.estValide()) return false;

    std::stringstream ss;
    ss << "UPDATE reunions SET "
       << "titre = '" << reunion.getTitre() << "', "
       << "date_reunion = '" << reunion.getDateReunion() << "', "
       << "heure_debut = '" << reunion.getHeureDebut() << "', "
       << "heure_fin = '" << reunion.getHeureFin() << "', "
       << "type_reunion = '" << reunion.getTypeReunion() << "', "
       << "salle = '" << reunion.getSalle() << "', "
       << "description = '" << reunion.getDescription() << "', "
       << "organisateur_id = " << reunion.getOrganisateurId()
       << " WHERE id_reunion = " << reunion.getId();

    return db->executeQuery(ss.str());
}

bool ReunionDAO::supprimer(int id) {
    // Supprimer d'abord les participants
    std::stringstream ss1;
    ss1 << "DELETE FROM participants_reunion WHERE id_reunion = " << id;
    if (!db->executeQuery(ss1.str())) return false;

    // Puis supprimer la réunion
    std::stringstream ss2;
    ss2 << "DELETE FROM reunions WHERE id_reunion = " << id;
    return db->executeQuery(ss2.str());
}

Reunion* ReunionDAO::getById(int id) {
    std::stringstream ss;
    ss << "SELECT * FROM reunions WHERE id_reunion = " << id;

    MYSQL_RES* result = db->getResult();
    if (result) {
        MYSQL_ROW row = mysql_fetch_row(result);
        if (row) {
            Reunion* reunion = new Reunion(
                row[1],  // titre
                row[2],  // date_reunion
                row[3],  // heure_debut
                row[4],  // heure_fin
                row[5]   // type_reunion
            );
            reunion->setId(std::stoi(row[0]));
            reunion->setSalle(row[6]);
            reunion->setDescription(row[7]);
            reunion->setOrganisateurId(std::stoi(row[8]));

            // Charger les participants
            std::vector<int> participants = getParticipants(id);
            for (int participantId : participants) {
                reunion->ajouterParticipant(participantId);
            }

            mysql_free_result(result);
            return reunion;
        }
        mysql_free_result(result);
    }
    return nullptr;
}

std::vector<Reunion> ReunionDAO::getAll() {
    std::vector<Reunion> reunions;
    std::string query = "SELECT * FROM reunions";

    if (db->executeQuery(query)) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Reunion reunion(
                    row[1],  // titre
                    row[2],  // date_reunion
                    row[3],  // heure_debut
                    row[4],  // heure_fin
                    row[5]   // type_reunion
                );
                reunion.setId(std::stoi(row[0]));
                reunion.setSalle(row[6]);
                reunion.setDescription(row[7]);
                reunion.setOrganisateurId(std::stoi(row[8]));

                // Charger les participants
                std::vector<int> participants = getParticipants(reunion.getId());
                for (int participantId : participants) {
                    reunion.ajouterParticipant(participantId);
                }

                reunions.push_back(reunion);
            }
            mysql_free_result(result);
        }
    }
    return reunions;
}

bool ReunionDAO::ajouterParticipant(int reunionId, int participantId) {
    std::stringstream ss;
    ss << "INSERT INTO participants_reunion (id_reunion, id_participant) VALUES ("
       << reunionId << ", " << participantId << ")";
    return db->executeQuery(ss.str());
}

std::vector<int> ReunionDAO::getParticipants(int reunionId) {
    std::vector<int> participants;
    std::stringstream ss;
    ss << "SELECT id_participant FROM participants_reunion WHERE id_reunion = " << reunionId;

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                participants.push_back(std::stoi(row[0]));
            }
            mysql_free_result(result);
        }
    }
    return participants;
}

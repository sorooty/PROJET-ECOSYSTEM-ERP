#include "../../include/dao/RetenueDAO.hpp"
#include <sstream>

RetenueDAO::RetenueDAO() {
    db = DatabaseConnection::getInstance();
}

bool RetenueDAO::ajouter(const Retenue& retenue) {
    if (!retenue.estValide()) return false;

    std::stringstream ss;
    ss << "INSERT INTO retenues (id_eleve, date_retenue, heure_debut, "
       << "heure_fin, motif, id_professeur, statut, commentaire) VALUES ("
       << retenue.getEleveId() << ", '"
       << retenue.getDateRetenue() << "', '"
       << retenue.getHeureDebut() << "', '"
       << retenue.getHeureFin() << "', "
       << (retenue.getMotif().empty() ? "NULL" : "'" + retenue.getMotif() + "'") << ", "
       << retenue.getProfesseurId() << ", '"
       << retenue.getStatut() << "', "
       << (retenue.getCommentaire().empty() ? "NULL" : "'" + retenue.getCommentaire() + "'")
       << ")";

    return db->executeQuery(ss.str());
}

bool RetenueDAO::modifier(const Retenue& retenue) {
    if (!retenue.estValide()) return false;

    std::stringstream ss;
    ss << "UPDATE retenues SET "
       << "date_retenue = '" << retenue.getDateRetenue() << "', "
       << "heure_debut = '" << retenue.getHeureDebut() << "', "
       << "heure_fin = '" << retenue.getHeureFin() << "', "
       << "motif = " << (retenue.getMotif().empty() ? "NULL" : "'" + retenue.getMotif() + "'") << ", "
       << "id_professeur = " << retenue.getProfesseurId() << ", "
       << "statut = '" << retenue.getStatut() << "', "
       << "commentaire = " << (retenue.getCommentaire().empty() ? "NULL" : "'" + retenue.getCommentaire() + "'")
       << " WHERE id_retenue = " << retenue.getId();

    return db->executeQuery(ss.str());
}

bool RetenueDAO::supprimer(int id) {
    std::stringstream ss;
    ss << "DELETE FROM retenues WHERE id_retenue = " << id;
    return db->executeQuery(ss.str());
}

std::vector<Retenue> RetenueDAO::getAll() {
    std::vector<Retenue> retenues;
    
    if (db->executeQuery("SELECT * FROM retenues")) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Retenue retenue(
                    std::stoi(row[1]),  // eleveId
                    row[2],             // dateRetenue
                    row[3],             // heureDebut
                    row[4]              // heureFin
                );
                retenue.setId(std::stoi(row[0]));
                if (row[5]) retenue.setMotif(row[5]);
                if (row[6]) retenue.setProfesseurId(std::stoi(row[6]));
                if (row[7]) retenue.setStatut(row[7]);
                if (row[8]) retenue.setCommentaire(row[8]);
                
                retenues.push_back(retenue);
            }
            mysql_free_result(result);
        }
    }
    return retenues;
}

std::vector<Retenue> RetenueDAO::getRetenuesEleve(int eleveId) {
    std::vector<Retenue> retenues;
    std::stringstream ss;
    
    ss << "SELECT * FROM retenues WHERE id_eleve = " << eleveId
       << " ORDER BY date_retenue DESC, heure_debut DESC";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Retenue retenue(
                    std::stoi(row[1]),
                    row[2],
                    row[3],
                    row[4]
                );
                retenue.setId(std::stoi(row[0]));
                if (row[5]) retenue.setMotif(row[5]);
                if (row[6]) retenue.setProfesseurId(std::stoi(row[6]));
                if (row[7]) retenue.setStatut(row[7]);
                if (row[8]) retenue.setCommentaire(row[8]);
                
                retenues.push_back(retenue);
            }
            mysql_free_result(result);
        }
    }
    return retenues;
}

bool RetenueDAO::marquerEffectuee(int retenueId) {
    std::stringstream ss;
    ss << "UPDATE retenues SET statut = 'effectuée' "
       << "WHERE id_retenue = " << retenueId;
    
    return db->executeQuery(ss.str());
}

bool RetenueDAO::marquerAnnulee(int retenueId, const std::string& motif) {
    std::stringstream ss;
    ss << "UPDATE retenues SET statut = 'annulée', "
       << "commentaire = '" << motif << "' "
       << "WHERE id_retenue = " << retenueId;
    
    return db->executeQuery(ss.str());
}

// Les autres méthodes seront implémentées selon les besoins 
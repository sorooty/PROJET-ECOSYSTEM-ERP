#include "../../include/dao/RetardDAO.hpp"
#include <sstream>

RetardDAO::RetardDAO() {
    db = DatabaseConnection::getInstance();
}

bool RetardDAO::ajouter(const Retard& retard) {
    if (!retard.estValide()) return false;

    std::stringstream ss;
    ss << "INSERT INTO retards (id_eleve, date_retard, heure_arrivee, "
       << "duree_retard, justifie, motif, id_validateur) VALUES ("
       << retard.getEleveId() << ", '"
       << retard.getDateRetard() << "', '"
       << retard.getHeureArrivee() << "', "
       << retard.getDureeMinutes() << ", "
       << (retard.estJustifie() ? "1" : "0") << ", "
       << (retard.getMotif().empty() ? "NULL" : "'" + retard.getMotif() + "'") << ", "
       << (retard.getValidateurId() > 0 ? std::to_string(retard.getValidateurId()) : "NULL")
       << ")";

    return db->executeQuery(ss.str());
}

bool RetardDAO::supprimer(int id) {
    std::stringstream ss;
    ss << "DELETE FROM retards WHERE id_retard = " << id;
    return db->executeQuery(ss.str());
}

std::vector<Retard> RetardDAO::getAll() {
    std::vector<Retard> retards;
    
    if (db->executeQuery("SELECT * FROM retards")) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Retard retard(
                    std::stoi(row[1]),  // eleveId
                    row[2],             // dateRetard
                    row[3],             // heureArrivee
                    std::stoi(row[4])   // dureeMinutes
                );
                retard.setId(std::stoi(row[0]));
                retard.setJustifie(row[5] != nullptr && std::string(row[5]) == "1");
                if (row[6]) retard.setMotif(row[6]);
                if (row[7]) retard.setValidateurId(std::stoi(row[7]));
                
                retards.push_back(retard);
            }
            mysql_free_result(result);
        }
    }
    return retards;
}

std::vector<Retard> RetardDAO::getRetardsEleve(int eleveId) {
    std::vector<Retard> retards;
    std::stringstream ss;
    
    ss << "SELECT * FROM retards WHERE id_eleve = " << eleveId
       << " ORDER BY date_retard DESC, heure_arrivee DESC";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Retard retard(
                    std::stoi(row[1]),
                    row[2],
                    row[3],
                    std::stoi(row[4])
                );
                retard.setId(std::stoi(row[0]));
                retard.setJustifie(row[5] != nullptr && std::string(row[5]) == "1");
                if (row[6]) retard.setMotif(row[6]);
                if (row[7]) retard.setValidateurId(std::stoi(row[7]));
                
                retards.push_back(retard);
            }
            mysql_free_result(result);
        }
    }
    return retards;
}

bool RetardDAO::justifierRetard(int retardId, const std::string& motif, int validateurId) {
    std::stringstream ss;
    ss << "UPDATE retards SET justifie = 1, motif = '" << motif 
       << "', id_validateur = " << validateurId
       << " WHERE id_retard = " << retardId;
    
    return db->executeQuery(ss.str());
}

int RetardDAO::compterRetardsEleve(int eleveId, const std::string& dateDebut, const std::string& dateFin) {
    std::stringstream ss;
    ss << "SELECT COUNT(*) FROM retards WHERE id_eleve = " << eleveId
       << " AND date_retard >= '" << dateDebut << "'"
       << " AND date_retard <= '" << dateFin << "'";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row = mysql_fetch_row(result);
            if (row) {
                int count = std::stoi(row[0]);
                mysql_free_result(result);
                return count;
            }
            mysql_free_result(result);
        }
    }
    return 0;
} 
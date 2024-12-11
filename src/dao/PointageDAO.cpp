#include "../../include/dao/PointageDAO.hpp"
#include <sstream>

PointageDAO::PointageDAO() {
    db = DatabaseConnection::getInstance();
}

bool PointageDAO::ajouter(const Pointage& pointage) {
    std::stringstream ss;
    ss << "INSERT INTO pointage (id_eleve, date_pointage, heure_arrivee, "
       << "heure_depart, statut, commentaire, validateur_id) VALUES ("
       << pointage.getEleveId() << ", '"
       << pointage.getDatePointage() << "', "
       << (pointage.getHeureArrivee().empty() ? "NULL" : "'" + pointage.getHeureArrivee() + "'") << ", "
       << (pointage.getHeureDepart().empty() ? "NULL" : "'" + pointage.getHeureDepart() + "'") << ", '"
       << pointage.getStatut() << "', "
       << (pointage.getCommentaire().empty() ? "NULL" : "'" + pointage.getCommentaire() + "'") << ", "
       << pointage.getValidateurId() << ")";

    return db->executeQuery(ss.str());
}

bool PointageDAO::enregistrerArrivee(int eleveId, const std::string& heure) {
    std::stringstream ss;
    ss << "INSERT INTO pointage (id_eleve, date_pointage, heure_arrivee, statut) VALUES ("
       << eleveId << ", CURRENT_DATE(), '" << heure << "', 'présent')";

    return db->executeQuery(ss.str());
}

bool PointageDAO::enregistrerDepart(int eleveId, const std::string& heure) {
    std::stringstream ss;
    ss << "UPDATE pointage SET heure_depart = '" << heure << "' "
       << "WHERE id_eleve = " << eleveId 
       << " AND date_pointage = CURRENT_DATE() "
       << "AND heure_depart IS NULL";

    return db->executeQuery(ss.str());
}

std::vector<Pointage> PointageDAO::getPointagesEleve(int eleveId,
    const std::string& dateDebut, const std::string& dateFin) {

    std::vector<Pointage> pointages;
    std::stringstream ss;

    ss << "SELECT * FROM pointage WHERE id_eleve = " << eleveId
       << " AND date_pointage BETWEEN '" << dateDebut << "' AND '" << dateFin << "' "
       << "ORDER BY date_pointage DESC";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Pointage pointage(std::stoi(row[1]), row[2]);
                pointage.setId(std::stoi(row[0]));
                if (row[3]) pointage.setHeureArrivee(row[3]);
                if (row[4]) pointage.setHeureDepart(row[4]);
                pointage.setStatut(row[5]);
                if (row[6]) pointage.setCommentaire(row[6]);
                if (row[7]) pointage.setValidateurId(std::stoi(row[7]));

                pointages.push_back(pointage);
            }
            mysql_free_result(result);
        }
    }
    return pointages;
}

std::vector<Pointage> PointageDAO::getPointagesJour(const std::string& date) {
    std::vector<Pointage> pointages;
    std::stringstream ss;
    
    ss << "SELECT * FROM pointage WHERE date_pointage = '" << date << "' "
       << "ORDER BY heure_arrivee";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Pointage pointage(std::stoi(row[1]), row[2]);
                pointage.setId(std::stoi(row[0]));
                if (row[3]) pointage.setHeureArrivee(row[3]);
                if (row[4]) pointage.setHeureDepart(row[4]);
                pointage.setStatut(row[5]);
                if (row[6]) pointage.setCommentaire(row[6]);
                if (row[7]) pointage.setValidateurId(std::stoi(row[7]));
                
                pointages.push_back(pointage);
            }
            mysql_free_result(result);
        }
    }
    return pointages;
}

std::vector<Pointage> PointageDAO::getRetardsEleve(int eleveId) {
    std::vector<Pointage> retards;
    std::stringstream ss;
    
    ss << "SELECT * FROM pointage WHERE id_eleve = " << eleveId 
       << " AND TIME(heure_arrivee) > '08:00:00' "  // Heure limite configurable
       << "ORDER BY date_pointage DESC";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Pointage pointage(std::stoi(row[1]), row[2]);
                pointage.setId(std::stoi(row[0]));
                if (row[3]) pointage.setHeureArrivee(row[3]);
                if (row[4]) pointage.setHeureDepart(row[4]);
                pointage.setStatut(row[5]);
                if (row[6]) pointage.setCommentaire(row[6]);
                if (row[7]) pointage.setValidateurId(std::stoi(row[7]));
                
                retards.push_back(pointage);
            }
            mysql_free_result(result);
        }
    }
    return retards;
}

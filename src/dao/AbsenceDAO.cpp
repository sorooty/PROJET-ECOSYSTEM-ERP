#include "../../include/dao/AbsenceDAO.hpp"
#include <sstream>

AbsenceDAO::AbsenceDAO() {
    db = DatabaseConnection::getInstance();
}

bool AbsenceDAO::ajouter(const Absence& absence) {
    if (!absence.estValide()) return false;

    std::stringstream ss;
    ss << "INSERT INTO absences (id_eleve, date_debut, date_fin, justifie, motif) VALUES ("
       << absence.getEleveId() << ", '"
       << absence.getDateDebut() << "', '"
       << absence.getDateFin() << "', "
       << (absence.estJustifie() ? "1" : "0") << ", "
       << (absence.getMotif().empty() ? "NULL" : "'" + absence.getMotif() + "'")
       << ")";

    return db->executeQuery(ss.str());
}

bool AbsenceDAO::supprimer(int id) {
    std::stringstream ss;
    ss << "DELETE FROM absences WHERE id_absence = " << id;
    return db->executeQuery(ss.str());
}

std::vector<Absence> AbsenceDAO::getAll() {
    std::vector<Absence> absences;
    
    if (db->executeQuery("SELECT * FROM absences")) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Absence absence(
                    std::stoi(row[1]),  // eleveId
                    row[2],             // dateDebut
                    row[3]              // dateFin
                );
                absence.setId(std::stoi(row[0]));
                absence.setJustifie(row[4] != nullptr && std::string(row[4]) == "1");
                if (row[5]) absence.setMotif(row[5]);
                
                absences.push_back(absence);
            }
            mysql_free_result(result);
        }
    }
    return absences;
}

std::vector<Absence> AbsenceDAO::getAbsencesEleve(int eleveId) {
    std::vector<Absence> absences;
    std::stringstream ss;
    
    ss << "SELECT * FROM absences WHERE id_eleve = " << eleveId
       << " ORDER BY date_debut DESC";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Absence absence(
                    std::stoi(row[1]),
                    row[2],
                    row[3]
                );
                absence.setId(std::stoi(row[0]));
                absence.setJustifie(row[4] != nullptr && std::string(row[4]) == "1");
                if (row[5]) absence.setMotif(row[5]);
                
                absences.push_back(absence);
            }
            mysql_free_result(result);
        }
    }
    return absences;
}

bool AbsenceDAO::justifierAbsence(int absenceId, const std::string& motif) {
    std::stringstream ss;
    ss << "UPDATE absences SET justifie = 1, motif = '" << motif 
       << "' WHERE id_absence = " << absenceId;
    
    return db->executeQuery(ss.str());
}

int AbsenceDAO::compterAbsencesEleve(int eleveId, const std::string& dateDebut, const std::string& dateFin) {
    std::stringstream ss;
    ss << "SELECT COUNT(*) FROM absences WHERE id_eleve = " << eleveId
       << " AND date_debut >= '" << dateDebut << "'"
       << " AND date_fin <= '" << dateFin << "'";

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
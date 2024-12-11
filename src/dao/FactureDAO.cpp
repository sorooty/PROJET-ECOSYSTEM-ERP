#include "../../include/dao/FactureDAO.hpp"
#include <sstream>

FactureDAO::FactureDAO() {
    db = DatabaseConnection::getInstance();
}

bool FactureDAO::ajouter(const Facture& facture) {
    if (!facture.estValide()) return false;

    std::stringstream ss;
    ss << "INSERT INTO factures (id_eleve, montant_total, date_emission, "
       << "date_echeance, statut) VALUES ("
       << facture.getEleveId() << ", "
       << facture.getMontantTotal() << ", '"
       << facture.getDateEmission() << "', '"
       << facture.getDateEcheance() << "', '"
       << facture.getStatut() << "')";

    return db->executeQuery(ss.str());
}

std::vector<Facture> FactureDAO::getFacturesEleve(int eleveId) {
    std::vector<Facture> factures;
    std::stringstream ss;
    
    ss << "SELECT * FROM factures WHERE id_eleve = " << eleveId
       << " ORDER BY date_emission DESC";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Facture facture(
                    std::stoi(row[1]),     // eleveId
                    std::stod(row[2]),     // montantTotal
                    row[3],                // dateEmission
                    row[4]                 // dateEcheance
                );
                facture.setId(std::stoi(row[0]));
                facture.setStatut(row[5]);
                
                factures.push_back(facture);
            }
            mysql_free_result(result);
        }
    }
    return factures;
}

bool FactureDAO::mettreAJourStatut(int factureId, const std::string& statut) {
    std::stringstream ss;
    ss << "UPDATE factures SET statut = '" << statut << "' "
       << "WHERE id_facture = " << factureId;
    
    return db->executeQuery(ss.str());
}

std::vector<Facture> FactureDAO::getFacturesImpayees() {
    std::vector<Facture> factures;
    std::stringstream ss;
    
    ss << "SELECT * FROM factures WHERE statut = 'en attente' "
       << "ORDER BY date_echeance ASC";

    if (db->executeQuery(ss.str())) {
        MYSQL_RES* result = db->getResult();
        if (result) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result))) {
                Facture facture(
                    std::stoi(row[1]),     // eleveId
                    std::stod(row[2]),     // montantTotal
                    row[3],                // dateEmission
                    row[4]                 // dateEcheance
                );
                facture.setId(std::stoi(row[0]));
                facture.setStatut(row[5]);
                
                factures.push_back(facture);
            }
            mysql_free_result(result);
        }
    }
    return factures;
} 
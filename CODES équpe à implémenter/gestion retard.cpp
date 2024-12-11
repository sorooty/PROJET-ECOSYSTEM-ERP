#include <iostream>
#include <vector>
#include <string>

class Retard {
public:
    int retard_id;
    int eleve_id;
    std::string date_retard;
    int duree;
    bool est_justifie;
    std::string motif;

    Retard(int retard_id, int eleve_id, std::string date_retard, int duree, bool est_justifie, std::string motif)
        : retard_id(retard_id), eleve_id(eleve_id), date_retard(date_retard), duree(duree), est_justifie(est_justifie), motif(motif) {}
};

class GestionRetard {
private:
    std::vector<Retard> retards;

public:
    void ajouterRetard(int retard_id, int eleve_id, const std::string& date_retard, int duree, bool est_justifie, const std::string& motif) {
        retards.push_back(Retard(retard_id, eleve_id, date_retard, duree, est_justifie, motif));
        std::cout << "Retard ajouté pour l'élève ID " << eleve_id << " le " << date_retard << " pour une durée de " << duree << " minutes" << std::endl;
    }

    void RetirerRetard(int retard_id) {
        for (auto it = retards.begin(); it != retards.end(); ++it) {
            if (it->retard_id == retard_id) {
                retards.erase(it);
                std::cout << "Retard avec ID " << retard_id << " supprimé" << std::endl;
                return;
            }
        }
        std::cout << "Aucun retard trouvé avec l'ID " << retard_id << std::endl;
    }

    void listRetards() const {
        std::cout << "Liste des retards :" << std::endl;
        for (const auto& retard : retards) {
            std::cout << "ID: " << retard.retard_id << ", Élève ID: " << retard.eleve_id << ", Date: " << retard.date_retard << ", Durée: " << retard.duree << " minutes, Justifié: " << (retard.est_justifie ? "Oui" : "Non") << ", Motif: " << retard.motif << std::endl;
        }
    }
};

int main() {
    GestionRetard gestion;
    int retard_id;
    int eleve_id;
    std::string date_retard;
    int duree;
    bool est_justifie;
    std::string motif;
    cout<<"ajouter l'eleve, l'id, retard, date de début et de fin, le justificatif et le motif"<<endl;
    cin>>retard_id;
    cin>>eleve_id;
    cin>>duree;
    cin>>est_justifie;
    cin>>motif;
    gestion.ajouterRetard(retard_id,eleve_id,date_retard,duree,est_justifie,motif);
    gestion.ajouterRetard(retard_id,eleve_id,date_retard,duree,est_justifie,motif);
    gestion.listRetards();
    gestion.RetirerRetard(retard_id);
    gestion.listRetards();

    return 0;
}


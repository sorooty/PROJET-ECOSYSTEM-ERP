#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Retenue {
public:
    int retenue_id;
    int eleve_id;
    string date_retenue;
    string duree;
    string motif;

    Retenue(int retenue_id, int eleve_id, std::string date_retenue, string duree, std::string motif)
        : retenue_id(retenue_id), eleve_id(eleve_id), date_retenue(date_retenue), duree(duree), motif(motif) {}
};

class RetenueManager {
private:
    std::vector<Retenue> retenues;

public:
    void ajouterRetenue(int retenue_id, int eleve_id, const std::string& date_retenue, string duree, const std::string& motif) {
        retenues.push_back(Retenue(retenue_id, eleve_id, date_retenue, duree, motif));
        std::cout << "Retenue ajoutée pour l'élève avec " << eleve_id << " le " << date_retenue << " pour une durée de " << duree << std::endl;
    }

    void retirerRetenue(int retenue_id) {
        for (auto it = retenues.begin(); it != retenues.end(); ++it) {
            if (it->retenue_id == retenue_id) {
                retenues.erase(it);
                std::cout << "Retenue avec ID " << retenue_id << " supprimée" << std::endl;
                return;
            }
        }
        std::cout << "Aucune retenue trouvée avec l'ID " << retenue_id << std::endl;
    }

    void listRetenues() const {
        std::cout << "Liste des retenues :" << std::endl;
        for (const auto& retenue : retenues) {
            std::cout << "ID: " << retenue.retenue_id << ", Élève ID: " << retenue.eleve_id << ", Date: " << retenue.date_retenue << ", Durée: " << retenue.duree << ", Motif: " << retenue.motif << std::endl;
        }
    }
};

int main() {
    RetenueManager manager;
    int retenue_id;
    int eleve_id;
    string date_retenue;
    string duree;
    string motif;
    cout<< "entree id retenue, eleve, date, duree, motif :" <<endl;
    cin>>retenue_id;
    cin>>eleve_id;
    cin>>date_retenue;
    cin>>duree;
    cin>>motif;
    manager.ajouterRetenue(retenue_id,eleve_id,date_retenue,duree,motif);
    manager.ajouterRetenue(retenue_id,eleve_id,date_retenue,duree,motif);
    manager.listRetenues();
    manager.retirerRetenue(retenue_id);
    manager.listRetenues();

    return 0;
}


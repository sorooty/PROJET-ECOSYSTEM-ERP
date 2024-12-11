#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Reunion{
public:
    int id_reunion;
    std::string titre;
    std::string date_reunion;
    std::string heure_debut;
    std::string heure_fin;
    std::string type_reunion;
    std::string salle;
    std::string desctiption;
    int organisateur_id;
    std::vector<int> participanrs;

    Reunion(int id_reunion,td::string titre, std::string date_reunion, std::string heure_debut, std::string heure_fin, std::string type_reunion, std::string salle, std::string desctiption, int organisateur_id)
        : id_reunion(id_reunion), titre(titre), date_reunion(date_reunion), heure_debut(heure_debut), heure_fin(heure_fin), type_reunion(type_reunion), salle(salle), description(description), organisateur_id(organisateur_id){}

    void ajouterParticipant(int id_utilisateur){
        participants.push_back(id_utilisateur);
    }
    static void enregistrerReunion(const Reunion& reunion) {
        cout << "La reunion a été enregistrée !" << endl;
    }
    static void afficherReunion() {
        cout << "Affichage des reunions :" << id_reunion << endl;
    }
    static void supprimerReunion(int id_reunion) {
        cout << "La reunion a ete supprimee."
    }
};
int main() {
    int choix;
    do {
        cout << "Que voulez-vous faire ?" << endl;
        cout << "1. Ajouter une reunion" << endl;
        cout << "2. Aficher les reunions" << endl;
        cout << "3. Supprimer une reunion" << endl;
        cout << "4. Quitter" << endl;

        cin >> choix;

        switch (choix) {
        case 1: {
            int id_reunion;
            std::strin titre, date_reunion, heure_debut, heure_fin, type_reunion, salle, description;
            int organisateur_id;

            cout << "Entrez les informations de la réunion :\n";

            cout << "ID de la reunion : ";
            cin >> id_reunion;

            cout << "Titre : "
            std::getline(std::cin >> std::ws, titre);

            cout << "Date de la reunion (AAAA-MM-JJ) : ";
            cin >> date_reunion;

            cout << "Heure de debut (HH:MM) : ";
            cin >> heure_debut;

            cout << "Heure de fin (HH:MM) : ";
            cin >> heure_fin;

            cout << "Type de reunion : ";
            std::gateline (std::cin >> std::ws, type_reunion);

            cout << "Salle : ";
            std::gateline (std::cin >> std::ws, salle);

            cout << "Description : ";
            std::gateline (std::cin >> std::ws, description);

            cout << "ID de l'organisateur : ";
            cin >> organisateur_id;

            Reunion nouvelle_reunion(id_reunion, titre, date_reunion, heure_debut, heure_fin, type_reunion, salle, description, organisateur_id);

            int participant_id;
            cout << "Entrer les IDs des participants (0 pour terminer) : ";
            while (cin >> participant_id && participant_id != 0) {
                    nouvelle_reunion.ajouterParticipant(participant_id);
                }

            Reunion::enregistrerReunion(nouvelle_reunion);
            break;
        }

        case 2:
            Reunion::afficherReunion();
            break;
        case 3: {
            int id_reunion;
            cout << "Entrer l'ID de la reunion a supprimer : ";
            cin >> id_reunion;
            Reunion::supprimerReunion(id_reunion);
            break;
        }
        case 4:
            cout << "Au revoir !" << endl;
            break;
        default:
            cout << "Choix invalide. Veuillez réessayer." << endl;
            break;
        }
    } while (choix!= 4)

    return 0;
}

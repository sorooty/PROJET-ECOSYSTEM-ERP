#include <iostream>
#include <vector>
#include <string>

class Absence {
public:
    int id_absence;
    int id_eleve;
    std::string date_debut;
    std::string date_fin;
    bool justifie;
    std::string motif;

    Absence(int id_absence, int id_eleve, std::string date_debut, std::string date_fin, bool justifie, std::string motif)
        : id_absence(id_absence), id_eleve(id_eleve), date_debut(date_debut), date_fin(date_fin), justifie(justifie), motif(motif) {}
};

class AbsenceManager {
private:
    std::vector<Absence> absences;

public:
    void addAbsence(int id_absence, int id_eleve, const std::string& date_debut, const std::string& date_fin, bool justifie, const std::string& motif) {
        absences.push_back(Absence(id_absence, id_eleve, date_debut, date_fin, justifie, motif));
        std::cout << "Absence ajoutée pour l'etudiant avec l'id " << id_eleve << " de " << date_debut << " à " << date_fin << std::endl;
    }

    void removeAbsence(int id_absence) {
        for (auto it = absences.begin(); it != absences.end(); ++it) {
            if (it->id_absence == id_absence) {
                absences.erase(it);
                std::cout << "Absence pour l'id " << id_absence << " supprimée" << std::endl;
                return;
            }
        }
        std::cout << "Pas d'absence pour l'id " << id_absence << std::endl;
    }

    void listAbsences() const {
        std::cout << "Liste des absences:" << std::endl;
        for (const auto& absence : absences) {
            std::cout << "ID: " << absence.id_absence << ", eleve avec id: " << absence.id_eleve << ", de: " << absence.date_debut << ", à: " << absence.date_fin << ", Justifié: " << (absence.justifie ? "Oui" : "Non") << ", Raison: " << absence.motif << std::endl;
        }
    }
};

    int main() {
        AbsenceManager manager;
        int id_absence;
        int id_eleve;
        std::string date_debut;
        std::string date_fin;
        bool justifie;
        std::string motif;
        cout<<"ajouter l'eleve, l'id, absence, date de début et de fin, le justificatif et le motif"<<endl;
        cin>>id_absence;
        cin>>id_eleve;
        cin>>date_debut;
        cin>>date_fin;
        cin>>justifie;
        cin>>motif;
        manager.addAbsence(id_absence,id_eleve,date_debut,date_fin,justifie,motif);
        manager.addAbsence(id_absence,id_eleve,date_debut,date_fin,justifie,motif);
        manager.listAbsences();
        manager.removeAbsence(id_absence);
        manager.listAbsences();

        return 0;
    }

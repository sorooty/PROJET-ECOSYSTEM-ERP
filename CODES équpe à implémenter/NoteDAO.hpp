#ifndef NOTEDAO_HPP
#define NOTEDAO_HPP

#include "../models/Note.hpp"
#include "../DatabaseConnection.hpp"
#include <vector>

class NoteDAO {
private:
    DatabaseConnection* db;

public:
    NoteDAO();

    // Méthodes CRUD
    bool ajouter(const Note& note);
    bool modifier(const Note& note);
    bool supprimer(int id);
    Note* getById(int id);
    std::vector<Note> getAll();

    // Méthodes spécifiques
    std::vector<Note> getNotesEleve(int eleveId);
    std::vector<Note> getNotesMatiereEleve(int eleveId, int matiereId);
    double getMoyenneEleve(int eleveId, int matiereId);
    double getMoyenneGenerale(int eleveId);
    double getMoyenneClasse(int classeId, int matiereId);
    std::vector<Note> getNotesParPeriode(int eleveId, const std::string& debut, const std::string& fin);
};

#endif 
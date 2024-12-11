// src/models/Reunion.cpp
#include "../../include/models/Reunion.hpp"

Reunion::Reunion(const std::string& titre, const std::string& dateReunion,
                const std::string& heureDebut, const std::string& heureFin,
                const std::string& typeReunion)
    : titre(titre),
      dateReunion(dateReunion),
      heureDebut(heureDebut),
      heureFin(heureFin),
      typeReunion(typeReunion)
{
    id = 0;
    organisateurId = 0;
}

void Reunion::ajouterParticipant(int participantId) {
    // Vérifier si le participant n'est pas déjà dans la liste
    for (int id : participants) {
        if (id == participantId) return;
    }
    participants.push_back(participantId);
}

void Reunion::retirerParticipant(int participantId) {
    for (auto it = participants.begin(); it != participants.end(); ++it) {
        if (*it == participantId) {
            participants.erase(it);
            return;
        }
    }
}

bool Reunion::estValide() const {
    return !titre.empty() &&
           !dateReunion.empty() &&
           !heureDebut.empty() &&
           !heureFin.empty() &&
           !typeReunion.empty() &&
           heureDebut < heureFin;
}

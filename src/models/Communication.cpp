// src/models/Communication.cpp
#include "../../include/models/Communication.hpp"

Communication::Communication(const std::string& type, const std::string& titre,
                           const std::string& contenu, int expediteurId)
    : type(type),
      titre(titre),
      contenu(contenu),
      expediteurId(expediteurId),
      importance("normale")
{
    id = 0;
}

void Communication::ajouterDestinataire(int destinataireId) {
    for (int id : destinataires) {
        if (id == destinataireId) return;
    }
    destinataires.push_back(destinataireId);
}

void Communication::retirerDestinataire(int destinataireId) {
    for (auto it = destinataires.begin(); it != destinataires.end(); ++it) {
        if (*it == destinataireId) {
            destinataires.erase(it);
            return;
        }
    }
}

bool Communication::estValide() const {
    return !type.empty() &&
           !titre.empty() &&
           !contenu.empty() &&
           expediteurId > 0 &&
           (type == "annonce" || type == "message" || type == "notification") &&
           (importance == "normale" || importance == "importante" || importance == "urgente");
}

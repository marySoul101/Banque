#pragma once
#include "CompteEpargne.h"
#include"ComptePayant.h"
namespace Banque {
    class CompteEpargnePayant :
         virtual public CompteEpargne,virtual public ComptePayant
    {
    public:
        CompteEpargnePayant(Devise* sol, Devise* interet, Client* c);
        void retrait(Devise* d) override;
        void virement(Devise* d) override;
        void afficher()const;
    };
}

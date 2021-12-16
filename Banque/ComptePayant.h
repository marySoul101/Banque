#pragma once
#include "CompteCourant.h"
namespace Banque {
    class ComptePayant :
        virtual public CompteCourant
    {
    private:
        static Devise* price;
    public:
        ComptePayant(Devise* d, Client* c);
        void retrait(Devise* d) override;
        void virement(Devise* d) override;
        bool check_retrait_CP(Devise * d);
        void afficher()const;

    };
};

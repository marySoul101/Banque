#pragma once
#include "Operation.h"
namespace Banque {
    class OperationR :
        public Operation
    {
    private:
        string libelle;
    public:
        OperationR(Devise* mont, Compte* c);
        void afficher()const override;
    };
};

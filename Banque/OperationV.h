#pragma once
#include "Operation.h"
namespace Banque {
    class OperationV :
        public Operation
    {
    private:
        string libelle;
    public:
        OperationV(Devise* mont, Compte* c);
        void afficher()const override;
    };
};

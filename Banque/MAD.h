#pragma once
#include "Devise.h"
namespace Banque {
    class MAD :public Devise
    {
    private:
        static double mad_dol, mad_eur;
    public:
        MAD(double v);
        Dollar* convert_to_dollar()override;
        Euro* convert_to_euro()override;
        MAD* convert_to_mad()override;
        void afficher()const;
        Devise* Clone(double);
    };

};
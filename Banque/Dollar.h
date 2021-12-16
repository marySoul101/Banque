#pragma once
#include "Devise.h"
namespace Banque {
    class Dollar :public Devise
    {
    private:
        static double doll_mad, doll_eur;
    public:
        Dollar(double v);
        MAD* convert_to_mad()override;
        Euro* convert_to_euro()override;
        Dollar* convert_to_dollar()override;
        Devise* Clone(double);
        void afficher()const;
    };
};

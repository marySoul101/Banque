#pragma once
#include "Devise.h"
namespace Banque {
    class Euro :public Devise
    {
    private:
        static double euro_mad, euro_dol;
    public:
        Euro(double v);
        MAD* convert_to_mad()override;
        Dollar* convert_to_dollar()override;
        Euro* convert_to_euro()override;
        Devise* Clone(double);
        void afficher() const;
    };
};

#include "MAD.h"
#include"Dollar.h"
#include"Euro.h"
using namespace Banque;
double MAD::mad_dol = 0.11;
double MAD::mad_eur = 0.096;
MAD::MAD(double v):Devise(v)
{
}

Dollar* MAD::convert_to_dollar()
{
	Dollar* d=new Dollar(this->convertion(this->mad_dol));
	return d;
}

Euro* MAD::convert_to_euro()
{
	Euro * e=new Euro(this->convertion(this->mad_eur));
	return e;
}

MAD* Banque::MAD::convert_to_mad() 
{
	return new MAD(*this);
}

void MAD::afficher() const
{
	this->Devise::afficher();
	cout << "MAD" << endl;
}

Devise* Banque::MAD::Clone(double v)
{
	return new MAD(v);
}

#include "Dollar.h"
#include"MAD.h"
#include"Euro.h"
using namespace Banque;
double Banque::Dollar::doll_mad = 9.18;
double Banque::Dollar::doll_eur = 0.88;
Banque::Dollar::Dollar(double v):Devise(v)
{
	
}

MAD* Banque::Dollar::convert_to_mad()
{
	MAD* m = new MAD(this->convertion(this->doll_mad));
	return m;
}

Euro* Banque::Dollar::convert_to_euro()
{
	Euro* e = new Euro(this->convertion(this->doll_eur));
	return e;
}

Dollar* Banque::Dollar::convert_to_dollar() 
{
	return new Dollar(*this);
}

Devise* Banque::Dollar::Clone(double v)
{
	return new Dollar(v);
}

void Banque::Dollar::afficher() const
{
	this->Devise::afficher();
	cout << "Dollar" << endl;
}

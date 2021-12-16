#include "Euro.h"
#include"Dollar.h"
#include"MAD.h"
using namespace Banque;
double Euro::euro_dol = 1.13;
double Euro::euro_mad = 10.42;
Banque::Euro::Euro(double v):Devise(v)
{
	
}

MAD* Banque::Euro::convert_to_mad()
{
	MAD* m=new MAD(this->Devise::convertion(this->euro_mad));
	return m;
}

Dollar* Banque::Euro::convert_to_dollar()
{
	Dollar* d = new Dollar(this->convertion(this->euro_dol));
	return d;
}

Euro* Banque::Euro::convert_to_euro() 
{
	return  new Euro(*this);
}

Devise* Banque::Euro::Clone(double v)
{
	return new Euro(v);
}

void Banque::Euro::afficher() const
{
	this->Devise::afficher();
	cout << "Euro" << endl;
}

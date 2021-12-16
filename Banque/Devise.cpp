#include "Devise.h"
#include"MAD.h"
#include"Euro.h"
#include"Dollar.h"
#include<typeinfo>
using namespace Banque;
Banque::Devise::Devise(double v)
{
	this->valeur = v;
}

double Banque::Devise::convertion(double v)
{
	return this->valeur*v;
}

MAD* Banque::Devise::convert_to_mad() 
{
	MAD* m = new MAD(this->valeur);
	return m; 
}

Dollar* Banque::Devise::convert_to_dollar() 
{
	Dollar* d = new Dollar(this->valeur);
	return d;
}

Euro* Banque::Devise::convert_to_euro() 
{
	Euro* e = new Euro(this->valeur);
	return e;
}

Devise& Banque::Devise::operator+(Devise& d)
{
	Devise* converted = this->ConvertToMyType(&d);
	Devise* test = this->Clone(this->valeur + converted->valeur);
	delete converted;
	return *test;
}

Devise& Banque::Devise::operator-(Devise& d)
{
	Devise* converted = this->ConvertToMyType(&d);
	Devise* test = this->Clone(this->valeur - converted->valeur);
	delete converted;
	return *test;
}

Devise& Banque::Devise::operator*(Devise& d)
{
	Devise* converted = this->ConvertToMyType(&d);
	Devise* test = this->Clone(this->valeur * converted->valeur);
	delete converted;
	return *test;
}

bool Banque::Devise::operator>=(Devise& d)
{
	bool res = false;
	Devise* converted = this->ConvertToMyType(&d);
	if (this->valeur >= converted->valeur) res = true;
	delete converted;
	return res;
}

bool Banque::Devise::operator<=(Devise& d)
{
	bool res = false;
	Devise* converted = this->ConvertToMyType(&d);
	if (this->valeur <= converted->valeur) res = true;
	delete converted;
	return res;
}



void Banque::Devise::afficher() const
{
	cout << "le solde: " << this->valeur << endl;
}

Devise* Banque::Devise::ConvertToMyType(Devise* D)
{
	if (typeid(*this) == typeid(MAD))return D->convert_to_mad();
	if (typeid(*this) == typeid(Dollar))return D->convert_to_dollar();
	if (typeid(*this) == typeid(Euro))return D->convert_to_euro();
}

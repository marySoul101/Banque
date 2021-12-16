#include "ComptePayant.h"
#include"MAD.h"


using namespace Banque;
Devise* Banque::ComptePayant::price = new MAD(0.05);
Banque::ComptePayant::ComptePayant(Devise* d, Client* c):CompteCourant(d,c),Compte(d,c)
{
}

void Banque::ComptePayant::retrait(Devise* d)
{
	if (this->check_retrait_CP(d)) {

		this->CompteCourant::retrait(d);
		this->CompteCourant::retrait(&(d->operator*(*(this->price))));
	}
}

void Banque::ComptePayant::virement(Devise* d)
{
	this->CompteCourant::virement(d);
	this->CompteCourant::retrait(&(d->operator*(*(this->price))));
}

bool Banque::ComptePayant::check_retrait_CP(Devise* d)
{
	return (this->check_solde(&(*d * *(this->price))));
}

void Banque::ComptePayant::afficher() const
{
	cout << "\nprix d'op: " << endl;
		this->price->afficher();
	this->CompteCourant::afficher();
}

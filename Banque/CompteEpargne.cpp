#include "CompteEpargne.h"
#include"MAD.h"
using namespace Banque;
Devise* CompteEpargne::min_taux = new MAD(0);
Devise* CompteEpargne::max_taux = new MAD(100);
Banque::CompteEpargne::CompteEpargne(Devise* t, Devise* s, Client* c):Compte(s,c)
{
	if(t->operator>=(*(this->min_taux))&&t->operator<=(*(this->max_taux)))
	this->taux_interet = t;
}

void Banque::CompteEpargne::retrait(Devise* d)
{
	
	if (this->check_retrait_CE(d))
	{
		this->Compte::retrait(d);
	}
}

void Banque::CompteEpargne::virement(Devise* d)
{
	this->Compte::virement(d);
}

Devise* Banque::CompteEpargne::calcul_interet()
{
	return this->times_solde(this->taux_interet);
}

bool Banque::CompteEpargne::check_retrait_CE(Devise* d)
{
	Devise* d1 = new MAD(0.5);
	return (d->operator<=(*(this->times_solde(d1))));
}

void Banque::CompteEpargne::afficher() const
{
	cout << "\ntaux interet: " << endl;
		this->taux_interet->afficher();
	this->Compte::afficher();
}

void Banque::CompteEpargne::afficher_taux_interet() const
{
	cout << "\ntaux interet: " << endl;
	this->taux_interet->afficher();
}

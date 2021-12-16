#include "CompteCourant.h"
#include"Operation.h"
#include"OperationR.h"
#include"OperationV.h"
#include"MAD.h"
using namespace Banque;
Devise* Banque::CompteCourant::decouvert = new MAD(200);
Banque::CompteCourant::CompteCourant( Devise* s, Client* c):Compte(s,c)
{
}

void Banque::CompteCourant::retrait(Devise* d)
{
	if ((this->solde_suffisant(d)) &&  (this->test_sup(d->operator+(*(this->decouvert)))))
	{
		this->Compte::retrait(d);
	}
	
}

void Banque::CompteCourant::virement(Devise* d)
{
	this->Compte::virement(d);
	
}

void Banque::CompteCourant::afficher() const
{
	cout << "\ndecouvert: " ;
	this->decouvert->afficher();
	this->Compte::afficher();
}

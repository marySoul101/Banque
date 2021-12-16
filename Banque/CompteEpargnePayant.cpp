#include "CompteEpargnePayant.h"

Banque::CompteEpargnePayant::CompteEpargnePayant(Devise* sol, Devise* interet, Client* c) :CompteEpargne(interet, sol, c) , ComptePayant(sol,c),CompteCourant(sol,c),Compte(sol,c)
{

}

void Banque::CompteEpargnePayant::retrait(Devise* d)
{
	if (this->check_retrait_CE(d))
	{
		this->ComptePayant::retrait(d);
	}
}

void Banque::CompteEpargnePayant::virement(Devise* d)
{
	this->ComptePayant::virement(d);
}

void Banque::CompteEpargnePayant::afficher() const
{
	this->CompteEpargne::afficher_taux_interet();
	this->ComptePayant::afficher();
}

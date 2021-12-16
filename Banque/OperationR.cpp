#include "OperationR.h"
using namespace Banque;
Banque::OperationR::OperationR(Devise* mont, Compte* c):Operation(mont,c)
{
	this->libelle = "retrait";
}

void Banque::OperationR::afficher() const
{
	cout << "\ntype op: " << this->libelle;
	this->Operation::afficher();
}

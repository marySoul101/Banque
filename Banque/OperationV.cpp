#include "OperationV.h"
using namespace Banque;
Banque::OperationV::OperationV(Devise* mont, Compte* c):Operation(mont,c)
{
	this->libelle = "virement";
}

void Banque::OperationV::afficher() const
{
	cout << "\ntype op: " << this->libelle;
	this->Operation::afficher();
}

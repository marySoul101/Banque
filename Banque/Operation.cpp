#include "Operation.h"
#include"Compte.h"
using namespace Banque;
int Banque:: Operation:: compt=0;
Banque::Operation::Operation(Devise* mont,Compte* c):num_op(++compt)
{
	this->date_op = __DATE__;
	this->montant_op = mont;
	this->compte_banq = c;
}

Banque::Operation::~Operation()
{
	delete this->montant_op;
}

void Banque::Operation::afficher() const
{
	cout << "\nnum op: " << this->num_op << "\ndate op: " << this->date_op<<endl;
	this->montant_op->afficher();
	//this->compte_banq->Compte::afficher();
}

#include "Compte.h"
#include"OperationV.h"
#include"OperationR.h"
#include"Client.h"
#include"MAD.h"
using namespace Banque;
int Banque::Compte::compt = 0;
Devise* Banque::Compte::plafond = new MAD(2000);
Banque::Compte::Compte(Devise* d,Client* c):num_compte(++compt)
{
	this->solde = d;
	this->titulaire = c;
}

Banque::Compte::~Compte()
{
	for (int i = 0; i < this->liste_operations.size(); i++)
		delete  this->liste_operations[i];
	delete this->solde;
	//this->liste_operations.clear();
}

bool Banque::Compte::solde_suffisant(Devise* mont)
{
	return((this->solde->operator>=(*mont))&&(mont->operator<=(*(this->plafond))));
}

Devise* Banque::Compte::minus_solde(Devise* d)
{
	return &(this->solde->operator-(*d));
}

Devise* Banque::Compte::plus_solde(Devise* d)
{
	return &(this->solde->operator+(*d));
}

Devise* Banque::Compte::times_solde(Devise* d)
{
	return &(this->solde->operator*(*d));
	
}

bool Banque::Compte::check_solde(Devise* d)
{
	return (this->solde->operator>=(*d));
}

bool Banque::Compte::check_solde(Devise* d1, Devise* d2)
{
	return (this->solde->operator>=(d1->operator*(*d2)));
}



void Banque::Compte::retrait(Devise* d)
{
	*(this->solde) = *(this->solde)- *d;
	OperationR* o = new OperationR(d, this);
	this->ajouter_operation(o);
}

void Banque::Compte::virement(Devise* d)
{
	*(this->solde) = *(this->solde) + *d;
	OperationV* o = new OperationV(d, this);
	this->ajouter_operation(o);
}

void Banque::Compte::ajouter_operation(Operation* o)
{
	this->liste_operations.push_back(o);
}

bool Banque::Compte::test_sup(Devise& d)
{
	return (this->solde->operator>=(d));
}



void Banque::Compte::afficher() const
{
	cout << "\nnum compte: " << this->num_compte<<endl;
	this->solde->afficher();
	//this->titulaire->Client::afficher();
	for (int i = 0; i < this->liste_operations.capacity(); i++)
	{
		this->liste_operations[i]->afficher();
		cout << endl;
	}
}

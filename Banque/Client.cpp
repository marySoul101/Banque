#include "Client.h"
using namespace Banque;
Banque::Client::Client(string p, string n, string adr)
{
	this->prenom = p;
	this->nom = n;
	this->adresse = adr;
}

Banque::Client::~Client()
{
	if (this->liste_comptes.size() > 0)
	{
		for (int i = 0; i < this->liste_comptes.size(); i++)
		{
			//this->liste_comptes.at(i)->~Compte();
			delete this->liste_comptes[i];
		}
	}

}

void Banque::Client::ajouter_compte(Compte* c)
{
	this->liste_comptes.push_back(c);
}

void Banque::Client::afficher() const
{
	cout << "\nnom client: " << this->nom << "\nprenom client: " << this->prenom << "\nadresse client: " << this->adresse<<endl;
	for (int i = 0; i < this->liste_comptes.capacity(); i++)
	{
		this->liste_comptes.at(i)->afficher();
		cout << endl;
	}
}

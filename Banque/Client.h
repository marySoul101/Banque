#pragma once
#include<iostream>
#include<vector>
#include"Compte.h"
using namespace std;
namespace Banque {
	class Client
	{
	private:
		string prenom;
		string nom;
		string adresse;
		vector <Compte*> liste_comptes;
	public:
		Client(string p, string n, string adr);
		~Client();
		void ajouter_compte(Compte* c);
		void afficher()const;
	};
};

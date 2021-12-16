#pragma once
#include<iostream>
#include<vector>
#include"Devise.h"
using namespace std;
namespace Banque {
	class Operation;
	class OperationR;
	class OperationV;
	class Client;
	class MAD;
	class Compte
	{
	private:
		int static compt;
		int const num_compte;
		Devise* solde;
		static Devise* plafond;
		Client* titulaire;
		vector<Operation*> liste_operations;
	public:
		Compte(Devise* d,Client* c);
		virtual ~Compte();
		bool solde_suffisant(Devise* d);
		Devise* minus_solde(Devise* d);
		Devise* plus_solde(Devise* d);
		Devise* times_solde(Devise* d);
		bool check_solde(Devise* d);
		bool check_solde(Devise* d1,Devise*d2);
		virtual void retrait(Devise* d)=0;
		virtual void virement(Devise* d)=0;
		void ajouter_operation(Operation* o);
		bool test_sup(Devise& d);
		void afficher()const;
	};
};

#pragma once
#include<iostream>
#include"Devise.h"
using namespace std;
namespace Banque {
	class Compte;
	class Operation
	{
	private:
		int static compt;
		const int num_op;
		string date_op;
		Devise* montant_op;
		Compte* compte_banq;
	public:
		Operation(Devise* mont,Compte* c);
		virtual ~Operation();
		virtual void afficher()const;
	};
};

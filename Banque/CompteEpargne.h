#pragma once
#include<assert.h>
#include"Compte.h"
namespace Banque {
	class CompteEpargne :virtual public Compte
	{
	private:
		Devise* taux_interet;
		static Devise* min_taux,* max_taux;
	public:
		CompteEpargne(Devise* t, Devise* s, Client* c);
		void retrait(Devise* d) ;
		void virement(Devise* d) ;
		Devise* calcul_interet();
		bool check_retrait_CE(Devise* d);
		void afficher()const;
		void afficher_taux_interet()const;
	};
};

#pragma once
#include"Compte.h"
namespace Banque {
	class CompteCourant : virtual public Compte
	{
	private:
		static Devise* decouvert;
	public:
		CompteCourant( Devise* s, Client* c);
		void retrait(Devise* d) override;
		void virement(Devise* d) override;
		void afficher()const;
	};
};

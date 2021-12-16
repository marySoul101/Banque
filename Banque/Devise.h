#pragma once
#include<typeinfo>
#include<iostream>
//#include"MAD.h"
//#include"Dollar.h"
//#include"Euro.h"
using namespace std;
namespace Banque {
	class MAD;
	class Dollar;
	class Euro;
	class Devise
	{
	private:
		double valeur;
	public:
		Devise(double v);
		 double convertion(double v);
		 virtual MAD* convert_to_mad() = 0;
		 virtual Dollar* convert_to_dollar()=0;
		 virtual Euro* convert_to_euro()=0;
		 virtual Devise* Clone(double v)=0;
		 Devise& operator+(Devise& d);
		 Devise& operator-(Devise& d);
		 Devise& operator*(Devise& d);
		 bool operator>=(Devise& d);
		 bool operator<=(Devise& d);
		 Devise& operator=(Devise* d)=delete;
		 virtual void afficher()const;
		 Devise* ConvertToMyType(Devise* D);
	};
};

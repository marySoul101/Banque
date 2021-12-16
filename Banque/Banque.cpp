// Banque.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include"Devise.h"
#include"MAD.h"
#include"Dollar.h"
#include"Euro.h"
#include"Client.h"
#include"Compte.h"
#include"CompteCourant.h"
#include"CompteEpargne.h"
#include"ComptePayant.h"
#include"Operation.h"
#include"OperationR.h"
#include"OperationV.h"
using namespace std;
using namespace Banque;
int main()
{
    Devise* d = new MAD(100);
    Devise* d1 = new Dollar(1020);
    Devise* d5 = new MAD(25);
    Devise* d6 = new MAD(120);
    d->afficher();
    d1 = d1->convert_to_euro();
    d1->afficher();
    Client* c = new Client("saad", "salmi", "adrsaad");
    CompteCourant* c1 = new CompteCourant(d, c);
    c->ajouter_compte(c1);
    c->afficher();
    c1->virement(d5);
    c1->afficher();
    c1->retrait(d6);
    c1->afficher();
    delete c;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

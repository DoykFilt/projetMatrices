#include "Cexception.h"
#include "Cmatrice.h"
#include "Cparseur.h"
#include "CmatriceGenerateur.h"
#include "CmatriceManipulateur.h"
#include <iostream>

using namespace std;

void main(int argc, char * argv[])
{
	try
	{
		
		argc = 2;
		argv[1] = "matrice.txt";
		

		Cmatrice<double> * pdMATMatrice = nullptr;
		Cmatrice<double> * pdMATtemp = nullptr;
		Cparseur * pPARparseur = nullptr;
		CmatriceGenerateur * pMGRmatriceGenerateur = new CmatriceGenerateur();
		CmatriceManipulateur<double> * pMMAmatriceManipulateur = new CmatriceManipulateur<double>();
		
		char ** ppcBalises;
		unsigned int uiNbrBalises;
		unsigned int uiCompteur;

		//les balises principales à trouver dans le fichier
		uiNbrBalises = 4;
		ppcBalises = new char *[uiNbrBalises];
		ppcBalises[0] = _strdup("TYPEMATRICE");
		ppcBalises[1] = _strdup("NBCOLONNES");
		ppcBalises[2] = _strdup("NBLIGNES");
		ppcBalises[3] = _strdup("MATRICE");
		pPARparseur = new Cparseur(ppcBalises, uiNbrBalises);

		//Si il n'y a aucune matrice on s'arrête là
		if(argc <= 1)
			throw(Cexception(0, "Pas de parametres"));
		//Si il y a plus d'une matrice en paramètre on le signal mais on continu
		if(argc > 2)
			cout << "Attention seule la première matrice passée en paramètre sera utilisee" << endl << endl;

		//On récupère la matrice
		pPARparseur->PARLire(argv[1]);
		pMGRmatriceGenerateur->MGRsetParseur(pPARparseur);
		pdMATMatrice = pMGRmatriceGenerateur->MGRgenererMatrice();

		//affichage matrices rentrées
		cout << "La matrice lue est :" << endl << endl;
		pdMATMatrice->MTMATAfficherMatrice();
		cout << endl;

		//affichage de la matrice échelonnée
		cout << "Echelonnee cette matrice devient :" << endl << endl;
		pdMATtemp = & pMMAmatriceManipulateur->MTMAMEchelonnageMatrice(pdMATMatrice);
		pdMATtemp->MTMATAfficherMatrice();
		free(pdMATtemp);
		cout << endl;

		//Calcul rang matrices
		cout << "Ainsi son rang est : ";
		cout << pMMAmatriceManipulateur->MTMAMCalculRang(pdMATMatrice) << endl;


		//On libère la mémoire allouée
		free(pdMATMatrice);
		delete pMGRmatriceGenerateur;
		delete pMMAmatriceManipulateur;
		delete pPARparseur;
		for(uiCompteur = 0; uiCompteur < uiNbrBalises; uiCompteur++)
			free(ppcBalises[uiCompteur]);
		delete ppcBalises;
	}
	catch(Cexception EXCexception)
	{
		//Dans le cas d'une levé d'exception on l'attrape et on la lit
		cout << "Erreur " << EXCexception.EXCLire_Valeur() << " : " << EXCexception.EXCLire_Message() << endl;
	}
}
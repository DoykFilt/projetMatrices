#include "Cexception.h"
#include "Cmatrice.h"
#include "Cparseur.h"
#include "CmatriceGenerateur.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void main(int argc, char * argv[])
{
		/*
		argc = 2;
		argv[1] = "matrice.txt";*/

		unsigned int uiCmptr, uiNbrMatrice = 0;
		double dValeur;
		Cmatrice<double> ** ppdMATListeMatrice = nullptr;
		Cmatrice<double> * pdMATTemp = nullptr;
		Cparseur * pPARparseur = nullptr;
		CmatriceGenerateur * pMGRmatriceGenerateur = new CmatriceGenerateur();
		
		char ** ppcBalises;
		unsigned int uiNbrBalises;

		
	try
	{
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

		//On récupère les matrices
		for(uiCmptr = 1; uiCmptr < (unsigned int)argc; uiCmptr++)
		{
			pPARparseur->PARLire(argv[uiCmptr]);
			if(ppdMATListeMatrice == nullptr)
			{
				ppdMATListeMatrice = (Cmatrice<double> **)malloc(sizeof(Cmatrice<double> *));
				if(ppdMATListeMatrice == nullptr)
					throw Cexception(ERREUR_ALLOCATION, "Dans la fonction main");
			}
			else 
			{
				ppdMATListeMatrice = (Cmatrice<double> **)realloc(ppdMATListeMatrice, sizeof(Cmatrice<double> *) * (uiNbrMatrice + 1));
				if(ppdMATListeMatrice == nullptr)
					throw Cexception(ERREUR_REALLOCATION, "Dans la fonction main");
			}
			pMGRmatriceGenerateur->MGRsetParseur(pPARparseur);
			ppdMATListeMatrice[uiNbrMatrice] = pMGRmatriceGenerateur->MGRgenererMatrice();
			uiNbrMatrice++;
		}

	
		//On demande à l'utilisateur de rentrer un nombre
		cout << "Entrez une valeur : " << endl;
		while(!(cin >> dValeur))
		{
			cerr << "Erreur de saisie, ressaisissez une valeur valide (nombre reel)" << endl;
            cin.clear();  
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
		}
		cout << endl;
	
		//On multiplie chaque matrice par cette valeur
		cout << "Multiplication de toutes les matrices par " << dValeur << " :\n\n";
		for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
		{
			(dValeur * *(ppdMATListeMatrice[uiCmptr])).MTMATAfficherMatrice();
			cout << endl;
		}
	
		//On divise chaque matrice par cette valeur
		cout << "Division de toutes les matrices par " << dValeur << " :\n\n";
		for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
		{
			(*(ppdMATListeMatrice[uiCmptr]) / dValeur).MTMATAfficherMatrice();
			cout << endl;
		}
	}
	catch(Cexception EXCexception)
	{
		//Dans le cas d'une levé d'exception on l'attrape et on la lit
		cout << "Erreur " ;
		cout << EXCexception.EXCLire_Valeur() << " : " ;
		cout << EXCexception.EXCLire_Message() << endl;
	}
	
	try
	{
		//On addition toute les matrices entre elles
		if(uiNbrMatrice != 0)
			pdMATTemp = new Cmatrice<double>(*ppdMATListeMatrice[0]);
		for(uiCmptr = 1; uiCmptr < uiNbrMatrice; uiCmptr++)
			*pdMATTemp = *pdMATTemp + *ppdMATListeMatrice[uiCmptr];
		cout << "Resultat de l'addition de toutes les matrice entre elles : \n" << endl;
		pdMATTemp->MTMATAfficherMatrice();
		
	}
	catch(Cexception EXCexception)
	{
		//Dans le cas d'une levé d'exception on l'attrape et on la lit
		cout << "Erreur " ;
		cout << EXCexception.EXCLire_Valeur() << " : " ;
		cout << EXCexception.EXCLire_Message() << endl;
	}

	try
	{
		//On alterne addition et soustraction entre toute les matrices
		if(uiNbrMatrice != 0)
			*pdMATTemp = *ppdMATListeMatrice[0];
		for(uiCmptr = 1; uiCmptr < uiNbrMatrice; uiCmptr++)
		{
			if(uiCmptr % 2 == 0)
				*pdMATTemp = *pdMATTemp + *ppdMATListeMatrice[uiCmptr];
			else
				*pdMATTemp = *pdMATTemp - *ppdMATListeMatrice[uiCmptr];
		}
		cout << "Resultat de la soustraction alternee avec la soustraction des matrice entre elles : \n" << endl;
		pdMATTemp->MTMATAfficherMatrice();
		
	}
	catch(Cexception EXCexception)
	{
		//Dans le cas d'une levé d'exception on l'attrape et on la lit
		cout << "Erreur " ;
		cout << EXCexception.EXCLire_Valeur() << " : " ;
		cout << EXCexception.EXCLire_Message() << endl;
	}

	try
	{
		//On multiplie toute les matrices entre elles
		if(uiNbrMatrice != 0)
			*pdMATTemp = *ppdMATListeMatrice[0];
		for(uiCmptr = 1; uiCmptr < uiNbrMatrice; uiCmptr++)
			*pdMATTemp = *pdMATTemp * *ppdMATListeMatrice[uiCmptr];
		cout << "Resultat de la multiplication de toutes les matrice entre elles : \n" << endl;
		pdMATTemp->MTMATAfficherMatrice();
		
	}
	catch(Cexception EXCexception)
	{
		//Dans le cas d'une levé d'exception on l'attrape et on la lit
		cout << "Erreur " ;
		cout << EXCexception.EXCLire_Valeur() << " : " ;
		cout << EXCexception.EXCLire_Message() << endl;
	}

	//On libère la mémoire allouée
	for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
		delete ppdMATListeMatrice[uiCmptr];
	free(ppdMATListeMatrice);
	delete pdMATTemp;

	this_thread::sleep_for(chrono::seconds(5));
}
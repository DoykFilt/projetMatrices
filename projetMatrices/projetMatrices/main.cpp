#include "Cexception.h"
#include "Cmatrice.h"
#include "Cparseur.h"
#include <iostream>

using namespace std;

void main(int argc, char * argv[])
{
	try
	{
		unsigned int uiCmptr, uiNbrMatrice = 0;
		double dValeur;
		CMatrice<double> ** ppdMATListeMatrice = nullptr;
		CMatrice<double> * dMATTemp = nullptr;
		Cparseur * pPARparseur = new Cparseur();

		//On récupère les matrices
		for(uiCmptr = 1; uiCmptr < (unsigned int)argc; uiCmptr++)
		{
			pPARparseur->PARLireMatrice(argv[uiCmptr]);
			if(ppdMATListeMatrice == nullptr)
			{
				ppdMATListeMatrice = (CMatrice<double> **)malloc(sizeof(CMatrice<double> *));
				if(ppdMATListeMatrice == nullptr)
					throw Cexception(1, "Dans la fonction main");
			}
			else 
			{
				ppdMATListeMatrice = (CMatrice<double> **)realloc(ppdMATListeMatrice, sizeof(CMatrice<double> *) * (uiNbrMatrice + 1));
				if(ppdMATListeMatrice == nullptr)
					throw Cexception(2, "Dans la fonction main");
			}
			(pPARparseur->PARcreerDoubleMatrice())->MTMATAfficherMatrice();
			ppdMATListeMatrice[uiNbrMatrice] = pPARparseur->PARcreerDoubleMatrice();
			uiNbrMatrice++;
		}
	
		//On demande à l'utilisateur de rentrer un nombre
		cout << "Entrez une valeur : " << endl;
		cin >> dValeur;
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
	
		//On addition toute les matrices entre elles
		if(uiNbrMatrice != 0)
			dMATTemp = new CMatrice<double>(*ppdMATListeMatrice[0]);
		for(uiCmptr = 1; uiCmptr < uiNbrMatrice; uiCmptr++)
			*dMATTemp = *dMATTemp + *ppdMATListeMatrice[uiCmptr];
		cout << "Resultat de l'addition de toutes les matrice entre elles : \n" << endl;
		dMATTemp->MTMATAfficherMatrice();

		//On alterne addition et soustraction entre toute les matrices
		if(uiNbrMatrice != 0)
			*dMATTemp = *ppdMATListeMatrice[0];
		for(uiCmptr = 1; uiCmptr < uiNbrMatrice; uiCmptr++)
		{
			if(uiCmptr % 2 == 0)
				*dMATTemp = *dMATTemp + *ppdMATListeMatrice[uiCmptr];
			else
				*dMATTemp = *dMATTemp - *ppdMATListeMatrice[uiCmptr];
		}
		cout << "Resultat de la soustraction alternee avec la soustraction des matrice entre elles : \n" << endl;
		dMATTemp->MTMATAfficherMatrice();

		//On multiplie toute les matrices entre elles
		if(uiNbrMatrice != 0)
			*dMATTemp = *ppdMATListeMatrice[0];
		for(uiCmptr = 1; uiCmptr < uiNbrMatrice; uiCmptr++)
			*dMATTemp = *dMATTemp * *ppdMATListeMatrice[uiCmptr];
		cout << "Resultat de la multiplication de toutes les matrice entre elles : \n" << endl;
		dMATTemp->MTMATAfficherMatrice();

		//On libère la mémoire allouée
		for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
			delete ppdMATListeMatrice[uiCmptr];
		free(ppdMATListeMatrice);
		delete dMATTemp;
	}
	catch(Cexception EXCexception)
	{
		//Dans le cas d'une levé d'exception on l'attrape et on la lit
		cout << "Erreur " ;
		cout << EXCexception.EXCLire_Valeur() << " : " ;
		cout << EXCexception.EXCLire_Message() << endl;
	}
}
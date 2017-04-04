#include "Cexception.h"
#include "Cmatrice.h"
#include "Cparseur.h"
#include <iostream>

using namespace std;

void main(int argc, char * argv[])
{
	try
	{
		//On lit les matrices
		unsigned int uiCmptr, uiNbrMatrice = 0;
		double dValeur;
		CMatrice<double> ** ppdMATListeMatrice = nullptr;
		CMatrice<double> * dMATTemp;
		Cparseur * pPARparseur = new Cparseur();

		//On r�cup�re les matrices
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

			ppdMATListeMatrice[uiNbrMatrice] = pPARparseur->PARcreerDoubleMatrice();
			uiNbrMatrice++;
		}
	
		//On demande � l'utilisateur de rentrer un nombre
		cout << "Entrez une valeur : " << endl;
		cin >> dValeur;
		cout << endl;

		//On multiplie chaque matrice par cette valeur
		cout << "Multiplication de toute les matrices par " << dValeur << " :\n\n";
		for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
		{
			(*(ppdMATListeMatrice[uiCmptr]) * 4).MTMATAfficherMatrice();
			cout << endl;
		}
	
		//On multiplie chaque matrice par cette valeur
		cout << "Multiplication de toute les matrices par " << dValeur << " :\n\n";
		for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
		{
			(4.0 * *(ppdMATListeMatrice[uiCmptr])).MTMATAfficherMatrice();
			cout << endl;
		}
	
		//On divise chaque matrice par cette valeur
		cout << "Division de toute les matrices par " << dValeur << " :\n\n";
		for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
		{
			(*(ppdMATListeMatrice[uiCmptr]) / 4).MTMATAfficherMatrice();
			cout << endl;
		}
	
		//On addition toute les matrices entre elles
		if(uiNbrMatrice != 0)
			dMATTemp = new CMatrice<double>(*ppdMATListeMatrice[0]);
		for(uiCmptr = 1; uiCmptr < uiNbrMatrice; uiCmptr++)
			*dMATTemp = *dMATTemp + *ppdMATListeMatrice[uiCmptr];
		cout << "R�sultat de l'addition de toute les matrice entre elles : \n" << endl;
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
		cout << "R�sultat de la soustraction altern�e avec la soustraction des matrice entre elles : \n" << endl;
		dMATTemp->MTMATAfficherMatrice();

		//On multiplie toute les matrices entre elles
		if(uiNbrMatrice != 0)
			*dMATTemp = *ppdMATListeMatrice[0];
		for(uiCmptr = 1; uiCmptr < uiNbrMatrice; uiCmptr++)
			*dMATTemp = *dMATTemp * *ppdMATListeMatrice[uiCmptr];
		cout << "R�sultat de la multiplication de toute les matrice entre elles : \n" << endl;
		dMATTemp->MTMATAfficherMatrice();

		//On lib�re la m�moire allou�e
		for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
			delete ppdMATListeMatrice[uiCmptr];
		free(ppdMATListeMatrice);
		delete dMATTemp;
	}
	catch(Cexception EXCexception)
	{
		//Dans le cas d'une lev� d'exception on l'attrape et on la lit
		cout << "Erreur " << EXCexception.EXCLire_Valeur() << " : " << EXCexception.EXCLire_Message() << endl;
	}
}
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
		CMatrice<double> * dMATTemp;
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

			ppdMATListeMatrice[uiNbrMatrice] = pPARparseur->PARcreerDoubleMatrice();
			uiNbrMatrice++;
		}
	
		//affichage matrices rentrées
		cout << "Affichage matrices" << endl;
		for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
		{
			(*(ppdMATListeMatrice[uiCmptr])).MTMATAfficherMatrice();
			cout << endl;
		}

		//echelonnage matrices
		cout << "echelonnage matrices" << endl;
		for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
		{
			(*(ppdMATListeMatrice[uiCmptr])).MTMATEchelonnageMatrice();
			(*(ppdMATListeMatrice[uiCmptr])).MTMATAfficherMatrice();
		}

		//Calcul rang matrices
		cout << "calcul rangs matrices" << endl;
		for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
		{
			(*(ppdMATListeMatrice[uiCmptr])).MTMATEchelonnageMatrice().MTMATCalculRang();
			(*(ppdMATListeMatrice[uiCmptr])).MTMATAfficherMatrice();
		}



		//On libère la mémoire allouée
		for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
			delete ppdMATListeMatrice[uiCmptr];
		free(ppdMATListeMatrice);
		delete dMATTemp;
	}
	catch(Cexception EXCexception)
	{
		//Dans le cas d'une levé d'exception on l'attrape et on la lit
		cout << "Erreur " << EXCexception.EXCLire_Valeur() << " : " << EXCexception.EXCLire_Message() << endl;
	}
}
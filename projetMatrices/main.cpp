#include "Cexception.h"
#include "CMatrice.h"
#include "Cparseur.h"
#include <iostream>

using namespace std;

void main(int argc, char * argv[])
{
	//On lit les matrices
	unsigned int uiCmptr, uiNbrMatrice = 0;
	double dValeur;
	CMatrice<double> ** ppdMATListeMatrice = nullptr;
	CMatrice<double> dMATTemp;
	Cparseur * pPARparseur = new Cparseur();

	cout<< argc << endl;
	for(uiCmptr = 0; uiCmptr < (unsigned int)argc; uiCmptr++)
		cout << argv[uiCmptr] << endl;

	for(uiCmptr = 1; uiCmptr < (unsigned int)argc; uiCmptr++)
	{
		pPARparseur->PARLireMatrice(argv[uiCmptr]);
		if(ppdMATListeMatrice == nullptr)
			ppdMATListeMatrice = (CMatrice<double> **)malloc(sizeof(CMatrice<double> *));
		else 
			ppdMATListeMatrice = (CMatrice<double> **)realloc(ppdMATListeMatrice, sizeof(CMatrice<double> *) * (uiNbrMatrice + 1));

		ppdMATListeMatrice[uiNbrMatrice] = pPARparseur->PARcreerDoubleMatrice();
		uiNbrMatrice++;
	}

	for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
	{
		ppdMATListeMatrice[uiCmptr]->MTMATAfficherMatrice();
		cout << endl;
	}
	
	//On demande à l'utilisateur de rentrer un nombre
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
		(*(ppdMATListeMatrice[uiCmptr]) * 4).MTMATAfficherMatrice();
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
		dMATTemp = *ppdMATListeMatrice[0];
	for(uiCmptr = 1; uiCmptr < uiNbrMatrice; uiCmptr++)
		dMATTemp = dMATTemp + *ppdMATListeMatrice[uiCmptr];
	cout << "Résultat de l'addition de toute les matrice entre elles : \n" << endl;
	dMATTemp.MTMATAfficherMatrice();

	//On alterne addition et soustraction entre toute les matrices
	if(uiNbrMatrice != 0)
		dMATTemp = *ppdMATListeMatrice[0];
	for(uiCmptr = 1; uiCmptr < uiNbrMatrice; uiCmptr++)
	{
		if(uiCmptr % 2 == 0)
			dMATTemp = dMATTemp + *ppdMATListeMatrice[uiCmptr];
		else
			dMATTemp = dMATTemp - *ppdMATListeMatrice[uiCmptr];
	}
	cout << "Résultat de la soustraction alternée avec la soustraction des matrice entre elles : \n" << endl;
	dMATTemp.MTMATAfficherMatrice();

	//On libère la mémoire allouée
	for(uiCmptr = 0; uiCmptr < uiNbrMatrice; uiCmptr++)
		delete ppdMATListeMatrice[uiCmptr];
	free(ppdMATListeMatrice);
}
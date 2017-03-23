#include "CMatrice.h"
#include "Cexception.h"
#include <iostream>

using namespace std;

void main()
{
	try
	{
		unsigned int uiCompteurLignes;
		unsigned int uiCompteurColonnes;

		CMatrice<int> * MATIntMatrice1 = new CMatrice<int>();
		CMatrice<char> * MATIntMatriceA = new CMatrice<char>();

		cout<<"Matrice 1 (constructeur vide):\n";
		MATIntMatrice1->MATAfficherMatrice();

		int** ppiMat = (int **) malloc(sizeof(int) * 2);
		ppiMat[0] = (int *)malloc(sizeof(int) * 6);
		ppiMat[1] = (int *)malloc(sizeof(int) * 6);

		for(uiCompteurLignes = 0; uiCompteurLignes < 2; uiCompteurLignes++)
			for(uiCompteurColonnes = 0; uiCompteurColonnes < 6; uiCompteurColonnes++)
				ppiMat[uiCompteurLignes][uiCompteurColonnes] = uiCompteurLignes + uiCompteurColonnes;
	
		CMatrice<int> * MATIntMatrice2 = new CMatrice<int>(ppiMat, 2, 6);
		cout<<"Matrice 2 (constructeur de confort):\n";
		MATIntMatrice2->MATAfficherMatrice();
		
		CMatrice<int> * MATIntMatrice3 = new CMatrice<int>(*MATIntMatrice2);
		cout<<"Matrice 3 (constructeur de recopie):\n";
		MATIntMatrice3->MATAfficherMatrice();
		
		cout<<"Transposee de la matrice 3:\n";
		MATIntMatrice3->MTMATTransposeeMatrice().MATAfficherMatrice();

		cout<<"Matrice 4 (Multiplication de la matrice 3 par 4):\n";
		CMatrice<int> * MATIntMatrice4 = &(*MATIntMatrice3 * 4);
		MATIntMatrice4->MATAfficherMatrice();
		
		delete MATIntMatrice4;
		
		cout<<"Matrice 4 (Multiplication de 4 par la matrice 3):\n";
		MATIntMatrice4 = &(4 * *MATIntMatrice3);
		MATIntMatrice4->MATAfficherMatrice();
		
		/*cout<<"Multiplication de la matrice 3 par 4:\n";
		(4 * *MATIntMatrice3).MATAfficherMatrice();*/
		
		cout<<"Multiplication de la matrice 3 avec sa transposée:\n";
		(*MATIntMatrice3 * MATIntMatrice3->MTMATTransposeeMatrice()).MATAfficherMatrice();

		cout<<"Addition de la matrice 3 avec elle-même: \n";
		*MATIntMatrice4 = *MATIntMatrice3 + *MATIntMatrice3;
		MATIntMatrice4->MATAfficherMatrice();
		cout<<"Puis soustraction avec sa première moitié :\n";
		*MATIntMatrice4 = *MATIntMatrice4 - *MATIntMatrice3 / 2;
		MATIntMatrice4->MATAfficherMatrice();
		MATIntMatrice3->MATAfficherMatrice();

		char** ppcMat = (char **) malloc(sizeof(char) * 2);
		ppcMat[0] = (char *)malloc(sizeof(char) * 6);
		ppcMat[1] = (char *)malloc(sizeof(char) * 6);

		for(uiCompteurLignes = 0; uiCompteurLignes < 2; uiCompteurLignes++)
			for(uiCompteurColonnes = 0; uiCompteurColonnes < 6; uiCompteurColonnes++)
				ppiMat[uiCompteurLignes][uiCompteurColonnes] = uiCompteurLignes + uiCompteurColonnes;
		
		CMatrice<char> * MATIntMatriceA = new CMatrice<char>(ppcMat, 2, 6);
		cout<<"Matrice A (constructeur de confort):\n";
		MATIntMatriceA->MATAfficherMatrice();
		
		cout<<"Addition de la matrice A avec la matrice 1: \n";
		(*MATIntMatriceA + *MATIntMatrice1).MATAfficherMatrice();


		delete MATIntMatrice1;
		delete MATIntMatrice2;
		delete MATIntMatrice3;
		delete MATIntMatrice4;

		for(uiCompteurLignes = 0; uiCompteurLignes < 2; uiCompteurLignes++)
			free(ppiMat[uiCompteurLignes]);
		free(ppiMat);
	}
	catch(Cexception e)
	{
		//cout << e.EXCLire_Valeur() << " : " << e.EXCLire_Message() << endl;
	}
	while(1);
}


#include "CMatrice.h"
#include "Cexception.h"

/******************************************************************************
Constructeur par d�faut
*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet en cours est initialis�.
******************************************************************************/
template<class MType> CMatrice<MType>::CMatrice()
{
	uiMATnbLignes = 0;
	uiMATnbColonnes = 0;
	ppMTMATMatrice = (MType **)malloc(0);
	if(ppMTMATMatrice == nullptr)
	{
/*		Cexception * EXCexception = new Cexception(2, "Allocation �chou�e");
		throw *EXCexception;
	*/}
}

/******************************************************************************
Constructeur de recopie
*******************************************************************************
	Entr�e : Objet de la m�me classe
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet en cours est initialis� par recopie
******************************************************************************/
template<class MType> CMatrice<MType>::CMatrice(const CMatrice<MType> & MTMATMatrice)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = MTMATMatrice.uiMATnbLignes;
	uiMATnbColonnes = MTMATMatrice.uiMATnbColonnes;
	ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbLignes);
	if(ppMTMATMatrice == nullptr)
		throw Cexception(2, "Allocation �chou�e");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
		{
			//Cexception * EXCexception = new Cexception(2, "Allocation �chou�e");
			//throw *EXCexception;
		}

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];
	}
}

/******************************************************************************
Constructeur de confort 1
*******************************************************************************
	Entr�e : une matrice de type MType, uiLignes et uiColonnes deux naturels
	Necessit� : la matrice est de taille uiLignes * uiColonnes
	Sortie : Rien
	Entraine : L'objet en cours est initialis�.
******************************************************************************/
template<class MType> CMatrice<MType>::CMatrice(MType ** & ppMTMatrice, unsigned int uiLignes, unsigned int uiColonnes)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = uiLignes;
	uiMATnbColonnes = uiColonnes;
	ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbLignes);
	if(ppMTMATMatrice == nullptr)
	{
		//Cexception * EXCexception = new Cexception(2, "Allocation �chou�e");
		//throw * EXCexception;
	}

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
		{
			//Cexception * EXCexception = new Cexception(2, "Allocation �chou�e");
			//throw *EXCexception;
		}

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMatrice[uiCompteurLignes][uiCompteurColonnes];
	}
}

/******************************************************************************
Constructeur de confort 2
*******************************************************************************
	Entr�e : uiLignes et uiColonnes deux naturels
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet en cours est initialis�, sa matrice est de taille uiLignes * uiColonnes remplir de 0;
******************************************************************************/
template<class MType> CMatrice<MType>::CMatrice(unsigned int uiLignes, unsigned int uiColonnes)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = uiLignes;
	uiMATnbColonnes =uiColonnes;
	ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbLignes);
/*	if(ppMTMATMatrice == nullptr)
		throw Cexception(2, "Allocation �chou�e");
		*/
	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
		{
/*			Cexception * EXCexception = new Cexception(2, "Allocation �chou�e");
			throw *EXCexception;
	*/	}

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = 0;
	}
}

/******************************************************************************
Destructeur
*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet en cours d�sallou�
******************************************************************************/
template<class MType> CMatrice<MType>::~CMatrice()
{
	unsigned int uiCompteurLignes;

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		free(ppMTMATMatrice[uiCompteurLignes]);
	free(ppMTMATMatrice);
}

/******************************************************************************
MTMATTransposeeMatrice
*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : r�f�rence sur un objet de type CMatrice<MType>
	Entraine : Retourne la transpos�e de la matrice
******************************************************************************/
template<class MType> CMatrice<MType> & CMatrice<MType>::MTMATTransposeeMatrice() const
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	MType ** ppMTMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbColonnes);
	if(ppMTMatrice == nullptr)
		throw Cexception(2, "Allocation �chou�e");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbColonnes; uiCompteurLignes++)
	{
		ppMTMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbLignes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
			throw Cexception(2, "Allocation �chou�e");
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbLignes; uiCompteurColonnes++)
			ppMTMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMATMatrice[uiCompteurColonnes][uiCompteurLignes];
	}
	
	CMatrice<MType> * MTMATMatrice = new CMatrice<MType>(ppMTMatrice, uiCompteurLignes, uiCompteurColonnes);

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbColonnes; uiCompteurLignes++)
		free(ppMTMatrice[uiCompteurLignes]);
	free(ppMTMatrice);

	return *MTMATMatrice;
}

/******************************************************************************
MATAfficherMatrice
*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : Rien
	Entraine : Affiche la matrice
******************************************************************************/
template<class MType> void CMatrice<MType>::MTMATAfficherMatrice() const
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			cout << ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] << " ";
		cout << endl;
	}
}

/******************************************************************************
MTMATgetNbLignes
*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : naturel
	Entraine : Retourne le nombre de lignes de la matrice
******************************************************************************/
template<class MType> unsigned int CMatrice<MType>::MTMATgetNbLignes() const
{
	return uiMATnbLignes;
}

/******************************************************************************
MTMATgetNbColonnes
*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : naturel
	Entraine : Retourne le nombre de colonnes de la matrice
******************************************************************************/
template<class MType> unsigned int CMatrice<MType>::MTMATgetNbColonnes() const
{
	return uiMATnbColonnes;
}

/******************************************************************************
MTMATget
*******************************************************************************
	Entr�e : uiLigne, uiColonnes deux naturel
	Necessit� : uiLigne et uiColonne ne sont pas plus grand que les dimensions de la matrice
	Sortie : MType
	Entraine : Retourne l'�l�ment de la matrice � la ligne uiLigne et � la colonne uiColonne
******************************************************************************/
template<class MType> MType CMatrice<MType>::MTMATget(unsigned int uiLigne, unsigned int uiColonne)
{
	if(uiLigne > uiMATnbLignes || uiColonne > uiMATnbColonnes)
		throw Cexception(4, "Tailles en param�tre trop grandes");
	return ppMTMATMatrice[uiLigne][uiColonne];
}

/******************************************************************************
MTMATset
*******************************************************************************
	Entr�e : uiLigne, uiColonnes deux naturel, MTValeur la valeur � stocker
	Necessit� : uiLigne et uiColonne ne sont pas plus grand que les dimensions de la matrice
	Sortie : Rien
	Entraine : L'�l�ment � la position uiLigne, uiColonnes a �t� remplac�
******************************************************************************/
template<class MType> MType CMatrice<MType>::MTMATset(unsigned int uiLigne, unsigned int uiColonne, MType MTValeur)
{
	if(uiLigne > uiMATnbLignes || uiColonne > uiMATnbColonnes)
		throw Cexception(4, "Tailles en param�tre trop grandes");
	ppMTMATMatrice[uiLigne][uiColonne] = MTValeur;
}

/******************************************************************************
MTMATsetMatrice
*******************************************************************************
	Entr�e : uiLigne, uiColonnes deux naturel, ppMTMatrice une matrice de type MType
	Necessit� : ppMTMatrice est de taille uiLignes * uiColonne
	Sortie : Rien
	Entraine : Les attributs de l'objet ont �t� remplac�s
******************************************************************************/
template<class MType> void CMatrice<MType>::MTMATsetMatrice(const MType ** ppMTMatrice, const unsigned int uiLignes, const unsigned int uiColonnes)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	if(uiLignes > uiMATnbLignes)
	{
		ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * uiLignes);
		if(ppMTMATMatrice == nullptr)
			throw Cexception(3, "R�allocation �chou�e");
	}
	else if(uiLignes < uiMATnbLignes)
	{
		for(uiCompteurLignes = uiMATnbLignes; uiCompteurLignes > uiLignes; uiCompteurLignes--)
			free(ppMTMATMatrice[uiCompteurLignes]);
		ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * uiLignes);
		if(ppMTMATMatrice == nullptr)
			throw Cexception(3, "R�allocation �chou�e");
	}
	uiMATnbLignes = uiLignes;

	if(uiColonnes > uiMATnbColonnes || uiColonnes < uiMATnbColonnes)
	{
		for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		{
			ppMTMATMatrice[uiCompteurLignes] = (MType *)realloc(ppMTMATMatrice[uiCompteurLignes], sizeof(MType) * uiColonnes);
			if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
				throw Cexception(3, "R�allocation �chou�e");
		}
	}
	uiMATnbColonnes = uiColonnes;

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMatrice[uiCompteurLignes][uiCompteurColonnes];
}

/******************************************************************************
surcharge de operator=
*******************************************************************************
	Entr�e : un objet du m�me type
	Necessit� : N�ant
	Sortie : Une r�f�rence sur l'objet en cours qui a �t� modifi�
	Entraine : L'objet en cours est une copie de l'objet en param�tre
******************************************************************************/
template<class MType> CMatrice<MType> & CMatrice<MType>::operator=(CMatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	if(MTMATMatrice.uiMATnbLignes > uiMATnbLignes)
	{
		ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * MTMATMatrice.uiMATnbLignes);
/*		if(ppMTMATMatrice == nullptr)
			throw Cexception(3, "R�allocation �chou�e");
	*/}
	else if(MTMATMatrice.uiMATnbLignes < uiMATnbLignes)
	{
		for(uiCompteurLignes = uiMATnbLignes; uiCompteurLignes > MTMATMatrice.uiMATnbLignes; uiCompteurLignes--)
			free(ppMTMATMatrice[uiCompteurLignes]);
		ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * MTMATMatrice.uiMATnbLignes);
	/*	if(ppMTMATMatrice == nullptr)
			throw Cexception(3, "R�allocation �chou�e");
	*/}
	uiMATnbLignes = MTMATMatrice.uiMATnbLignes;

	if(MTMATMatrice.uiMATnbColonnes > uiMATnbColonnes || MTMATMatrice.uiMATnbColonnes < uiMATnbColonnes)
	{
		for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		{
			ppMTMATMatrice[uiCompteurLignes] = (MType *)realloc(ppMTMATMatrice[uiCompteurLignes], sizeof(MType) * MTMATMatrice.uiMATnbColonnes);
		/*	if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
				throw Cexception(3, "R�allocation �chou�e");
		*/}
	}
	uiMATnbColonnes = MTMATMatrice.uiMATnbColonnes;

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];

	return *this;
}

template<class MType> CMatrice<MType> & CMatrice<MType>::operator*(MType MTValeur)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	CMatrice<MType> * MTMATNewMatrice = new CMatrice<MType>(ppMTMATMatrice, uiMATnbLignes, uiMATnbColonnes);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATNewMatrice->uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATNewMatrice->uiMATnbColonnes; uiCompteursColonnes++)
			MTMATNewMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteursColonnes] = MTMATNewMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteursColonnes] * MTValeur;

	return *MTMATNewMatrice;
}

template<class MType> CMatrice<MType> & CMatrice<MType>::operator*(CMatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignesMAT1, uiCompteurColonnesMAT2;
	unsigned int uiCompteurOperation;
	MType MTvaleurCase;

	if(uiMATnbColonnes != MTMATMatrice.uiMATnbLignes)
		throw Cexception(3, "Calcul sur des matrices de taille imcompatible");


	MType ** ppMTMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbColonnes);
	if(ppMTMatrice == nullptr)
		throw Cexception(2, "Allocation �chou�e");

	for(uiCompteurLignesMAT1 = 0; uiCompteurLignesMAT1 < uiMATnbLignes; uiCompteurLignesMAT1++)
	{
		ppMTMatrice[uiCompteurLignesMAT1] = (MType *)malloc(sizeof(MType) * MTMATMatrice.uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignesMAT1] == nullptr)
			throw Cexception(2, "Allocation �chou�e");
	}

	for(uiCompteurLignesMAT1 = 0; uiCompteurLignesMAT1 < uiMATnbLignes; uiCompteurLignesMAT1++)
	{
		for(uiCompteurColonnesMAT2 = 0; uiCompteurColonnesMAT2 < MTMATMatrice.uiMATnbColonnes; uiCompteurColonnesMAT2++)
		{
			MTvaleurCase = 0;
			for(uiCompteurOperation = 0; uiCompteurOperation < MTMATMatrice.uiMATnbColonnes; uiCompteurOperation++)
			{
				MTvaleurCase = MTvaleurCase + ppMTMATMatrice[uiCompteurLignesMAT1][uiCompteurOperation] * MTMATMatrice.ppMTMATMatrice[uiCompteurOperation][uiCompteurColonnesMAT2];
			}
			ppMTMatrice[uiCompteurLignesMAT1][uiCompteurColonnesMAT2] = MTvaleurCase;
		}
	}

	return *(new CMatrice<MType>(ppMTMatrice, uiMATnbLignes, MTMATMatrice.uiMATnbColonnes));
}

template<class MType> CMatrice<MType> & CMatrice<MType>::operator/(MType MTValeur)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	CMatrice<MType> * MTMATNewMatrice = new CMatrice<MType>(ppMTMATMatrice, uiMATnbLignes, uiMATnbColonnes);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < uiMATnbColonnes; uiCompteursColonnes++)
			MTMATNewMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteursColonnes] = MTMATNewMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteursColonnes] / MTValeur;

	return *MTMATNewMatrice;
}

template<class MType> CMatrice<MType> & CMatrice<MType>::operator+(CMatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

/*	if(uiMATnbLignes != MTMATMatrice.uiMATnbLignes || uiMATnbColonnes != MTMATMatrice.uiMATnbColonnes)
		throw Cexception(3, "Calcule sur matrices de tailles incompatibles");
		*/
	CMatrice<MType> * MTMATNewMatrice = new CMatrice<MType>(uiMATnbLignes, uiMATnbColonnes);

	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATMatrice.uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < MTMATMatrice.uiMATnbColonnes; uiCompteurColonnes++)
			MTMATNewMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] + MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];

	return *MTMATNewMatrice;
}

template<class MType> CMatrice<MType> & CMatrice<MType>::operator-(CMatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

/*	if(uiMATnbLignes != MTMATMatrice.uiMATnbLignes || uiMATnbColonnes != MTMATMatrice.uiMATnbColonnes)
		throw Cexception(3, "Calcule sur matrices de tailles incompatibles");
		*/
	CMatrice<MType> * MTMATNewMatrice = new CMatrice<MType>(uiMATnbLignes, uiMATnbColonnes);

	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATMatrice.uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < MTMATMatrice.uiMATnbColonnes; uiCompteurColonnes++)
			MTMATNewMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] - MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];

	return *MTMATNewMatrice;
}
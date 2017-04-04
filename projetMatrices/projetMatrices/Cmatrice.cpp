#include "CMatrice.h"
#include "Cexception.h"

/******************************************************************************
Constructeur par défaut
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé.
******************************************************************************/
template<class MType> CMatrice<MType>::CMatrice()
{
	uiMATnbLignes = 0;
	uiMATnbColonnes = 0;

	ppMTMATMatrice = (MType **)malloc(0);
	if(ppMTMATMatrice == nullptr)
		throw Cexception(2, "Dans le constructeur de CMatrice");
}

/******************************************************************************
Constructeur de recopie
*******************************************************************************
	Entrée : Objet de la même classe
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé par recopie
******************************************************************************/
template<class MType> CMatrice<MType>::CMatrice(const CMatrice<MType> & MTMATMatrice)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = MTMATMatrice.uiMATnbLignes;
	uiMATnbColonnes = MTMATMatrice.uiMATnbColonnes;

	ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbLignes);
	if(ppMTMATMatrice == nullptr)
		throw Cexception(2, "Dans le constructeur de recopie de CMatrice");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
			throw Cexception(2, "Dans le constructeur de recopie de CMatrice");

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];
	}
}

/******************************************************************************
Constructeur de confort 1
*******************************************************************************
	Entrée : une matrice de type MType, uiLignes et uiColonnes deux naturels
	Necessité : la matrice est de taille uiLignes * uiColonnes
	Sortie : Rien
	Entraine : L'objet en cours est initialisé.
******************************************************************************/
template<class MType> CMatrice<MType>::CMatrice(MType ** & ppMTMatrice, unsigned int uiLignes, unsigned int uiColonnes)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = uiLignes;
	uiMATnbColonnes = uiColonnes;
	ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbLignes);
	if(ppMTMATMatrice == nullptr)
		throw Cexception(2, "Dans le constructeur de recopie de CMatrice");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
			throw Cexception(2, "Dans le constructeur de recopie de CMatrice");

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMatrice[uiCompteurLignes][uiCompteurColonnes];
	}
}

/******************************************************************************
Constructeur de confort 2
*******************************************************************************
	Entrée : uiLignes et uiColonnes deux naturels
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé, sa matrice est de taille uiLignes * uiColonnes remplir de 0;
******************************************************************************/
template<class MType> CMatrice<MType>::CMatrice(unsigned int uiLignes, unsigned int uiColonnes)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = uiLignes;
	uiMATnbColonnes =uiColonnes;
	ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbLignes);
	if(ppMTMATMatrice == nullptr)
		throw Cexception(2, "Dans le constructeur de recopie de CMatrice");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
			throw Cexception(2, "Dans le constructeur de recopie de CMatrice");

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = 0;
	}
}

/******************************************************************************
Destructeur
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours désalloué
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
	Entrée : Rien
	Necessité : Néant
	Sortie : référence sur un objet de type CMatrice<MType>
	Entraine : Retourne la transposée de la matrice
******************************************************************************/
template<class MType> CMatrice<MType> & CMatrice<MType>::MTMATTransposeeMatrice() const
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;
	CMatrice<MType> * MTMATMatrice;

	MType ** ppMTMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbColonnes);
	if(ppMTMatrice == nullptr)
		throw Cexception(2, "Dans le constructeur de recopie de CMatrice");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbColonnes; uiCompteurLignes++)
	{
		ppMTMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbLignes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
			throw Cexception(2, "Dans le constructeur de recopie de CMatrice");

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbLignes; uiCompteurColonnes++)
			ppMTMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMATMatrice[uiCompteurColonnes][uiCompteurLignes];
	}
	
	MTMATMatrice = new CMatrice<MType>(ppMTMatrice, uiCompteurLignes, uiCompteurColonnes);

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbColonnes; uiCompteurLignes++)
		free(ppMTMatrice[uiCompteurLignes]);
	free(ppMTMatrice);

	return *MTMATMatrice;
}

/******************************************************************************
MATAfficherMatrice
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
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
	Entrée : Rien
	Necessité : Néant
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
	Entrée : Rien
	Necessité : Néant
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
	Entrée : uiLigne, uiColonnes deux naturel
	Necessité : uiLigne et uiColonne ne sont pas plus grand que les dimensions de la matrice
	Sortie : MType
	Entraine : Retourne l'élément de la matrice à la ligne uiLigne et à la colonne uiColonne
******************************************************************************/
template<class MType> MType CMatrice<MType>::MTMATget(unsigned int uiLigne, unsigned int uiColonne)
{
	if(uiLigne > uiMATnbLignes || uiColonne > uiMATnbColonnes)
		throw Cexception(4, "Indices en parametre trop grands (Methode MTMATget)");

	return ppMTMATMatrice[uiLigne][uiColonne];
}

/******************************************************************************
MTMATset
*******************************************************************************
	Entrée : uiLigne, uiColonnes deux naturel, MTValeur la valeur à stocker
	Necessité : uiLigne et uiColonne ne sont pas plus grand que les dimensions de la matrice
	Sortie : Rien
	Entraine : L'élément à la position uiLigne, uiColonnes a été remplacé
******************************************************************************/
template<class MType> MType CMatrice<MType>::MTMATset(unsigned int uiLigne, unsigned int uiColonne, MType MTValeur)
{
	if(uiLigne > uiMATnbLignes || uiColonne > uiMATnbColonnes)
		throw Cexception(4, "Indices en parametre trop grands (Methode MTMATset)");

	ppMTMATMatrice[uiLigne][uiColonne] = MTValeur;
}

/******************************************************************************
MTMATsetMatrice
*******************************************************************************
	Entrée : uiLigne, uiColonnes deux naturel, ppMTMatrice une matrice de type MType
	Necessité : ppMTMatrice est de taille uiLignes * uiColonne
	Sortie : Rien
	Entraine : Les attributs de l'objet ont été remplacés
******************************************************************************/
template<class MType> void CMatrice<MType>::MTMATsetMatrice(const MType ** ppMTMatrice, const unsigned int uiLignes, const unsigned int uiColonnes)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	if(uiLignes > uiMATnbLignes)
	{
		ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * uiLignes);
		if(ppMTMATMatrice == nullptr)
			throw Cexception(2, "Dans la methode MTMATsetMatrice");
	}
	else if(uiLignes < uiMATnbLignes)
	{
		for(uiCompteurLignes = uiMATnbLignes; uiCompteurLignes > uiLignes; uiCompteurLignes--)
			free(ppMTMATMatrice[uiCompteurLignes]);

		ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * uiLignes);
		if(ppMTMATMatrice == nullptr)
			throw Cexception(2, "Dans la methode MTMATsetMatrice");
	}
	uiMATnbLignes = uiLignes;

	if(uiColonnes > uiMATnbColonnes || uiColonnes < uiMATnbColonnes)
	{
		for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		{
			ppMTMATMatrice[uiCompteurLignes] = (MType *)realloc(ppMTMATMatrice[uiCompteurLignes], sizeof(MType) * uiColonnes);
			if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
				throw Cexception(2, "Dans la methode MTMATsetMatrice");
		}
	}
	uiMATnbColonnes = uiColonnes;

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMatrice[uiCompteurLignes][uiCompteurColonnes];
}

/******************************************************************************
surcharge de l'opérateur d'affectation
*******************************************************************************
	Entrée : un objet du même type
	Necessité : Néant
	Sortie : Une référence sur l'objet en cours qui a été modifié
	Entraine : L'objet en cours est une copie de l'objet en paramètre
******************************************************************************/
template<class MType> CMatrice<MType> & CMatrice<MType>::operator=(CMatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	//Dans le cas où notre objet n'a pas été préalablement alloué
	if(ppMTMATMatrice == nullptr)
	{
		ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * MTMATMatrice.uiMATnbLignes);
		if(ppMTMATMatrice == nullptr)
			throw Cexception(2, "Lors d'une affectation d'une CMatrice dans une autre");
		uiMATnbLignes = MTMATMatrice.uiMATnbLignes;
		
		for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		{
			ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * MTMATMatrice.uiMATnbColonnes);
			if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
				throw Cexception(2, "Lors d'une affectation d'une CMatrice dans une autre");
		}
		uiMATnbColonnes = MTMATMatrice.uiMATnbColonnes;
	}
	else //Sinon on realloue de la bonne taille
	{
		if(MTMATMatrice.uiMATnbLignes > uiMATnbLignes)
		{
			ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * MTMATMatrice.uiMATnbLignes);
			if(ppMTMATMatrice == nullptr)
				throw Cexception(2, "Lors d'une affectation d'une CMatrice dans une autre");
		}
		else if(MTMATMatrice.uiMATnbLignes < uiMATnbLignes)
		{
			for(uiCompteurLignes = uiMATnbLignes; uiCompteurLignes > MTMATMatrice.uiMATnbLignes; uiCompteurLignes--)
				free(ppMTMATMatrice[uiCompteurLignes]);
			ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * MTMATMatrice.uiMATnbLignes);
			if(ppMTMATMatrice == nullptr)
				throw Cexception(2, "Lors d'une affectation d'une CMatrice dans une autre");
		}
		uiMATnbLignes = MTMATMatrice.uiMATnbLignes;

		if(MTMATMatrice.uiMATnbColonnes > uiMATnbColonnes || MTMATMatrice.uiMATnbColonnes < uiMATnbColonnes)
		{
			for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
			{
				ppMTMATMatrice[uiCompteurLignes] = (MType *)realloc(ppMTMATMatrice[uiCompteurLignes], sizeof(MType) * MTMATMatrice.uiMATnbColonnes);
				if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
					throw Cexception(2, "Lors d'une affectation d'une CMatrice dans une autre");
			}
		}
		uiMATnbColonnes = MTMATMatrice.uiMATnbColonnes;
	}

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];

	return *this;
}

/******************************************************************************
surcharge de operator*
*******************************************************************************
	Entrée : une valeur de type MType
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType> CMatrice<MType> & CMatrice<MType>::operator*(MType MTValeur)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	CMatrice<MType> * MTMATNouvelleMatrice = new CMatrice<MType>(ppMTMATMatrice, uiMATnbLignes, uiMATnbColonnes);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATNouvelleMatrice->uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATNouvelleMatrice->uiMATnbColonnes; uiCompteursColonnes++)
			MTMATNouvelleMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteursColonnes] = MTMATNouvelleMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteursColonnes] * MTValeur;

	return *MTMATNouvelleMatrice;
}

/******************************************************************************
surcharge de operator*
*******************************************************************************
	Entrée : un objet CMatrice du même type que l'objet en cours
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType> CMatrice<MType> & CMatrice<MType>::operator*(CMatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignesMAT1, uiCompteurColonnesMAT2;
	unsigned int uiCompteurOperation;
	MType MTvaleurCase;
	MType ** ppMTMatrice;

	if(uiMATnbColonnes != MTMATMatrice.uiMATnbLignes)
			throw Cexception(3, "Tailles des matrices incompatible (dans la surcharge operator*(CMatrice<MType> const &)");


	ppMTMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbColonnes);
	if(ppMTMatrice == nullptr)
		throw Cexception(1, "Dans la surcharge operator*(CMatrice<MType> const &)");

	for(uiCompteurLignesMAT1 = 0; uiCompteurLignesMAT1 < uiMATnbLignes; uiCompteurLignesMAT1++)
	{
		ppMTMatrice[uiCompteurLignesMAT1] = (MType *)malloc(sizeof(MType) * MTMATMatrice.uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignesMAT1] == nullptr)
			throw Cexception(1, "Dans la surcharge operator*(CMatrice<MType> const &)");
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

/******************************************************************************
surcharge de operator/
*******************************************************************************
	Entrée : un objet CMatrice du même type que l'objet en cours
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType> CMatrice<MType> & CMatrice<MType>::operator/(MType MTValeur)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	CMatrice<MType> * MTMATNouvelleMatrice = new CMatrice<MType>(ppMTMATMatrice, uiMATnbLignes, uiMATnbColonnes);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < uiMATnbColonnes; uiCompteursColonnes++)
			MTMATNouvelleMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteursColonnes] = MTMATNouvelleMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteursColonnes] / MTValeur;

	return *MTMATNouvelleMatrice;
}

/******************************************************************************
surcharge de operator+
*******************************************************************************
	Entrée : un objet CMatrice du même type que l'objet en cours
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType> CMatrice<MType> & CMatrice<MType>::operator+(CMatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;
	CMatrice<MType> * MTMATNouvelleMatrice;

	if(uiMATnbLignes != MTMATMatrice.uiMATnbLignes || uiMATnbColonnes != MTMATMatrice.uiMATnbColonnes)
		throw Cexception(3, "Tailles des matrices incompatible (dans la surcharge operator+(CMatrice<MType> const &)");
		
	MTMATNouvelleMatrice = new CMatrice<MType>(uiMATnbLignes, uiMATnbColonnes);

	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATMatrice.uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < MTMATMatrice.uiMATnbColonnes; uiCompteurColonnes++)
			MTMATNouvelleMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] + MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];

	return *MTMATNouvelleMatrice;
}

/******************************************************************************
surcharge de operator-
*******************************************************************************
	Entrée : un objet CMatrice du même type que l'objet en cours
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType> CMatrice<MType> & CMatrice<MType>::operator-(CMatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	if(uiMATnbLignes != MTMATMatrice.uiMATnbLignes || uiMATnbColonnes != MTMATMatrice.uiMATnbColonnes)
		throw Cexception(3, "Tailles des matrices incompatible (dans la surcharge operator-(CMatrice<MType> const &)");
	CMatrice<MType> * MTMATNouvelleMatrice = new CMatrice<MType>(uiMATnbLignes, uiMATnbColonnes);

	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATMatrice.uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < MTMATMatrice.uiMATnbColonnes; uiCompteurColonnes++)
			MTMATNouvelleMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] - MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];

	return *MTMATNouvelleMatrice;
}

/******************************************************************************
surcharge de operator* de double
*******************************************************************************
	Entrée : un double et un objet CMatrice de type générique
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType> CMatrice<MType> & operator*(double dValeur, CMatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	CMatrice<MType> * MTMATNouvelleMatrice = new CMatrice<MType>(MTMATMatrice);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATNouvelleMatrice->MTMATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATNouvelleMatrice->MTMATgetNbColonnes(); uiCompteursColonnes++)
			MTMATNouvelleMatrice->MTMATset(uiCompteurLignes, uiCompteursColonnes, MTMATNouvelleMatrice->MTMATget(uiCompteurLignes, uiCompteursColonnes) * dValeur);

	return *MTMATNouvelleMatrice;
}
#include "CMatrice.h"
#include "Cexception.h"

template<class MType> CMatrice<MType>::CMatrice()
{
	uiMATnbLignes = 0;
	uiMATnbColonnes = 0;
	ppMTMATMatrice = (MType **)malloc(0);
	if(ppMTMATMatrice == nullptr)
	{
		Cexception * EXCexception = new Cexception(2, "Allocation échouée");
		throw *EXCexception;
	}
}

template<class MType> CMatrice<MType>::CMatrice(const CMatrice<MType> & MTMATMatrice)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = MTMATMatrice.uiMATnbLignes;
	uiMATnbColonnes = MTMATMatrice.uiMATnbColonnes;
	ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbLignes);
	if(ppMTMATMatrice == nullptr)
		throw Cexception(2, "Allocation échouée");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
		{
			Cexception * EXCexception = new Cexception(2, "Allocation échouée");
			throw *EXCexception;
		}

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];
	}
}

template<class MType> CMatrice<MType>::CMatrice(MType ** & ppMTMatrice, unsigned int uiLignes, unsigned int uiColonnes)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = uiLignes;
	uiMATnbColonnes = uiColonnes;
	ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbLignes);
	if(ppMTMATMatrice == nullptr)
	{
		Cexception * EXCexception = new Cexception(2, "Allocation échouée");
		throw * EXCexception;
	}

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
		{
			Cexception * EXCexception = new Cexception(2, "Allocation échouée");
			throw *EXCexception;
		}

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMatrice[uiCompteurLignes][uiCompteurColonnes];
	}
}

template<class MType> CMatrice<MType>::CMatrice(unsigned int uiLignes, unsigned int uiColonnes)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = uiLignes;
	uiMATnbColonnes =uiColonnes;
	ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbLignes);
	if(ppMTMATMatrice == nullptr)
		throw Cexception(2, "Allocation échouée");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
		{
			Cexception * EXCexception = new Cexception(2, "Allocation échouée");
			throw *EXCexception;
		}

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = 0;
	}
}

template<class MType> CMatrice<MType>::~CMatrice()
{
	unsigned int uiCompteurLignes;

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		free(ppMTMATMatrice[uiCompteurLignes]);
	free(ppMTMATMatrice);
}

//Methodes
template<class MType> CMatrice<MType> & CMatrice<MType>::MTMATTransposeeMatrice() const
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	MType ** ppMTMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbColonnes);
	if(ppMTMatrice == nullptr)
		throw Cexception(2, "Allocation échouée");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbColonnes; uiCompteurLignes++)
	{
		ppMTMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbLignes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
			throw Cexception(2, "Allocation échouée");
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbLignes; uiCompteurColonnes++)
			ppMTMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMATMatrice[uiCompteurColonnes][uiCompteurLignes];
	}
	
	CMatrice<MType> * MTMATMatrice = new CMatrice<MType>(ppMTMatrice, uiCompteurLignes, uiCompteurColonnes);

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbColonnes; uiCompteurLignes++)
		free(ppMTMatrice[uiCompteurLignes]);
	free(ppMTMatrice);

	return *MTMATMatrice;
}

template<class MType> void CMatrice<MType>::MATAfficherMatrice() const
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			cout << ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] << " ";
		cout << endl;
	}
}

//Accesseurs
template<class MType> unsigned int CMatrice<MType>::MATgetNbLignes() const
{
	return uiMATnbLignes;
}

template<class MType> unsigned int CMatrice<MType>::MATgetNbColonnes() const
{
	return uiMATnbColonnes;
}

template<class MType> void CMatrice<MType>::MATsetMatrice(const MType ** ppMTMatrice, const unsigned int uiLignes, const unsigned int uiColonnes)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	if(uiLignes > uiMATnbLignes)
	{
		ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * uiLignes);
		if(ppMTMATMatrice == nullptr)
			throw Cexception(3, "Réallocation échouée");
	}
	else if(uiLignes < uiMATnbLignes)
	{
		for(uiCompteurLignes = uiMATnbLignes; uiCompteurLignes > uiLignes; uiCompteurLignes--)
			free(ppMTMATMatrice[uiCompteurLignes]);
		ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * uiLignes);
		if(ppMTMATMatrice == nullptr)
			throw Cexception(3, "Réallocation échouée");
	}
	uiMATnbLignes = uiLignes;

	if(uiColonnes > uiMATnbColonnes || uiColonnes < uiMATnbColonnes)
	{
		for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		{
			ppMTMATMatrice[uiCompteurLignes] = (MType *)realloc(ppMTMATMatrice[uiCompteurLignes], sizeof(MType) * uiColonnes);
			if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
				throw Cexception(3, "Réallocation échouée");
		}
	}
	uiMATnbColonnes = uiColonnes;

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMatrice[uiCompteurLignes][uiCompteurColonnes];
}

//Operateurs
template<class MType> CMatrice<MType> & CMatrice<MType>::operator*(MType MTValeur)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	CMatrice<MType> * MTMATMatrice = new CMatrice<MType>(ppMTMATMatrice, uiMATnbLignes, uiMATnbColonnes);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATMatrice->uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATMatrice->uiMATnbColonnes; uiCompteursColonnes++)
			MTMATMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteursColonnes] = MTMATMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteursColonnes] * MTValeur;

	return *MTMATMatrice;
}

template<class MType> CMatrice<MType> & operator*(MType MTValeur, CMatrice<MType> const & MTMATMatrice)
{
	/*
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	CMatrice<MType> * MTMATNewMatrice = new CMatrice<MType>(MTMATMatrice.ppMTMATMatrice, MTMATMatrice.uiMATnbLignes, MTMATMatrice.uiMATnbColonnes);
	
	for(uiCompteurLignes = 0; uisCompteurLignes < MTMATMatrice->uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATMatrice->uiMATnbColonnes; uiCompteursColonnes++)
			MTMATNewMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteursColonnes] *= MTValeur;*/
	CMatrice<MType> * MTMATMatriceTemp = new CMatrice<MType>(MTMATMatrice);
	CMatrice<MType> & MTMATNewMatrice = MTMATMatriceTemp->operator*(MTValeur);
	delete MTMATMatriceTemp;

	return MTMATNewMatrice;
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
		throw Cexception(2, "Allocation échouée");

	for(uiCompteurLignesMAT1 = 0; uiCompteurLignesMAT1 < uiMATnbLignes; uiCompteurLignesMAT1++)
	{
		ppMTMatrice[uiCompteurLignesMAT1] = (MType *)malloc(sizeof(MType) * MTMATMatrice.uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignesMAT1] == nullptr)
			throw Cexception(2, "Allocation échouée");
	}

	for(uiCompteurLignesMAT1 = 0; uiCompteurLignesMAT1 < uiMATnbLignes; uiCompteurLignesMAT1++)
	{
		for(uiCompteurColonnesMAT2 = 0; uiCompteurColonnesMAT2 < MTMATMatrice.uiMATnbColonnes; uiCompteurColonnesMAT2++)
		{
			MTvaleurCase = 0;
			for(uiCompteurOperation = 0; uiCompteurOperation < uiMATnbColonnes; uiCompteurOperation++)
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

	CMatrice<MType> * MTMATMatrice = new CMatrice<MType>(ppMTMATMatrice, uiMATnbLignes, uiMATnbColonnes);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATMatrice->uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATMatrice->uiMATnbColonnes; uiCompteursColonnes++)
			MTMATMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteursColonnes] = MTMATMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteursColonnes] / MTValeur;

	return *MTMATMatrice;
}

template<class MType> CMatrice<MType> & CMatrice<MType>::operator+(CMatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	if(uiMATnbLignes != MTMATMatrice.uiMATnbLignes || uiMATnbLignes != MTMATMatrice.uiMATnbLignes)
		throw Cexception(3, "Calcule sur matrices de tailles incompatibles");

	CMatrice<MType> * MTMATNewMatrice = new CMatrice<MType>(uiMATnbLignes, uiMATnbColonnes);

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			MTMATNewMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] + MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];

	return *MTMATNewMatrice;
}

template<class MType> CMatrice<MType> & CMatrice<MType>::operator-(CMatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	if(uiMATnbLignes != MTMATMatrice.uiMATnbLignes || uiMATnbLignes != MTMATMatrice.uiMATnbLignes)
		throw Cexception(3, "Calcule sur matrices de tailles incompatibles");

	CMatrice<MType> * MTMATNewMatrice = new CMatrice<MType>(uiMATnbLignes, uiMATnbColonnes);

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			MTMATNewMatrice->ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] - MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];

	return *MTMATNewMatrice;
}

template<class MType> CMatrice<MType> & CMatrice<MType>::operator=(CMatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	if(MTMATMatrice.uiMATnbLignes > uiMATnbLignes)
	{
		ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * MTMATMatrice.uiMATnbLignes);
		if(ppMTMATMatrice == nullptr)
			throw Cexception(3, "Réallocation échouée");
	}
	else if(MTMATMatrice.uiMATnbLignes < uiMATnbLignes)
	{
		for(uiCompteurLignes = uiMATnbLignes; uiCompteurLignes > MTMATMatrice.uiMATnbLignes; uiCompteurLignes--)
			free(ppMTMATMatrice[uiCompteurLignes]);
		ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * MTMATMatrice.uiMATnbLignes);
		if(ppMTMATMatrice == nullptr)
			throw Cexception(3, "Réallocation échouée");
	}
	uiMATnbLignes = MTMATMatrice.uiMATnbLignes;

	if(MTMATMatrice.uiMATnbColonnes > uiMATnbColonnes || MTMATMatrice.uiMATnbColonnes < uiMATnbColonnes)
	{
		for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		{
			ppMTMATMatrice[uiCompteurLignes] = (MType *)realloc(ppMTMATMatrice[uiCompteurLignes], sizeof(MType) * MTMATMatrice.uiMATnbColonnes);
			if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
				throw Cexception(3, "Réallocation échouée");
		}
	}
	uiMATnbColonnes = MTMATMatrice.uiMATnbColonnes;

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];

	return *this;
}

#include "CMatrice.h"
#include "CException.h"

CMatrice::CMatrice()
{
	uiMATnbLignes = 0;
	uiMATnbColonnes = 0;
	ppMTMATMatrice = (** MType)malloc(0);
	if(ppMTMATMatrice == nullptr)
		throw new CException(2, "Allocation échouée");
}

CMatrice::CMatrice(CMatrice<MType> MTMATMatrice)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = MTMATMatrice.uiMATnbLignes;
	uiMATnbColonnes = MTMATMatrice.uiMATnbColonnes;
	ppMTMATMatrice = (** MType)malloc(sizeof(* MType) * uiMATnbLignes);
	if(ppMTMATMatrice == nullptr)
		throw new CException(2, "Allocation échouée");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (* MType)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
			throw new CException(2, "Allocation échouée");

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];
	}
}

CMatrice::CMatrice(MType ** & ppMTMatrice, unsigned int uiLignes, unsigned int uiColonnes)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = uiLignes;
	uiMATnbColonnes = uiColonnes;
	ppMTMATMatrice = (** MType)malloc(sizeof(* MType) * uiMATnbLignes);
	if(ppMTMATMatrice == nullptr)
		throw new CException(2, "Allocation échouée");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (* MType)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
			throw new CException(2, "Allocation échouée");

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMatrice[uiCompteurLignes][uiCompteurColonnes];
	}
}

CMatrice::~CMatrice()
{
	unsigned int uiCompteurLignes;

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		free(ppMTMATMatrice[uiCompteurLignes]);
	free(ppMTMATMatrice);
}

//Methodes
CMatrice::CMatrice<MType> MTMATTransposeeMatrice() const
{

}

CMatrice::void MATAfficherMatrice() const
{

}

//Accesseurs
CMatrice::unsigned int MATgetNbLignes() const
{

}

CMatrice::unsigned int MATgetNbColonnes() const
{

}

CMatrice::MType ** & MATgetMatrice() const
{

}

CMatrice::void MATsetMatrice(MType ** & MTMATMatrice, unsigned int uiLignes, unsigned int uiColonnes)
{

}

//Operateurs
CMatrice::CMatrice<MType> & operator*(MType MTValeur)
{

}

CMatrice::CMatrice<MType> & MType::operator*(MTMATMatrice)
{

}

CMatrice::CMatrice<MType> & operator*(CMatrice<MType> MTMATMatrice)
{

}

CMatrice::CMatrice<MType> & operator/(MType MTValeur)
{

}

CMatrice::CMatrice<MType> & operator+(CMatrice<MType> MTMATMatrice)
{

}

CMatrice::CMatrice<MType> & operator-(CMatrice<MType> MTMATMatrice)
{

}
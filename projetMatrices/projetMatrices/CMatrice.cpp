#include "CMatrice.h"
#include "CException.h"

template<class MType> CMatrice<MType>::CMatrice()
{
	uiMATnbLignes = 0;
	uiMATnbColonnes = 0;
	ppMTMATMatrice = (** MType)malloc(0);
	if(ppMTMATMatrice == nullptr)
		throw new CException(2, "Allocation échouée");
}

template<class MType> CMatrice<MType>::CMatrice(const CMatrice<MType> & MTMATMatrice)
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

template<class MType> CMatrice<MType>::CMatrice(MType ** & ppMTMatrice, unsigned int uiLignes, unsigned int uiColonnes)
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

}

template<class MType> void CMatrice<MType>::MATAfficherMatrice() const
{

}

//Accesseurs
template<class MType> unsigned int CMatrice<MType>::MATgetNbLignes() const
{

}

template<class MType> unsigned int CMatrice<MType>::MATgetNbColonnes() const
{

}

template<class MType> MType ** & CMatrice<MType>::MATgetMatrice() const
{

}

template<class MType> void CMatrice<MType>::MATsetMatrice(MType ** & MTMATMatrice, unsigned int uiLignes, unsigned int uiColonnes)
{

}

//Operateurs
template<class MType> CMatrice<MType> & CMatrice<MType>::operator*(MType MTValeur)
{

}

template<class MType> CMatrice<MType> & CMatrice<MType>::MType::operator*(MTMATMatrice)
{

}

template<class MType> CMatrice<MType> & CMatrice<MType>::operator*(CMatrice<MType> MTMATMatrice)
{

}

template<class MType> CMatrice<MType> & CMatrice::operator/(MType MTValeur)
{

}

template<class MType> CMatrice<MType> & CMatrice::operator+(CMatrice<MType> MTMATMatrice)
{

}

template<class MType> CMatrice<MType> & CMatrice::operator-(CMatrice<MType> MTMATMatrice)
{

}
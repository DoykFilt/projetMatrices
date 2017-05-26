#ifndef CMATRICEMANIPULATEUR_H
#define CMATRICEMANIPULATEUR_H

#include "Cmatrice.h"

/******************************************************************************
class Cmatrice<class MType>
*******************************************************************************

	Ce Canvas de classe permet d'effectuer des manipulations complexes sur une matrice.

	Attributs
		Aucun

******************************************************************************/

template <class MType> class CmatriceManipulateur
{
public :
	/******************************************************************************
	MTMATTransposeeMatrice
	*******************************************************************************
		Entrée : Rien
		Necessité : Néant
		Sortie : référence sur un objet de type Cmatrice<MType>
		Entraine : Retourne la transposée de la matrice
	******************************************************************************/
	Cmatrice<MType> & MTMAMTransposeeMatrice(Cmatrice<MType> * pMTMATmatrice) const;
	
	/************************************************************************************************************************************************************
	MTMATEchelonnageMatrice
	*************************************************************************************************************************************************************
		Entrée : Un pointeur sur un objet de type Cmatrice<MType>
		Necessité : Pointeur non null
		Sortie : référence sur un objet de type CMatrice<MType>
		Entraine : Retourne la matrice echelonnée
	************************************************************************************************************************************************************/
	Cmatrice<MType> & MTMAMEchelonnageMatrice(Cmatrice<MType> * pMTMATmatrice) const;
	
	/************************************************************************************************************************************************************
	MTMATCalculRang
	*************************************************************************************************************************************************************
		Entrée : Un pointeur sur un objet de type Cmatrice<MType>
		Necessité : Pointeur non null
		Sortie : Naturel, rang de la matrice passé en paramètre
		Entraine : Le rang a été calculé et retourné
	************************************************************************************************************************************************************/
	unsigned int MTMAMCalculRang(Cmatrice<MType> * pMTMATmatrice);

};

#include "CmatriceManipulateur.cpp"

#endif
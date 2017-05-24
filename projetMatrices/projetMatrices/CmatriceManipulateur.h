#ifndef CMATRICEMANIPULATEUR_H
#define CMATRICEMANIPULATEUR_H

#include "Cmatrice.h"

template <class MType> CmatriceManipulateur
{
	
	/******************************************************************************
	MTMATTransposeeMatrice
	*******************************************************************************
		Entrée : Rien
		Necessité : Néant
		Sortie : référence sur un objet de type Cmatrice<MType>
		Entraine : Retourne la transposée de la matrice
	******************************************************************************/
	Cmatrice<MType> & MTMAMTransposeeMatrice(Cmatrice<MType> * MTMATmatrice) const;

	CMatrice<MType> & MTMATEchelonnageMatrice()const;
	unsigned int MTMATCalculRang();

};

#include "CmatriceManipulateur.cpp"

#endif
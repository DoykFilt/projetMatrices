#ifndef CMATRICEMANIPULATEUR_H
#define CMATRICEMANIPULATEUR_H

#include "Cmatrice.h"

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
	Cmatrice<MType> & MTMAMTransposeeMatrice(Cmatrice<MType> * MTMATmatrice) const;

	Cmatrice<MType> & MTMATEchelonnageMatrice(Cmatrice<MType> * MTMATmatrice) const;
	unsigned int MTMATCalculRang(Cmatrice<MType> * MTMATmatrice);

};

#include "CmatriceManipulateur.cpp"

#endif
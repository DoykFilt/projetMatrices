#ifndef CMATRICEMANIPULATEUR_H
#define CMATRICEMANIPULATEUR_H

#include "Cmatrice.h"

template <class MType> CmatriceManipulateur
{
	
	/******************************************************************************
	MTMATTransposeeMatrice
	*******************************************************************************
		Entr�e : Rien
		Necessit� : N�ant
		Sortie : r�f�rence sur un objet de type Cmatrice<MType>
		Entraine : Retourne la transpos�e de la matrice
	******************************************************************************/
	Cmatrice<MType> & MTMAMTransposeeMatrice(Cmatrice<MType> * MTMATmatrice) const;

	CMatrice<MType> & MTMATEchelonnageMatrice()const;
	unsigned int MTMATCalculRang();

};

#include "CmatriceManipulateur.cpp"

#endif
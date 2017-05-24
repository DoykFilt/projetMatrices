#ifndef CMATRICEMANIPULATEUR_H
#define CMATRICEMANIPULATEUR_H

#include "Cmatrice.h"

template <class MType> class CmatriceManipulateur
{
public :
	/******************************************************************************
	MTMATTransposeeMatrice
	*******************************************************************************
		Entr�e : Rien
		Necessit� : N�ant
		Sortie : r�f�rence sur un objet de type Cmatrice<MType>
		Entraine : Retourne la transpos�e de la matrice
	******************************************************************************/
	Cmatrice<MType> & MTMAMTransposeeMatrice(Cmatrice<MType> * MTMATmatrice) const;

	Cmatrice<MType> & MTMATEchelonnageMatrice(Cmatrice<MType> * MTMATmatrice) const;
	unsigned int MTMATCalculRang(Cmatrice<MType> * MTMATmatrice);

};

#include "CmatriceManipulateur.cpp"

#endif
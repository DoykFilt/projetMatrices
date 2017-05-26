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
		Entr�e : Rien
		Necessit� : N�ant
		Sortie : r�f�rence sur un objet de type Cmatrice<MType>
		Entraine : Retourne la transpos�e de la matrice
	******************************************************************************/
	Cmatrice<MType> & MTMAMTransposeeMatrice(Cmatrice<MType> * pMTMATmatrice) const;
	
	/************************************************************************************************************************************************************
	MTMATEchelonnageMatrice
	*************************************************************************************************************************************************************
		Entr�e : Un pointeur sur un objet de type Cmatrice<MType>
		Necessit� : Pointeur non null
		Sortie : r�f�rence sur un objet de type CMatrice<MType>
		Entraine : Retourne la matrice echelonn�e
	************************************************************************************************************************************************************/
	Cmatrice<MType> & MTMAMEchelonnageMatrice(Cmatrice<MType> * pMTMATmatrice) const;
	
	/************************************************************************************************************************************************************
	MTMATCalculRang
	*************************************************************************************************************************************************************
		Entr�e : Un pointeur sur un objet de type Cmatrice<MType>
		Necessit� : Pointeur non null
		Sortie : Naturel, rang de la matrice pass� en param�tre
		Entraine : Le rang a �t� calcul� et retourn�
	************************************************************************************************************************************************************/
	unsigned int MTMAMCalculRang(Cmatrice<MType> * pMTMATmatrice);

};

#include "CmatriceManipulateur.cpp"

#endif
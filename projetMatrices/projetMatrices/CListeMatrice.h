#ifndef CLISTEMATRICE_H
#define CLISTEMATRICE_H

#include "CMatrice.h"

class CListeMatrice
{
	private :
		//attributs
		unsigned int uiLIMNbMatrices;
		CMatrice<MType> *  pMTMATLIMListe;

	public :
		//constructeurs et destructeur
		CListeMatrice();
		CListeMatrice(const CListeMatrice & LIMListe);
		CListeMatrice(unsigned int uiLIMNBMatrices, CMatrice<MType> * pMTLIMMatrice);
		~CListeMatrice();

		//methodes
		void LIMAjouterMatrice(CMatrice<MType> * pMTMATLIMMatrice);
		void LIMSupprimerMatrice(unsigned int uiIndex);
		CMatrice<MType> LIMSommeMatrices();
		CMatrice<MType> LIMSommeAlterneeMatrices();
		CMatrice<MType> LIMSoustractionMatrices();
		CMatrice<MType> LIMMultiplicationMatrices();
		
		//Accesseurs
		unsigned int LIMGetNbMatrices(); 
		CMatrice<MType>** LIMGetListeMatrices();

};
#endif
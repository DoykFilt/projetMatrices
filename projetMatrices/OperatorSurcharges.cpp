#include "CMatrice.h"

template<class MType> CMatrice<MType> & operator*(double dValeur, CMatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	CMatrice<MType> * MTMATNewMatrice = new CMatrice<MType>(MTMATMatrice);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATNewMatrice.MATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATNewMatrice.MATgetNbColonnes(); uiCompteursColonnes++)
			MTMATNewMatrice->MATset(uiCompteurLignes, uiCompteursColonnes, MTMATNewMatrice->MATget() * dValeur);

	return *MTMATNewMatrice;
}
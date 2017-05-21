#include "CmatriceManipulateur.h"

/******************************************************************************
MTMAMTransposeeMatrice
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : référence sur un objet de type Cmatrice<MType>
	Entraine : Retourne la transposée de la matrice
******************************************************************************/
template<class MType> Cmatrice<MType> & CmatriceManipulateur<MType>::MTMAMTransposeeMatrice(Cmatrice<MType> * pMTMATmatrice) const
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;
	Cmatrice<MType> * pMTMATNewMatrice;

	MType ** ppMTMatrice = (MType **)malloc(sizeof(MType *) * pMTMATmatrice->getNbColonnes());
	if(ppMTMatrice == nullptr)
		throw Cexception(2, "Dans le constructeur de recopie de Cmatrice");

	for(uiCompteurLignes = 0; uiCompteurLignes < pMTMATmatrice->getNbColonnes(); uiCompteurLignes++)
	{
		ppMTMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * pMTMATmatrice->getNbLignes());
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
			throw Cexception(2, "Dans le constructeur de recopie de Cmatrice");

		for(uiCompteurColonnes = 0; uiCompteurColonnes < pMTMATmatrice->getNbLignes(); uiCompteurColonnes++)
			ppMTMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMATMatrice[uiCompteurColonnes][uiCompteurLignes];
	}
	
	pMTMATNewMatrice = new Cmatrice<MType>(ppMTMatrice, uiCompteurLignes, uiCompteurColonnes);

	for(uiCompteurLignes = 0; uiCompteurLignes < pMTMATmatrice->getNbColonnes(); uiCompteurLignes++)
		free(ppMTMatrice[uiCompteurLignes]);
	free(ppMTMatrice);

	return * pMTMATNewMatrice;
}
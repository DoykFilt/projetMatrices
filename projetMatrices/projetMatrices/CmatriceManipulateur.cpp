#include "CmatriceManipulateur.h"
#include "Cmatrice.h"

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

/************************************************************************************************************************************************************
MTMATEchelonnageMatrice
*************************************************************************************************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : référence sur un objet de type CMatrice<MType>
	Entraine : Retourne la matrice echelonnée
************************************************************************************************************************************************************/
template<class MType> Cmatrice<MType> & CmatriceManipulateur<MType>::MTMATEchelonnageMatrice(Cmatrice<MType> * pMTMATmatrice) const
{
	MType ** ppMTmatrice;
	unsigned int uiNbLignes, uiNbColonnes;
	//compteurs de parcours de la matrice pour les différents calculs
	unsigned int uiCompteurLignes, uiCompteurColonnes; 	
	unsigned int uiCompteurColonnesInterne;
	//  = r  ligne dernier pivot trouvé
	unsigned int uiDernierPivot=0; 
	//position du pivot d'une colonne
	unsigned int uiPositionPivot;
	//valeur du pivot + tampon pour inversion des lignes -> voir nommage
	MType MTpivot; 
	MType MTtamponInversion;

	//Tout d'abord on récupère la matrice contenue dans pMTMATmatrice
	ppMTmatrice = new MType*[pMTMATmatrice->MTMATgetNbLignes()];
	for(uiCompteurLignes = 0; uiCompteurLignes < pMTMATmatrice->MTMATgetNbLignes(); uiCompteurLignes++)
		ppMTmatrice[uiCompteurLignes] = new MType[pMTMATmatrice->MTMATgetNbColonnes()];
	uiNbLignes = pMTMATmatrice->MTMATgetNbLignes();
	uiNbColonnes = pMTMATmatrice->MTMATgetNbColonnes();
	for(uiCompteurLignes = 0; uiCompteurLignes < uiNbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiNbColonnes; uiCompteurColonnes++)
			ppMTmatrice[uiCompteurLignes][uiCompteurColonnes] = pMTMATmatrice->MTMATget(uiCompteurLignes, uiCompteurColonnes);

	//boucle exterieure, pour réduire avec un pivot sur chaque colonne
	for(uiCompteurColonnes = 0; uiCompteurColonnes < uiNbColonnes; uiCompteurColonnes++)
	{
		//pivot initialise comme la valeur a la ligne apres celle du dernier pivot + num ligne
		MTpivot = ppMTmatrice[uiCompteurColonnes][uiDernierPivot];
		uiPositionPivot = uiDernierPivot;

		//parcours des lignes pour trouver le max -> nouveau pivot
		for(uiCompteurLignes = uiPositionPivot + 1; uiCompteurLignes < uiNbLignes; uiCompteurLignes++)
		{
			if(ppMTmatrice[uiCompteurColonnes][uiCompteurLignes] < 0 && MTpivot < (-1) * ppMTmatrice[uiCompteurColonnes][uiCompteurLignes]
				|| ppMTmatrice[uiCompteurColonnes][uiCompteurLignes] > 0 && MTpivot < ppMTmatrice[uiCompteurColonnes][uiCompteurLignes])
			{
				//remplacement du pivot et du num ligne
				MTpivot = ppMTmatrice[uiCompteurColonnes][uiCompteurLignes];
				uiPositionPivot = uiCompteurLignes;
			}
		}

		if(MTpivot != 0)
		{
			//division de la ligne du pivot pour mettre celui ci a 1
			//inversion entre ligne pivot et ancien pivot +1 
			for(uiCompteurColonnesInterne = 0; uiCompteurColonnesInterne < uiNbColonnes; uiCompteurColonnesInterne++)
			{
				ppMTmatrice[uiCompteurColonnesInterne][uiPositionPivot] /= MTpivot;
				MTtamponInversion = ppMTmatrice[uiCompteurColonnesInterne][uiPositionPivot];
				ppMTmatrice[uiCompteurColonnesInterne][uiPositionPivot] = ppMTmatrice[uiCompteurColonnesInterne][uiDernierPivot];
				ppMTmatrice[uiCompteurColonnesInterne][uiDernierPivot] = MTtamponInversion;
			}
			uiPositionPivot = uiDernierPivot; // remplacement ligne pivot par sa nouvelle valeur

			//soustraction des lignes par celle du pivot multiplié par le valeur sur ligne pivot -> mise a zero de la colonne du pivot
			for(uiCompteurLignes = 0; uiCompteurLignes < uiNbLignes; uiCompteurLignes++)
			{
				if(uiCompteurLignes != uiDernierPivot)
				{
					for(uiCompteurColonnesInterne = 0; uiCompteurColonnesInterne < uiNbColonnes; uiCompteurColonnesInterne++)
						ppMTmatrice[uiCompteurColonnesInterne][uiCompteurLignes] -= ppMTmatrice[uiCompteurColonnes][uiCompteurLignes] * ppMTmatrice[uiCompteurColonnesInterne][uiPositionPivot];
				}
			}
			uiDernierPivot++;
		}
		else
			throw Cexception(4, "matrice non inversible"); // warning ? non necessaire pour l'echelonnage

	}

	return * new Cmatrice<MType>(ppMTmatrice, uiNbLignes, uiNbColonnes);
}


/************************************************************************************************************************************************************
MTMATCalculRang
*************************************************************************************************************************************************************
	Entrée : Rien
	Necessité : matrice echelonnée en parametre
	Sortie : Rang de la matrice echelonnée
	Entraine : Néant
************************************************************************************************************************************************************/
template<class MType> unsigned int CmatriceManipulateur<MType>::MTMATCalculRang(Cmatrice<MType> * pMTMATmatrice)
{
	unsigned int uiRang=0;
	unsigned int uiCompteurLignes, uiCompteurColonnes; 
	bool bLigneVide;

	Cmatrice<MType> MTMATtemp = MTMATEchelonnageMatrice(pMTMATmatrice);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATtemp.MTMATgetNbLignes(); uiCompteurLignes++)
	{
		bLigneVide=true;
		for(uiCompteurColonnes = 0; uiCompteurColonnes < MTMATtemp.MTMATgetNbColonnes(); uiCompteurColonnes++)
		{
			if(MTMATtemp.MTMATget(uiCompteurLignes, uiCompteurColonnes) != 0)
				bLigneVide=false;
		}
		if(bLigneVide == false)
			uiRang++;
	}

	return uiRang;
}
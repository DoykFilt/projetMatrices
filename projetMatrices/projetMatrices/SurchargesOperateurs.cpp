#include "Cmatrice.h"

/******************************************************************************
surcharge de operator*
*******************************************************************************
	Entrée : un objet de type générique MType1 Cmatrice une valeur de type générique MType2
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet de type MType1 créé
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<typename MType1, typename MType2> Cmatrice<MType1> & operator* (Cmatrice<MType1> const & MTMATMatrice, MType2 MTValeur)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	Cmatrice<MType1> * MTMATNouvelleMatrice = new Cmatrice<MType1>(MTMATMatrice);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATNouvelleMatrice->MTMATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATNouvelleMatrice->MTMATgetNbColonnes(); uiCompteursColonnes++)
			MTMATNouvelleMatrice->MTMATset(uiCompteurLignes, uiCompteursColonnes, MTMATNouvelleMatrice->MTMATget(uiCompteurLignes, uiCompteursColonnes) * MTValeur);

	return *MTMATNouvelleMatrice;
}

/******************************************************************************
surcharge de operator*
*******************************************************************************
	Entrée : un objet de type générique MType1 Cmatrice une valeur de type générique MType2
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet de type MType1 créé
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType1, class MType2> Cmatrice<MType1> & operator*(MType2 MTValeur, Cmatrice<MType1> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	Cmatrice<MType1> * MTMATNouvelleMatrice = new Cmatrice<MType1>(MTMATMatrice);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATNouvelleMatrice->MTMATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATNouvelleMatrice->MTMATgetNbColonnes(); uiCompteursColonnes++)
			MTMATNouvelleMatrice->MTMATset(uiCompteurLignes, uiCompteursColonnes, MTMATNouvelleMatrice->MTMATget(uiCompteurLignes, uiCompteursColonnes) * MTValeur);

	return *MTMATNouvelleMatrice;
}

/******************************************************************************
surcharge de operator*
*******************************************************************************
	Entrée : deux objet de type générique (MType1 et MType2) Cmatrice
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet de type MType1 créé
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType1, class MType2> Cmatrice<MType1> & operator*(Cmatrice<MType1> const & MTMATMatrice1, Cmatrice<MType2> const & MTMATMatrice2)
{
	unsigned int uiCompteurLignesMAT1, uiCompteurColonnesMAT2;
	unsigned int uiCompteurOperation;
	MType1 MTvaleurCase;
	MType1 ** ppMTMatrice;

	if(MTMATMatrice1.MTMATgetNbColonnes() != MTMATMatrice2.MTMATgetNbLignes())
			throw Cexception(3, "Tailles des matrices incompatible (*)");

	ppMTMatrice = (MType1 **)malloc(sizeof(MType1 *) * MTMATMatrice1.MTMATgetNbColonnes());
	if(ppMTMatrice == nullptr)
		throw Cexception(1, "Dans la surcharge operator*");

	for(uiCompteurLignesMAT1 = 0; uiCompteurLignesMAT1 < MTMATMatrice1.MTMATgetNbLignes(); uiCompteurLignesMAT1++)
	{
		ppMTMatrice[uiCompteurLignesMAT1] = (MType1 *)malloc(sizeof(MType1) * MTMATMatrice2.MTMATgetNbColonnes());
		if(ppMTMatrice[uiCompteurLignesMAT1] == nullptr)
		throw Cexception(1, "Dans la surcharge operator*");
	}

	for(uiCompteurLignesMAT1 = 0; uiCompteurLignesMAT1 < MTMATMatrice1.MTMATgetNbLignes(); uiCompteurLignesMAT1++)
	{
		for(uiCompteurColonnesMAT2 = 0; uiCompteurColonnesMAT2 < MTMATMatrice2.MTMATgetNbColonnes(); uiCompteurColonnesMAT2++)
		{
			MTvaleurCase = 0;
			for(uiCompteurOperation = 0; uiCompteurOperation < MTMATMatrice1.MTMATgetNbColonnes(); uiCompteurOperation++)
			{
				MTvaleurCase = MTvaleurCase + MTMATMatrice1.MTMATget(uiCompteurLignesMAT1, uiCompteurOperation) * MTMATMatrice2.MTMATget(uiCompteurOperation, uiCompteurColonnesMAT2);
			}
			ppMTMatrice[uiCompteurLignesMAT1][uiCompteurColonnesMAT2] = MTvaleurCase;
		}
	}

	return *(new Cmatrice<MType1>(ppMTMatrice, MTMATMatrice1.MTMATgetNbLignes(), MTMATMatrice1.MTMATgetNbColonnes()));
}

/******************************************************************************
surcharge de operator/
*******************************************************************************
	Entrée : un objet de type générique MType1 Cmatrice une valeur de type générique MType2
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet de type MType1 créé
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType1, class MType2> Cmatrice<MType1> & operator/(Cmatrice<MType1> const & MTMATMatrice, MType2 MTValeur)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	if(MTValeur == (MType2)0)
		throw Cexception(3, "Division par zero impossible !");

	Cmatrice<MType1> * MTMATNouvelleMatrice = new Cmatrice<MType1>(MTMATMatrice);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATNouvelleMatrice->MTMATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATNouvelleMatrice->MTMATgetNbColonnes(); uiCompteursColonnes++)
			MTMATNouvelleMatrice->MTMATset(uiCompteurLignes, uiCompteursColonnes, MTMATNouvelleMatrice->MTMATget(uiCompteurLignes, uiCompteursColonnes) / MTValeur);

	return *MTMATNouvelleMatrice;
}

/******************************************************************************
surcharge de operator+
*******************************************************************************
	Entrée : deux objet de type générique (MType1 et MType2) Cmatrice
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet de type MType1 créé
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType1, class MType2> Cmatrice<MType1> & operator+(Cmatrice<MType1> const & MTMATMatrice1, Cmatrice<MType2> const & MTMATMatrice2)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;
	Cmatrice<MType1> * MTMATNouvelleMatrice;

	if(MTMATMatrice1.MTMATgetNbLignes() != MTMATMatrice2.MTMATgetNbLignes() || MTMATMatrice1.MTMATgetNbColonnes() != MTMATMatrice2.MTMATgetNbColonnes())
		throw Cexception(3, "Tailles des matrices incompatible (+)");

	MTMATNouvelleMatrice = new Cmatrice<MType1>(MTMATMatrice1.MTMATgetNbLignes(), MTMATMatrice1.MTMATgetNbColonnes());

	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATMatrice1.MTMATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < MTMATMatrice1.MTMATgetNbColonnes(); uiCompteurColonnes++)
			MTMATNouvelleMatrice->MTMATset(uiCompteurLignes, uiCompteurColonnes, MTMATMatrice1.MTMATget(uiCompteurLignes, uiCompteurColonnes) + MTMATMatrice2.MTMATget(uiCompteurLignes, uiCompteurColonnes));

	return *MTMATNouvelleMatrice;
}

/******************************************************************************
surcharge de operator+
*******************************************************************************
	Entrée : deux objet de type générique (MType1 et MType2) Cmatrice
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet de type MType1 créé
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType1, class MType2> Cmatrice<MType1> & operator-(Cmatrice<MType1> const & MTMATMatrice1, Cmatrice<MType2> const & MTMATMatrice2)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;
	Cmatrice<MType1> * MTMATNouvelleMatrice;

	if(MTMATMatrice1.MTMATgetNbLignes() != MTMATMatrice2.MTMATgetNbLignes() || MTMATMatrice1.MTMATgetNbColonnes() != MTMATMatrice2.MTMATgetNbColonnes())
		throw Cexception(3, "Tailles des matrices incompatible (-)");

	MTMATNouvelleMatrice = new Cmatrice<MType1>(MTMATMatrice1.MTMATgetNbLignes(), MTMATMatrice1.MTMATgetNbColonnes());

	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATMatrice1.MTMATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < MTMATMatrice1.MTMATgetNbColonnes(); uiCompteurColonnes++)
			MTMATNouvelleMatrice->MTMATset(uiCompteurLignes, uiCompteurColonnes, MTMATMatrice1.MTMATget(uiCompteurLignes, uiCompteurColonnes) - MTMATMatrice2.MTMATget(uiCompteurLignes, uiCompteurColonnes));

	return *MTMATNouvelleMatrice;
}
#include "CMatrice.h"

/******************************************************************************
surcharge de operator*
*******************************************************************************
	Entrée : un objet de type générique MType1 CMatrice une valeur de type générique MType2
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet de type MType1 créé
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<typename MType1, typename MType2> CMatrice<MType1> & operator* (CMatrice<MType1> const & MTMATMatrice, MType2 MTValeur)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	CMatrice<MType1> * MTMATNouvelleMatrice = new CMatrice<MType1>(MTMATMatrice);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATNouvelleMatrice->MTMATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATNouvelleMatrice->MTMATgetNbColonnes(); uiCompteursColonnes++)
			MTMATNouvelleMatrice->MTMATset(uiCompteurLignes, uiCompteursColonnes, MTMATNouvelleMatrice->MTMATget(uiCompteurLignes, uiCompteursColonnes) * MTValeur);

	return *MTMATNouvelleMatrice;
}

/******************************************************************************
surcharge de operator*
*******************************************************************************
	Entrée : un objet de type générique MType1 CMatrice une valeur de type générique MType2
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet de type MType1 créé
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType1, class MType2> CMatrice<MType1> & operator*(MType2 MTValeur, CMatrice<MType1> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	CMatrice<MType1> * MTMATNouvelleMatrice = new CMatrice<MType1>(MTMATMatrice);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATNouvelleMatrice->MTMATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATNouvelleMatrice->MTMATgetNbColonnes(); uiCompteursColonnes++)
			MTMATNouvelleMatrice->MTMATset(uiCompteurLignes, uiCompteursColonnes, MTMATNouvelleMatrice->MTMATget(uiCompteurLignes, uiCompteursColonnes) * MTValeur);

	return *MTMATNouvelleMatrice;
}

/******************************************************************************
surcharge de operator*
*******************************************************************************
	Entrée : deux objet de type générique (MType1 et MType2) CMatrice
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet de type MType1 créé
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType1, class MType2> CMatrice<MType1> & operator*(CMatrice<MType1> const & MTMATMatrice1, CMatrice<MType2> const & MTMATMatrice2)
{
	unsigned int uiCompteurLignesMAT1, uiCompteurColonnesMAT2;
	unsigned int uiCompteurOperation;
	MType1 MTvaleurCase;
	MType1 ** ppMTMatrice;

	if(MTMATMatrice1.MTMATgetNbColonnes() != MTMATMatrice2.MTMATgetNbLignes())
			throw Cexception(3, "Tailles des matrices incompatible (dans la surcharge operator*(CMatrice<MType1> const &, CMatrice<MType2> const &)");

	ppMTMatrice = (MType1 **)malloc(sizeof(MType1 *) * MTMATMatrice1.MTMATgetNbColonnes());
	if(ppMTMatrice == nullptr)
		throw Cexception(1, "Dans la surcharge operator*(CMatrice<MType1> const &, CMatrice<MType2> const &)");

	for(uiCompteurLignesMAT1 = 0; uiCompteurLignesMAT1 < MTMATMatrice1.MTMATgetNbLignes(); uiCompteurLignesMAT1++)
	{
		ppMTMatrice[uiCompteurLignesMAT1] = (MType1 *)malloc(sizeof(MType1) * MTMATMatrice2.MTMATgetNbColonnes());
		if(ppMTMatrice[uiCompteurLignesMAT1] == nullptr)
		throw Cexception(1, "Dans la surcharge operator*(CMatrice<MType1> const &, CMatrice<MType2> const &)");
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

	return *(new CMatrice<MType1>(ppMTMatrice, MTMATMatrice1.MTMATgetNbLignes(), MTMATMatrice1.MTMATgetNbColonnes()));
}

/******************************************************************************
surcharge de operator/
*******************************************************************************
	Entrée : un objet de type générique MType1 CMatrice une valeur de type générique MType2
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet de type MType1 créé
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType1, class MType2> CMatrice<MType1> & operator/(CMatrice<MType1> const & MTMATMatrice, MType2 MTValeur)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	if(MTValeur == (MType2)0)
		throw Cexception(3, "Division par zero impossible !");

	CMatrice<MType1> * MTMATNouvelleMatrice = new CMatrice<MType1>(MTMATMatrice);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATNouvelleMatrice->MTMATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATNouvelleMatrice->MTMATgetNbColonnes(); uiCompteursColonnes++)
			MTMATNouvelleMatrice->MTMATset(uiCompteurLignes, uiCompteursColonnes, MTMATNouvelleMatrice->MTMATget(uiCompteurLignes, uiCompteursColonnes) / MTValeur);

	return *MTMATNouvelleMatrice;
}

/******************************************************************************
surcharge de operator+
*******************************************************************************
	Entrée : deux objet de type générique (MType1 et MType2) CMatrice
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet de type MType1 créé
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType1, class MType2> CMatrice<MType1> & operator+(CMatrice<MType1> const & MTMATMatrice1, CMatrice<MType2> const & MTMATMatrice2)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;
	CMatrice<MType1> * MTMATNouvelleMatrice;

	if(MTMATMatrice1.MTMATgetNbLignes() != MTMATMatrice2.MTMATgetNbLignes() || MTMATMatrice1.MTMATgetNbColonnes() != MTMATMatrice2.MTMATgetNbColonnes())
		throw Cexception(3, "Tailles des matrices incompatible (dans la surcharge operator+(CMatrice<MType1> const &, CMatrice<MType2> const &)");

	MTMATNouvelleMatrice = new CMatrice<MType1>(MTMATMatrice1.MTMATgetNbLignes(), MTMATMatrice1.MTMATgetNbColonnes());

	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATMatrice1.MTMATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < MTMATMatrice1.MTMATgetNbColonnes(); uiCompteurColonnes++)
			MTMATNouvelleMatrice->MTMATset(uiCompteurLignes, uiCompteurColonnes, MTMATMatrice1.MTMATget(uiCompteurLignes, uiCompteurColonnes) + MTMATMatrice2.MTMATget(uiCompteurLignes, uiCompteurColonnes));

	return *MTMATNouvelleMatrice;
}

/******************************************************************************
surcharge de operator+
*******************************************************************************
	Entrée : deux objet de type générique (MType1 et MType2) CMatrice
	Necessité : Néant
	Sortie : Une référence sur le nouvel objet de type MType1 créé
	Entraine : Un nouvel objet a été alloué avec les bonnes valeurs
******************************************************************************/
template<class MType1, class MType2> CMatrice<MType1> & operator-(CMatrice<MType1> const & MTMATMatrice1, CMatrice<MType2> const & MTMATMatrice2)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;
	CMatrice<MType1> * MTMATNouvelleMatrice;

	if(MTMATMatrice1.MTMATgetNbLignes() != MTMATMatrice2.MTMATgetNbLignes() || MTMATMatrice1.MTMATgetNbColonnes() != MTMATMatrice2.MTMATgetNbColonnes())
		throw Cexception(3, "Tailles des matrices incompatible (dans la surcharge operator-(CMatrice<MType1> const &, CMatrice<MType2> const &)");

	MTMATNouvelleMatrice = new CMatrice<MType1>(MTMATMatrice1.MTMATgetNbLignes(), MTMATMatrice1.MTMATgetNbColonnes());

	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATMatrice1.MTMATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < MTMATMatrice1.MTMATgetNbColonnes(); uiCompteurColonnes++)
			MTMATNouvelleMatrice->MTMATset(uiCompteurLignes, uiCompteurColonnes, MTMATMatrice1.MTMATget(uiCompteurLignes, uiCompteurColonnes) - MTMATMatrice2.MTMATget(uiCompteurLignes, uiCompteurColonnes));

	return *MTMATNouvelleMatrice;
}
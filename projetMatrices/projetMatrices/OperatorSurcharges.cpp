template<class MType1, class MType2> CMatrice<MType1> & operator*(CMatrice<MType1> const & MTMATMatrice, MType2 MTValeur)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	CMatrice<MType1> * MTMATNewMatrice = new CMatrice<MType1>(MTMATMatrice);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATNewMatrice.MATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATNewMatrice.MATgetNbColonnes(); uiCompteursColonnes++)
			MTMATNewMatrice->MATset(uiCompteurLignes, uiCompteursColonnes, MTMATNewMatrice->MATget() * MTValeur);

	return *MTMATNewMatrice;
}

template<class MType1, class MType2> CMatrice<MType1> & operator*(MType2 MTValeur, CMatrice<MType1> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	CMatrice<MType1> * MTMATNewMatrice = new CMatrice<MType1>(MTMATMatrice);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATNewMatrice.MATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATNewMatrice.MATgetNbColonnes(); uiCompteursColonnes++)
			MTMATNewMatrice->MATset(uiCompteurLignes, uiCompteursColonnes, MTMATNewMatrice->MATget() * MTValeur);

	return *MTMATNewMatrice;
}

template<class MType1, class Mtype2> CMatrice<MType1> & operator*(CMatrice<MType1> const & MTMATMatrice1, CMatrice<MType2> const & MTMATMatrice2)
{
	unsigned int uiCompteurLignesMAT1, uiCompteurColonnesMAT2;
	unsigned int uiCompteurOperation;
	MType1 MTvaleurCase;

	if(MTMATMatrice1.MATgetColonnes() != MTMATMatrice2.MATgetLignes())
		throw Cexception(3, "Calcul sur des matrices de taille imcompatible");


	MType1 ** ppMTMatrice = (MType **)malloc(sizeof(MType1 *) * MTMATMatrice1.MATgetColonnes());
	if(ppMTMatrice == nullptr)
		throw Cexception(2, "Allocation échouée");

	for(uiCompteurLignesMAT1 = 0; uiCompteurLignesMAT1 < MTMATMatrice1.MATgetLignes(); uiCompteurLignesMAT1++)
	{
		ppMTMatrice[uiCompteurLignesMAT1] = (MType1 *)malloc(sizeof(MType1) * MTMATMatrice2.MATgetColonnes());
		if(ppMTMATMatrice[uiCompteurLignesMAT1] == nullptr)
			throw Cexception(2, "Allocation échouée");
	}

	for(uiCompteurLignesMAT1 = 0; uiCompteurLignesMAT1 < MTMATMatrice1.MATgetLignes(); uiCompteurLignesMAT1++)
	{
		for(uiCompteurColonnesMAT2 = 0; uiCompteurColonnesMAT2 < MTMATMatrice2.MATgetColonnes(); uiCompteurColonnesMAT2++)
		{
			MTvaleurCase = 0;
			for(uiCompteurOperation = 0; uiCompteurOperation < MTMATMatrice1.MATgetColonnes(); uiCompteurOperation++)
			{
				MTvaleurCase = MTvaleurCase + MTMATMatrice1.MATget(uiCompteurLignesMAT1, uiCompteurOperation) * MTMATMatrice2.MATget(uiCompteurOperation, uiCompteurColonnesMAT2);
			}
			ppMTMatrice[uiCompteurLignesMAT1][uiCompteurColonnesMAT2] = MTvaleurCase;
		}
	}

	return *(new CMatrice<MType1>(ppMTMatrice, uiMATnbLignes, MTMATMatrice.uiMATnbColonnes));
}

template<class MType1, class MType2> CMatrice<MType1> & operator/(CMatrice<MType1> const & MTMATMatrice, MType2 MTValeur)
{
	unsigned int uiCompteurLignes, uiCompteursColonnes;

	CMatrice<MType1> * MTMATNewMatrice = new CMatrice<MType1>(MTMATMatrice);
	
	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATNewMatrice.MATgetNbLignes(); uiCompteurLignes++)
		for(uiCompteursColonnes = 0; uiCompteursColonnes < MTMATNewMatrice.MATgetNbColonnes(); uiCompteursColonnes++)
			MTMATNewMatrice->MATset(uiCompteurLignes, uiCompteursColonnes, MTMATNewMatrice->MATget() / MTValeur);

	return *MTMATNewMatrice;
}

template<class MType1, class MType2> CMatrice<MType1> & operator+(CMatrice<MType1> const & MTMATMatrice1, CMatrice<MType2> const & MTMATMatrice2)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	if(MTMATMAtrice1.MATgetLignes() != MTMATMAtrice2.MATgetLignes() || MTMATMAtrice1.MATgetColonness() != MTMATMAtrice2.MATgetColonnes())
		throw Cexception(3, "Calcule sur matrices de tailles incompatibles");

	CMatrice<MType> * MTMATNewMatrice = new CMatrice<MType>(MTMATMAtrice1.MATgetLignes(), MTMATMAtrice1.MATgetColonness());

	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATMAtrice1.MATgetLignes(); uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < MTMATMAtrice1.MATgetColonnes(); uiCompteurColonnes++)
			MTMATNewMatrice->MATset(uiCompteurLignes, uiCompteurColonnes, MTMATMatrice1.MATget(uiCompteurLignes, uiCompteurColonnes) + MTMATMatrice2.MATget(uiCompteurLignes, uiCompteurColonnes);

	return *MTMATNewMatrice;
}

template<class MType1, class MType2> CMatrice<MType1> & operator-(CMatrice<MType1> const & MTMATMatrice1, CMatrice<MType2> const & MTMATMatrice2)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	if(MTMATMAtrice1.MATgetLignes() != MTMATMAtrice2.MATgetLignes() || MTMATMAtrice1.MATgetColonness() != MTMATMAtrice2.MATgetColonnes())
		throw Cexception(3, "Calcule sur matrices de tailles incompatibles");

	CMatrice<MType> * MTMATNewMatrice = new CMatrice<MType>(MTMATMAtrice1.MATgetLignes(), MTMATMAtrice1.MATgetColonness());

	for(uiCompteurLignes = 0; uiCompteurLignes < MTMATMAtrice1.MATgetLignes(); uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < MTMATMAtrice1.MATgetColonnes(); uiCompteurColonnes++)
			MTMATNewMatrice->MATset(uiCompteurLignes, uiCompteurColonnes, MTMATMatrice1.MATget(uiCompteurLignes, uiCompteurColonnes) - MTMATMatrice2.MATget(uiCompteurLignes, uiCompteurColonnes);

	return *MTMATNewMatrice;
}
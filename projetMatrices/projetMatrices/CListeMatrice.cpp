#include "ClisteMatrice.h"
#include "Cexception.h"

/******************************************************************************
Constructeur par défaut
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé.
******************************************************************************/
CListeMatrice::CListeMatrice()
{
	uiLIMNbMatrices = 0;
	pMTMATLIMListe = (CMatrice<MType> * ) malloc (0);
	if (pMTMATLIMListe = nullptr)
		throw Cexception(ERREUR_ALLOCATION);
}

/******************************************************************************
Constructeur de recopie
*******************************************************************************
	Entrée : Un Objet de la classe.
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé par recopie.
******************************************************************************/
CListeMatrice::CListeMatrice(const CListeMatrice  & LIMListe) 
{
	unsigned int uiBoucle;
	uiLIMNbMatrices = LIMListe.uiLIMNbMatrices;
	pMTMATLIMListe = (CMatrice<MType>*) malloc(uiLIMNbMatrices*sizeof(CMatrice<MType>));
	if (pMTMATLIMListe = nullptr)
		throw Cexception(ERREUR_ALLOCATION);

	for( uiBoucle =0; uiBoucle < uiLIMNbMatrices; uiBoucle++)
		pMTMATLIMListe[uiBoucle] = new CMatrice(LIMListe.pMTMATLIMListe[uiBoucle]);

}

/******************************************************************************
Constructeur à deux arguments
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé.
******************************************************************************/
CListeMatrice::CListeMatrice(unsigned int uiLIMNBMatrices, CMatrice<MType> * pMTMATLIMMatrice) 
{
	unsigned int uiBoucle;
	uiLIMNbMatrices = uiLIMNBMatrices;
	pMTMATLIMListe = (CMatrice<MType>*) malloc(uiLIMNbMatrices*sizeof(CMatrice<MType>));
	if (pMTMATLIMListe = nullptr)
		throw Cexception(ERREUR_ALLOCATION);

	for( uiBoucle =0; uiBoucle < uiLIMNbMatrices; uiBoucle++)
		pMTMATLIMListe[uiBoucle] = new CMatrice(pMTMATLIMMatrice[uiBoucle]); 
}

/******************************************************************************
Destructeur
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : Les matrices de la liste sont detruites et 
******************************************************************************/
CListeMatrice::~CListeMatrice()
{
	unsigned int uiBoucle;
	for( uiBoucle =0; uiBoucle < uiLIMNbMatrices; uiBoucle++)
		delete & pMTMATLIMListe[uiBoucle]; //free(pMTMATLIMListe[uiBoucle]);     // CMatrice()::~CMatrice();
	free(pMTMATLIMListe);
} 

/******************************************************************************
Constructeur par défaut
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé.
******************************************************************************/
void CListeMatrice::LIMAjouterMatrice(CMatrice<MType> * pMTMATLIMMatrice) 
{
	uiLIMNbMatrices++;
	pMTMATLIMListe = (CMatrice<MType>*) realloc(pMTMATLIMListe, uiLIMNbMatrices*sizeof(CMatrice<MType>));
	if(pMTMATLIMListe == nullptr)
			throw Cexception(ERREUR_REALLOCATION);

	pMTMATLIMListe[uiLIMNbMatrices -1] = new CMatrice(pMTMATLIMMatrice); //souci de parametre -> pointeur sur un objet 

}

/******************************************************************************
Constructeur par défaut
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé.
******************************************************************************/
void CListeMatrice::LIMSupprimerMatrice(unsigned int uiIndex )
{
	unsigned int uiBoucle;
	delete & pMTMATLIMListe[uiIndex]; //suppression matrice a l'index
	pMTMATLIMListe[uiIndex] = (CMatrice<MType>*) malloc(sizeof(CMatrice<MType>)); //allocation pointeur de l'index
	for(uiBoucle = uiIndex; uiBoucle < uiLIMNbMatrices; uiBoucle++) //decalage des matrices 
		pMTMATLIMListe[uiBoucle] = pMTMATLIMListe[uiIndex+1];
	delete & pMTMATLIMListe[uiLIMNbMatrices]; // libération du dernier pointeur : efface la derniere matrice ?
	uiLIMNbMatrices--;
	pMTMATLIMListe = (CMatrice<MType>*) realloc(pMTMATLIMListe, uiLIMNbMatrices*sizeof(CMatrice<MType>)); // reallocation de la liste de la nouvelle taille
} 

/******************************************************************************
Constructeur par défaut
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé.
******************************************************************************/
CMatrice<MType> CListeMatrice::LIMSommeMatrices()
{
	
	unsigned int uiBoucle;
	CMatrice<MType> * MATMatriceSomme = new CMatrice();
	* MATMatriceSomme = pMTMATLIMListe[0];
	for( uiBoucle =1; uiBoucle < uiLIMNbMatrices; uiBoucle++)
	{
		*MATMatriceSomme = *MATMatriceSomme + pMTMATLIMListe[uiBoucle];
	}
	return * MATMatriceSomme;
} 

/******************************************************************************
Constructeur par défaut
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé.
******************************************************************************/
CMatrice<MType> CListeMatrice::LIMSommeAlterneeMatrices() 
{
	unsigned int uiBoucle;
	CMatrice<MType> * MATMatriceSommeAlternee = new CMatrice();
	*MATMatriceSommeAlternee = pMTMATLIMListe[0];
	for( uiBoucle =1; uiBoucle < uiLIMNbMatrices; uiBoucle++)
	{
		*MATMatriceSommeAlternee = *MATMatriceSommeAlternee + (pMTMATLIMListe[uiBoucle] * ((-1)^(uiBoucle)));
	}
	return * MATMatriceSommeAlternee;

}

/******************************************************************************
Constructeur par défaut
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé.
******************************************************************************/
CMatrice<MType> CListeMatrice::LIMSoustractionMatrices() 
{
	unsigned int uiBoucle;
	CMatrice<MType> * MATMatriceSoustraction = new CMatrice();
	*MATMatriceSoustraction = pMTMATLIMListe[0];
	for( uiBoucle =1; uiBoucle < uiLIMNbMatrices; uiBoucle++)
	{
		*MATMatriceSoustraction = *MATMatriceSoustraction - pMTMATLIMListe[uiBoucle];
	}
	return * MATMatriceSoustraction;
}

/******************************************************************************
Constructeur par défaut
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé.
******************************************************************************/
CMatrice<MType> CListeMatrice::LIMMultiplicationMatrices() 
{
	unsigned int uiBoucle;
	CMatrice<MType> * MATMatriceMultiplication = new CMatrice();
	*MATMatriceMultiplication = pMTMATLIMListe[0];
	for( uiBoucle =1; uiBoucle < uiLIMNbMatrices; uiBoucle++)
	{
		*MATMatriceMultiplication = *MATMatriceMultiplication * pMTMATLIMListe[uiBoucle];
	}
	return * MATMatriceMultiplication;
}


/******************************************************************************
Constructeur par défaut
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé.
******************************************************************************/
inline unsigned int CListeMatrice::LIMGetNbMatrices()
{
	return uiLIMNbMatrices;
} 

/******************************************************************************
Constructeur par défaut
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé.
******************************************************************************/
inline CMatrice<MType>** CListeMatrice::LIMGetListeMatrices() 
{

}

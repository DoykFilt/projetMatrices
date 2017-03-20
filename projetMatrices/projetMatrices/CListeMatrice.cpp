#include "ClisteMatrice.h"
#include "Cexception.h"

//constructeurs
CListeMatrice::CListeMatrice()
{
	uiLIMNombreMatrices = 0;
	pMTMATLIMListe = (CMatrice<MType> * ) malloc (0);
	if (pMTMATLIMListe = nullptr)
		throw new Cexception(2, "allocation echouée");
}

CListeMatrice::CListeMatrice(const CListeMatrice  & LIMListe) 
{
	unsigned int uiBoucle;
	uiLIMNombreMatrices = LIMListe.uiLIMNombreMatrices;
	pMTMATLIMListe = (CMatrice<MType>*) malloc(uiLIMNombreMatrices*sizeof(CMatrice<MType>));
	if (pMTMATLIMListe = nullptr)
		throw new Cexception(2, "allocation echouée");

	for( uiBoucle =0; uiBoucle < uiLIMNombreMatrices; uiBoucle++)
		pMTMATLIMListe[uiBoucle] = new CMatrice(LIMListe.pMTMATLIMListe[uiBoucle]);

}

CListeMatrice::CListeMatrice(unsigned int uiLIMNBMatrices, CMatrice<MType> * pMTMATLIMMatrice) 
{
	unsigned int uiBoucle;
	uiLIMNombreMatrices = uiLIMNBMatrices;
	pMTMATLIMListe = (CMatrice<MType>*) malloc(uiLIMNombreMatrices*sizeof(CMatrice<MType>));
	if (pMTMATLIMListe = nullptr)
		throw new Cexception(2, "allocation echouée");

	for( uiBoucle =0; uiBoucle < uiLIMNombreMatrices; uiBoucle++)
		pMTMATLIMListe[uiBoucle] = new CMatrice(pMTMATLIMMatrice[uiBoucle]); //argument incorrect sur la forme ? pointeur membre droite correct ?
}

CListeMatrice::~CListeMatrice()
{
	unsigned int uiBoucle;
	for( uiBoucle =0; uiBoucle < uiLIMNombreMatrices; uiBoucle++)
		free(pMTMATLIMListe[uiBoucle]);     // CMatrice()::~CMatrice();
	free(pMTMATLIMListe);
} 

//Methodes
void CListeMatrice::LIMAjouterMatrice(CMatrice<MType> * pMTMATLIMMatrice) 
{
	uiLIMNombreMatrices++;
	pMTMATLIMListe = (CMatrice<MType>*) realloc(pMTMATLIMListe, uiLIMNombreMatrices*sizeof(CMatrice<MType>));
	if(pMTMATLIMListe == nullptr)
			throw Cexception(3, "Réallocation échouée");

	pMTMATLIMListe[uiLIMNombreMatrices -1] = new CMatrice(pMTMATLIMMatrice); //souci de parametre -> pointeur sur un objet 

}

void CListeMatrice::LIMSupprimerMatrice(unsigned int uiIndex )
{
	unsigned int uiBoucle;
	free(pMTMATLIMListe[uiIndex]); //suppression matrice a l'index
	pMTMATLIMListe[uiIndex] = (CMatrice<MType>*) malloc(sizeof(CMatrice<MType>)); //allocation pointeur de l'index
	for(uiBoucle = uiIndex; uiBoucle < uiLIMNombreMatrices; uiBoucle++) //decalage des matrices 
		pMTMATLIMListe[uiBoucle] = pMTMATLIMListe[uiIndex+1];
	free(pMTMATLIMListe[uiLIMNombreMatrices]); // libération du dernier pointeur : efface la derniere matrice ?
	uiLIMNombreMatrices--;
	pMTMATLIMListe = (CMatrice<MType>*) realloc(pMTMATLIMListe, uiLIMNombreMatrices*sizeof(CMatrice<MType>)); // reallocation de la liste de la nouvelle taille
} 

CMatrice<MType> CListeMatrice::LIMSommeMatrices()
{
	
	unsigned int uiBoucle;
	CMatrice<MType> * MATMatriceSomme = new CMatrice();
	*MATMatriceSomme = pMTMATLIMListe[0];
	for( uiBoucle =1; uiBoucle < uiLIMNombreMatrices; uiBoucle++)
	{
		*MATMatriceSomme = *MATMatriceSomme + pMTMATLIMListe[uiBoucle];
	}
	return * MATMatriceSomme;
} 

CMatrice<MType> CListeMatrice::LIMSommeAlterneeMatrices() 
{
	unsigned int uiBoucle;
	CMatrice<MType> * MATMatriceSommeAlternee = new CMatrice();
	*MATMatriceSommeAlternee = pMTMATLIMListe[0];
	for( uiBoucle =1; uiBoucle < uiLIMNombreMatrices; uiBoucle++)
	{
		*MATMatriceSommeAlternee = *MATMatriceSommeAlternee + (pMTMATLIMListe[uiBoucle] * ((-1)^(uiBoucle)));
	}
	return * MATMatriceSommeAlternee;

}

CMatrice<MType> CListeMatrice::LIMSoustractionMatrices() 
{
	unsigned int uiBoucle;
	CMatrice<MType> * MATMatriceSoustraction = new CMatrice();
	*MATMatriceSoustraction = pMTMATLIMListe[0];
	for( uiBoucle =1; uiBoucle < uiLIMNombreMatrices; uiBoucle++)
	{
		*MATMatriceSoustraction = *MATMatriceSoustraction - pMTMATLIMListe[uiBoucle];
	}
	return * MATMatriceSoustraction;
}

CMatrice<MType> CListeMatrice::LIMMultiplicationMatrices() 
{
	unsigned int uiBoucle;
	CMatrice<MType> * MATMatriceMultiplication = new CMatrice();
	*MATMatriceMultiplication = pMTMATLIMListe[0];
	for( uiBoucle =1; uiBoucle < uiLIMNombreMatrices; uiBoucle++)
	{
		*MATMatriceMultiplication = *MATMatriceMultiplication * pMTMATLIMListe[uiBoucle];
	}
	return * MATMatriceMultiplication;
}

//accesseurs
unsigned int CListeMatrice::LIMGetNbMatrices()
{
	return uiLIMNombreMatrices;
} 

CMatrice<MType>** CListeMatrice::LIMGetListeMatrices() 
{

}

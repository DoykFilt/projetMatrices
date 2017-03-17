#include "ClisteMatrice.h"

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
		pMTMATLIMListe[uiBoucle] = new CMatrice(pMTMATLIMListe[uiBoucle]);
}

CListeMatrice::~CListeMatrice()
{
	unsigned int uiBoucle;
	for( uiBoucle =0; uiBoucle < uiLIMNombreMatrices; uiBoucle++)
		delete pMTMATLIMListe[uiBoucle];
	free(pMTMATLIMListe);
} 

void CListeMatrice::LIMAjouterMatrice(CMatrice<MType> * pMTMATLIMMatrice) 
{
	uiLIMNombreMatrices++;
	pMTMATLIMListe = (CMatrice<MType>*) realloc(uiLIMNombreMatrices*sizeof(CMatrice<MType>));

}

void CListeMatrice::LIMSupprimerMatrice(unsigned int uiIndex )
{

} 

CMatrice<MType> CListeMatrice::LIMSommeMatrices()
{

} 

CMatrice<MType> CListeMatrice::LIMSommeAlterneeMatrices() 
{

}

CMatrice<MType> CListeMatrice::LIMSoustractionMatrices() 
{

}

CMatrice<MType> CListeMatrice::LIMMultiplicationMatrices() 
{

}

unsigned int CListeMatrice::LIMGetNbMatrices()
{

} 

CMatrice<MType>** CListeMatrice::LIMGetListeMatrices() 
{

}

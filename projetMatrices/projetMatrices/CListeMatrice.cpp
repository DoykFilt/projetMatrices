#include "ClisteMatrice.h"

CListeMatrice()
{
	uiNombreMatrices = 0;
	pMTMATLIMListe = (CMatrice<MType> * ) malloc (0);
	if (pMTMATLIMListe = nullptr)
		throw new CException(2, "allocation echouée");
}

CListeMatrice(CListeMatrice LIMListe) 
{
	unsigned int uiBoucle;
	uiNombrematrices = LIMListe.uiNombreMatrices;
	pMTMATLIMListe = (CMatrice<MType>*) malloc(uiNombrematrices*sizeof(CMatrice<MType>));
	if (pMTMATLIMListe = nullptr)
		throw new CException(2, "allocation echouée");

	for( uiBoucle =0; uiBoucle < uiNombreMatrices; uiBoucle++)
		pMTMATLIMListe[uiBoucle] = new CMatrice(LIMListe.pMTMATLIMListe[uiBoucle]);

}
CListeMatrice(unsigned int uiLIMNBMatrices, (CMatrice<MType> * ) pMTMATLIMMatrices ) 
{
	unsigned int uiBoucle;
	uiNombreMatrices = uiLIMNBMatrices;
	pMTMATLIMListe = (CMatrice<MType>*) malloc(uiNombrematrices*sizeof(CMatrice<MType>));
	if (pMTMATLIMListe = nullptr)
		throw new CException(2, "allocation echouée");

	for( uiBoucle =0; uiBoucle < uiNombreMatrices; uiBoucle++)
		pMTMATLIMListe[uiBoucle] = new CMatrice(pMTMATLIMMatrices[uiBoucle]);
}
~CListeMatrice()
{
	unsigned int uiBoucle;
	for( uiBoucle =0; uiBoucle < uiNombreMatrices; uiBoucle++)
		delete pMTMATLIMListe[uiBoucle];
	free(pMTMATLIMListe);
} 

void LIMAjouterMatrice(CMatrice<MType> * pMTMATLIMMatrice) 
{
	uiNombreMatrices++;
	pMTMATLIMListe = (CMatrice<MType>*) realloc(uiNombrematrices*sizeof(CMatrice<MType>));

}
void LIMSupprimerMatrice(unsigned int uiIndex )
{

} 
CMatrice<MType> LIMSommeMatrices()
{

} 
CMatrice<MType> LIMSommeAlterneeMatrices() 
{

}
CMatrice<MType> LIMSoustractionMatrices() 
{

}
CMatrice<MType> LIMMultiplicationMatrices() 
{

}
unsigned int LIMGetNbMatrices()
{

} 
CMatrice<MType>** LIMGetListeMatrices() 
{

}

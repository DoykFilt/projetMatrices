#include <iostream>
#include "Cexception.h"
#include "CmatriceGenerateur.h"

/******************************************************************************
Constructeur
*******************************************************************************
Entr�e : Rien
Necessit� : N�ant
Sortie : Rien
Entraine : L'objet a �t� initialis�
******************************************************************************/
CmatriceGenerateur::CmatriceGenerateur()
{
	pPARMGRparseur = nullptr;
}
/******************************************************************************
Constructeur avec un argument
*******************************************************************************
Entr�e : un pointeur sur un objet de type Cparseur
Necessit� : N�ant
Sortie : Rien
Entraine : L'objet a �t� initialis�
******************************************************************************/
CmatriceGenerateur::CmatriceGenerateur(Cparseur * pPARparseur)
{
	pPARMGRparseur = pPARparseur;
}
/******************************************************************************
Constructeur de recopie
*******************************************************************************
Entr�e : R�f�rence sur un objet de type CgraphGenerateur
Necessit� : N�ant
Sortie : Rien
Entraine : L'objet a �t� initialis� par recopie de l'objet en param�tre
******************************************************************************/
CmatriceGenerateur::CmatriceGenerateur(CmatriceGenerateur & MGRObjet)
{
	pPARMGRparseur = MGRObjet.pPARMGRparseur;
}
/******************************************************************************
Destructeur
*******************************************************************************
Entr�e : Rien
Necessit� : L'arbre a �t� d�sallou�
Sortie : Rien
Entraine : L'espace allou� pour les attributs de l'objet a �t� lib�r�
******************************************************************************/
CmatriceGenerateur::~CmatriceGenerateur(){}
/******************************************************************************
GRGgenererMatrice
*******************************************************************************
Entr�e : Rien
Necessit� : Le parseur a r�cup�r� les donn�es brutes pr�alablement
Sortie : l'objet reconnu de type Cmatrice<double> 
Entraine : un objet de type Cmatrice<double> a �t� allou� et retourn�
******************************************************************************/
Cmatrice<double> * CmatriceGenerateur::MGRgenererMatrice()
{
	Cmatrice<double> * pDMAmatrice;
	unsigned int uiNbrColonnes, uiNbrLignes;
	unsigned int uiCompteur, uiCompteurLignes, uiCompteurColonnes;
	double ** ppdMatrice;
	char * pcType = nullptr;
	char *** pppcBrut;
	//sept variables utilis�es pour la reconnaissance des chiffres contenu dans la matrice
	char * pcfix, *pcdef;
	char * pctemp;
	unsigned int uicfix = 0, uicdef = 0, uitemplen = 0;
	
	if(pPARMGRparseur == nullptr)
		throw Cexception(ERREUR_PRECONDITIONS, "Parseur vide");
	pppcBrut = pPARMGRparseur->PARbrut();
	if(pppcBrut == nullptr)
		throw Cexception(ERREUR_PRECONDITIONS, "Parser le fichier avant");

	//On r�cup�re puis on teste le type de la matrice
	for(uiCompteur = 0; uiCompteur < pPARMGRparseur->PARLireNbrBalise(); uiCompteur++)
		if(strcmp("TYPEMATRICE", pppcBrut[uiCompteur][0]) == 0)
			pcType = pppcBrut[uiCompteur][1];
	if(pcType == nullptr || strcmp("DOUBLE", pcType) != 0)
		throw Cexception(ERREUR_PARSEUR, "Type non reconnu");

	//Ensuite on r�cup�re ses dimensions
	for(uiCompteur = 0; uiCompteur < pPARMGRparseur->PARLireNbrBalise(); uiCompteur++)
		if(strcmp("NBCOLONNES", pppcBrut[uiCompteur][0]) == 0)
			uiNbrColonnes = MGRreconnaitreEntier(pppcBrut[uiCompteur][1]);
		else if(strcmp("NBLIGNES", pppcBrut[uiCompteur][0]) == 0)
			uiNbrLignes = MGRreconnaitreEntier(pppcBrut[uiCompteur][1]);

	//Finalement on rempli la matrice
	ppdMatrice = new double*[uiNbrLignes];
	for(uiCompteur = 0; uiCompteur < uiNbrLignes; uiCompteur++)
		ppdMatrice[uiCompteur] = new double[uiNbrColonnes];
	
	for(uiCompteur = 0; uiCompteur < pPARMGRparseur->PARLireNbrBalise(); uiCompteur++)
		if(strcmp("MATRICE", pppcBrut[uiCompteur][0]) == 0)
		{
			pcfix = pppcBrut[uiCompteur][1];
			pcdef = pppcBrut[uiCompteur][1];
		}
	pctemp = (char *)malloc(uitemplen + 1);
	if(pctemp == nullptr)
		throw(Cexception(ERREUR_ALLOCATION, "Dans PARcreerDoubleMatrice"));
	pctemp[0] = '\0';

	for(uiCompteurLignes = 0; uiCompteurLignes < uiNbrLignes; uiCompteurLignes++)
	{
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiNbrColonnes; uiCompteurColonnes++)
		{
			while(pcfix[uicfix] == ' ' && pcfix[uicfix] != '\0') uicfix++;
			uicdef = uicfix;
			while(pcdef[uicdef] != ' ' && pcdef[uicdef] != '\0') uicdef++;

			if(pcfix[uicfix] == '\0')
			{
				free(pctemp);
				throw Cexception(ERREUR_PARSEUR, "La taille de la Matrice lue ne correspond pas a la taille reelle");
			}

			for(int i = 0; uicfix + i < uicdef; i++)
			{
				uitemplen ++;
				pctemp = (char *)realloc(pctemp, uitemplen + 1);
				if(pctemp == nullptr)
					throw(Cexception(ERREUR_REALLOCATION, "Dans PARcreerDoubleMatrice"));
				pctemp[i] = pcfix[uicfix + i];
				pctemp[i + 1] = '\0';
			}
			ppdMatrice[uiCompteurLignes][uiCompteurColonnes] = atof(pctemp);
			uicfix = uicdef;
			uitemplen = 0;
			pctemp = (char *)realloc(pctemp, uitemplen + 1);
			if(pctemp == nullptr)
				throw(Cexception(ERREUR_REALLOCATION, "Dans PARcreerDoubleMatrice"));
			pctemp[0] = '\0';
		}
	}

	pDMAmatrice = new Cmatrice<double>(ppdMatrice, uiNbrLignes, uiNbrColonnes);
	
	//Lib�ration de la m�moire allou�e
	for(uiCompteur = 0; uiCompteur < uiNbrLignes; uiCompteur++)
		delete ppdMatrice[uiCompteur];
	delete ppdMatrice;
	free(pctemp);

	return pDMAmatrice;
}
/******************************************************************************
GRGsetParseur
*******************************************************************************
Entr�e : Un pointeur sur un objet de type Cparseur
Necessit� : N�ant
Sortie : Rien
Entraine : L'ancien parseur a �t� remplac� par le nouveau
******************************************************************************/
void CmatriceGenerateur::MGRsetParseur(Cparseur * pPARparseur)
{
	pPARMGRparseur = pPARparseur;
}
/******************************************************************************
GRGgetParseur
*******************************************************************************
Entr�e : Rien
Necessit� : N�ant
Sortie : Un poiteur sur le parseur
Entraine : Le pointeur a �t� retourn�
******************************************************************************/
Cparseur * CmatriceGenerateur::MGRgetParseur()
{
	return pPARMGRparseur;
}
/******************************************************************************
GRGreconnaitreEntier
*******************************************************************************
Entr�e : une chaine de caract�re contenant l'entier � reconnaitre
Necessit� : La chaine est convertible en entier
Sortie : L'entier reconnu
Entraine : L'entier a �t� reconnu et renvoy�
******************************************************************************/
unsigned int CmatriceGenerateur::MGRreconnaitreEntier(char * pcElm)
{
	unsigned int uiCompteur = 0;

	//On test d'abord si on a affaire � un nombre
	while(pcElm[uiCompteur] == ' ' || pcElm[uiCompteur] == '\n' && pcElm[uiCompteur] != '\0')
		uiCompteur++;
	while(pcElm[uiCompteur] != '\0' && pcElm[uiCompteur] != ' ' && pcElm[uiCompteur] != '\n' && pcElm[uiCompteur] != ',')
	{
		if(!isdigit(pcElm[uiCompteur]))
			throw Cexception(ERREUR_PARSEUR, "Impossible de reconnaitre un entier positif");
		uiCompteur++;
	}
	while(pcElm[uiCompteur] != '\0')
	{
		pcElm[uiCompteur] = ' ';
		uiCompteur++;
	}

	//puis on le renvoit
	return strtol(pcElm, NULL, 0);
}
/******************************************************************************
surcharge de l'op�rateur d'affectation
*******************************************************************************
Entr�e : un objet du m�me type
Necessit� : N�ant
Sortie : Une r�f�rence sur l'objet en cours qui a �t� modifi�
Entraine : L'objet en cours est une copie de l'objet en param�tre
******************************************************************************/
CmatriceGenerateur & CmatriceGenerateur::operator=(CmatriceGenerateur const & MGRObjet)
{
	pPARMGRparseur = MGRObjet.pPARMGRparseur;

	return *this;
}
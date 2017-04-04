#include <fstream>
#include <iostream>
#include "Cparseur.h"
#include <string.h>

using namespace std;

/******************************************************************************
Constructeur
*******************************************************************************
Entr�e : Rien
Necessit� : N�ant
Sortie : Rien
Entraine : L'objet a �t� initialis�
******************************************************************************/
Cparseur::Cparseur()
{	
	pctabBalisesValeurs[0][0] = _strdup(TYPEMATRICE);
	pctabBalisesValeurs[0][1] = nullptr;
	pctabBalisesValeurs[1][0] = _strdup(NBLIGNES);
	pctabBalisesValeurs[1][1] = nullptr;
	pctabBalisesValeurs[2][0] = _strdup(NBCOLONNES);
	pctabBalisesValeurs[2][1] = nullptr;
	pctabBalisesValeurs[3][0] = _strdup(MATRICE);
	pctabBalisesValeurs[3][1] = nullptr;

	pcType = nullptr;
}

/******************************************************************************
Constructeur de recopie
*******************************************************************************
Entr�e : R�f�rence sur un objet de type Cparseur
Necessit� : N�ant
Sortie : Rien
Entraine : L'objet a �t� initialis� par recopie de l'objet en param�tre
******************************************************************************/
Cparseur::Cparseur(Cparseur & PARObjet)
{	
	pctabBalisesValeurs[0][0] = _strdup(PARObjet.pctabBalisesValeurs[0][0]);
	pctabBalisesValeurs[0][1] = _strdup(PARObjet.pctabBalisesValeurs[0][1]);
	pctabBalisesValeurs[1][0] = _strdup(PARObjet.pctabBalisesValeurs[1][0]);
	pctabBalisesValeurs[1][1] = _strdup(PARObjet.pctabBalisesValeurs[1][1]);
	pctabBalisesValeurs[2][0] = _strdup(PARObjet.pctabBalisesValeurs[2][0]);
	pctabBalisesValeurs[2][1] = _strdup(PARObjet.pctabBalisesValeurs[2][1]);
	pctabBalisesValeurs[3][0] = _strdup(PARObjet.pctabBalisesValeurs[3][0]);
	pctabBalisesValeurs[3][1] = _strdup(PARObjet.pctabBalisesValeurs[3][1]);

	pcType = _strdup(PARObjet.pcType);
}

/******************************************************************************
Destructeur
*******************************************************************************
Entr�e : Rien
Necessit� : N�ant
Sortie : Rien
Entraine : L'espace allou� pour les attributs de l'objet a �t� lib�r�
******************************************************************************/
Cparseur::~Cparseur()
{
	free(pctabBalisesValeurs[0][0]);
	free(pctabBalisesValeurs[0][1]);
	free(pctabBalisesValeurs[1][0]);
	free(pctabBalisesValeurs[1][1]);
	free(pctabBalisesValeurs[2][0]);
	free(pctabBalisesValeurs[2][1]);
	free(pctabBalisesValeurs[3][0]);
	free(pctabBalisesValeurs[3][1]);

	free(pcType);
}

/******************************************************************************
PARLireMatrice
*******************************************************************************
Entr�e : pcfilename le chemin d'acc�s au fichier (cha�ne de caract�re)
Necessit� : Le fichier existe
Sortie : Un objet CMatrice de type MType
Entraine : la matrice est lue puis retourn�
******************************************************************************/
void Cparseur::PARLireMatrice(char * pcfilename)
{
	unsigned int uiCompteur = 0;
	unsigned int uiCompteurpcLigne, uiCompteurpcTempMat = 0;
	char pcLigne[256]; //Stocke une ligne du fichier sur laquelle on va faire nos op�rations
	char * pcTempMat; //Tampon utilis� dans la lecture du corps de la matrice
	char * pcTemp; //Tampon utilis� dans la lecture de tout le fichier
		
	/*
	if(pcLigne == nullptr);
		throw Cexception(1, "Lors de l'initialisation de la methode (PARLireMatrice) 2");
*/
	pcTempMat = (char *) malloc(sizeof(char));
	if(pcTempMat == nullptr)
		throw Cexception(1, "Lors de l'initialisation de la methode (PARLireMatrice) 1");
	pcTempMat[uiCompteurpcTempMat] = '\0';
	
		
	//Ouverture du fichier
	ifstream fichier(pcfilename, ios::in);
	if(fichier.fail())
		throw Cexception(5);

	//Boucle tant que la fin du fichier n'est pas atteinte
	while(fichier.getline(pcLigne, 256))
	{
		//On place le compteur de la ligne au d�but et on la met en majuscule
		uiCompteurpcLigne = 0;
		_strupr_s(pcLigne, strlen(pcLigne) + 1);

		pcTemp = pcLigne;//pour pouvoir manipuler la cha�ne

		//On cherche la premi�re balise sur la ligne : TYPEMATRICE
		pcTemp = strstr(pcLigne, pctabBalisesValeurs[0][0]);
		if(pcTemp != nullptr)
		{
			pctabBalisesValeurs[0][1] = PARrecupererElement(pcTemp); // on r�cup�re le d�t Elmt
			PAReffacerElmt(pctabBalisesValeurs[0][0], pctabBalisesValeurs[0][1], pcTemp); // et on l'efface du tampon
		}
		
		//On cherche la deuxi�me balise sur la m�me ligne : NBLIGNES
		pcTemp = strstr(pcLigne, pctabBalisesValeurs[1][0]);
		if(pcTemp!= nullptr)
		{
			pctabBalisesValeurs[1][1] = PARrecupererElement(pcTemp); // on r�cup�re le d�t Elmt
			PAReffacerElmt(pctabBalisesValeurs[1][0], pctabBalisesValeurs[1][1], pcTemp); // et on l'efface du tampon
		}
		
		//On cherche la troisi�me balise sur la m�me ligne : NBCOLONNES
		pcTemp = strstr(pcLigne, pctabBalisesValeurs[2][0]);
		if(pcTemp != nullptr)
		{
			pctabBalisesValeurs[2][1] = PARrecupererElement(pcTemp); // on r�cup�re le d�t Elmt
			PAReffacerElmt(pctabBalisesValeurs[2][0], pctabBalisesValeurs[2][1], pcTemp); // et on l'efface du tampon
		}
		
		//Puis on cherche la matrice : MATRICE
		pcTemp = strstr(pcLigne, pctabBalisesValeurs[3][0]);
		if(pcTemp != nullptr)
		{
			//On avance jusqu'au '['
			while(pcTemp[uiCompteurpcLigne] != '[')
			{
				if(pcTemp[uiCompteurpcLigne] == '\0')
				{
					if(!fichier.getline(pcTemp, 256))
						throw Cexception(6, "Fin du fichier atteint, '[' attendu");

					uiCompteurpcLigne = 0;
				}
				else
					uiCompteurpcLigne++;
			}
			uiCompteurpcLigne++;

			//Ensuite on prend tout jusqu'au ']' ou jusqu'� la fin du fichier
			while(pcTemp[uiCompteurpcLigne] != ']')
			{
				if(pcTemp[uiCompteurpcLigne] == '\0')
				{
					pcTempMat = (char *) realloc(pcTempMat, sizeof(char) * (strlen(pcTempMat) + 1));
					if(pcTempMat == nullptr)
						throw Cexception(2, "Dans la methode PARLireMatrice");

					pcTempMat[uiCompteurpcTempMat] = ' ';
					uiCompteurpcTempMat++;

					if(!fichier.getline(pcTemp, 256))
						throw Cexception(6, "Fin du fichier atteint, ']' attendu");

					uiCompteurpcLigne = 0;
				}
				else
				{
					pcTempMat = (char *) realloc(pcTempMat, sizeof(char) * (strlen(pcTempMat) + 1));
					if(pcTempMat == nullptr)
						throw Cexception(2, "Dans la methode PARLireMatrice");

					pcTempMat[uiCompteurpcTempMat] = pcTemp[uiCompteurpcLigne];
					uiCompteurpcLigne++;
					uiCompteurpcTempMat++;
				}
			}
			pcTempMat[uiCompteurpcTempMat] = '\0';
			pctabBalisesValeurs[3][1] = _strdup(pcTempMat);
		}
	}


	//Puis test si tout a bien �t� r�cup�r�
	for(uiCompteur = 0; uiCompteur < NBRBALISES; uiCompteur++)
	{
		if(pctabBalisesValeurs[uiCompteur][1] == nullptr)
			throw Cexception(6, "Fin du fichier , toute les informations n'ont pas �t� renseign�es");
	}
		
	//et on essaie de reconnaitre le type
	PARreconnaitreType(pctabBalisesValeurs[0][1]);

	//Pour finalement fermer le fichier et lib�rer les variables interm�diaires
	fichier.close();
	free(pcTempMat);
}

/******************************************************************************
PARcreerMatrice
*******************************************************************************
Entr�e : Une matrice de cha�ne de caract�res contenant les donn�es brut de la matrice
Necessit� : Les donn�es sont coh�rentes
Sortie : Un objet CMatrice de type MType
Entraine : L'objet retourn� a bien �t� initialis� avec des valeurs coh�rente
******************************************************************************/
CMatrice<double> * Cparseur::PARcreerDoubleMatrice()
{
	double ** ppdMatrice;
	unsigned int uiNbrLignes, uiNbrColonnes;
	unsigned int uiCptrLignes, uiCptrColonnes;
	char * pcEnd;
	CMatrice<double> * dMATMatrice;
	
	//Cette fonction ne peut retourner qu'une matrice de type double
	if(strcmp(pcType, DOUBLE) != 0)
		return nullptr;


	uiNbrLignes = PARreconnaitreTaille(pctabBalisesValeurs[1][1]);
	uiNbrColonnes = PARreconnaitreTaille(pctabBalisesValeurs[2][1]);

	ppdMatrice = new double*[uiNbrLignes];
	for(uiCptrLignes = 0; uiCptrLignes < uiNbrLignes; uiCptrLignes++)
		ppdMatrice[uiCptrLignes] = new double[uiNbrColonnes];

	ppdMatrice[0][0] = strtod(pctabBalisesValeurs[3][1], &pcEnd);
	uiCptrColonnes = 1;

	for(uiCptrLignes = 0; uiCptrLignes < uiNbrLignes; uiCptrLignes++)
	{
		for(; uiCptrColonnes < uiNbrColonnes; uiCptrColonnes++)
		{
			ppdMatrice[uiCptrLignes][uiCptrColonnes] = strtod(pcEnd, &pcEnd);
			if(pcEnd == nullptr && (uiCptrColonnes < uiNbrColonnes || uiCptrLignes < uiNbrLignes))
				throw Cexception(6, "La taille de la Matrice lue ne correspond pas a la taille reelle");
		}
		uiCptrColonnes = 0;
	}

	dMATMatrice = new CMatrice<double>(ppdMatrice, uiNbrColonnes, uiNbrLignes);
	
	delete ppdMatrice;
	
	return dMATMatrice;
}

/******************************************************************************
PARreconnaitreType
*******************************************************************************
Entr�e : une cha�ne de caract�res
Necessit� : N�ant
Sortie : Le type d�tect� (cha�ne de caract�res pr�d�finie) ou nullptr si pas de type reconnu
Entraine : Le bon type a �t� d�tect� ou aucun ne l'a �t�
******************************************************************************/
void Cparseur::PARreconnaitreType(char * pcElm)
{
	_strupr_s(pcElm, strlen(pcElm) + 1);
	if(strcmp(pcElm, DOUBLE) == 0)
		pcType= _strdup(DOUBLE);
	else if(strcmp(pcElm, INTEGER) == 0)
		pcType = _strdup(INTEGER);
	else if(strcmp(pcElm, FLOAT) == 0)
		pcType = _strdup(FLOAT);
	else if(strcmp(pcElm, CHARACTER) == 0)
		pcType = _strdup(CHARACTER);
	else
		pcType = nullptr;
	
	if(pcType == nullptr || strcmp(pcType, DOUBLE) != 0)
	{
		throw Cexception(6, "Type inconnu (cette version ne prend en compte que le type Double)");
	}

	pctabBalisesValeurs[0][1] = _strdup(pcType);
}

/******************************************************************************
PARgetType
*******************************************************************************
Entr�e : Rien
Necessit� : N�ant
Sortie : Retourne la valeur non modifiable du type de la derni�re matrice nulle
Entraine : L'objet a �t� initialis�
******************************************************************************/
const char * Cparseur::PARgetType()
{
	return (const char *)pcType;
}

/******************************************************************************
PARreconnaitreTaille
*******************************************************************************
Entr�e : une cha�ne de caract�res
Necessit� : le param�tre est convertible en int
Sortie : L'entier d�tect�
Entraine : L'entier retourn� est une taille valide
******************************************************************************/
unsigned int Cparseur::PARreconnaitreTaille(char * pcElm)
{
	long int liTemp;
	liTemp = strtol(pcElm, NULL, 0);
	if(liTemp == 0L || liTemp == liTemp * (-1))
		throw Cexception(6, "Impossible de reconnaitre la taille donnee pour la matrice");

	return (unsigned int)liTemp;
}

/******************************************************************************
PARrecupererElement
*******************************************************************************
Entr�e : une cha�ne de caract�res
Necessit� : La balise est associ� � un �l�ment
Sortie : L'�l�ment associ� � la balise (cha�ne de caract�re)
Entraine : Un �l�ment a �t� d�tect� et retourn�
******************************************************************************/
char * Cparseur::PARrecupererElement(char * pcElm)
{
	char * pcTemp;
	char * pcRetour = nullptr;
	unsigned int uiCptr = 0;

	pcTemp = strchr(pcElm, '=');
	if(pcTemp == nullptr)
		throw Cexception(6, "Pas de valeur trouv� pour la matrice, elle doit se trouver sur la m�me ligne que la balise");

	if(*(pcTemp) != '\0')
	{
		pcTemp++;
		while(*(pcTemp) == ' ' && *(pcTemp) != '\0')
			pcTemp++;
		while(*(pcTemp) != ' ' && *(pcTemp) != '\0')
		{
			if(pcRetour == nullptr)
			{
				pcRetour = (char*)malloc(sizeof(char));
				if(pcRetour == nullptr)
					throw Cexception(1, "Dans la fonction PARrecupererElement");
			}
			else
				pcRetour = (char *)realloc(pcRetour, sizeof(char) *(strlen(pcRetour) + 1));

			pcRetour[uiCptr] = *pcTemp;
			pcTemp++;
			uiCptr++;
		}
		pcRetour[uiCptr] = '\0';
	}
	else pcRetour = nullptr;

	if(pcRetour == nullptr || strlen(pcRetour) == 0)
		throw Cexception(6, "Pas de valeur trouv� pour la matrice, elle doit se trouver sur la m�me ligne que la balise");

	return pcRetour;
}

/******************************************************************************
PAReffacerElmt
*******************************************************************************
Entr�e : trois cha�nes de caract�res : les deux �l�ment � supprimer de la troisi�me
Necessit� : N�ant
Sortie : Rien
Entraine : Les deux cha�nes et le �gal ont �t� supprim�s de la cha�ne pcSrc
******************************************************************************/
void Cparseur::PAReffacerElmt(char * pcElmt, char * pcValeur, char * pcSrc)
{
	unsigned int uiCptrBalise, uiCptrValeur;

	//On efface la balise
	for(uiCptrBalise = 0; uiCptrBalise < strlen(pcElmt); uiCptrBalise++)
		pcSrc[uiCptrBalise] = ' ';

	//On efface les blancs et l'�gal
	while (pcSrc[uiCptrBalise] == ' ' || pcSrc[uiCptrBalise] == '=')
	{
		pcSrc[uiCptrBalise] = ' ';
		uiCptrBalise++;
	}

	//On efface la valeur
	for(uiCptrValeur = 0; uiCptrValeur < strlen(pcValeur); uiCptrValeur++)
		pcSrc[uiCptrBalise + uiCptrValeur] = ' ';
}

/******************************************************************************
PAREnregistrerMatrice

~~~~~~~Fonction vide pr�par�e pour une possible am�lioration de la classe~~~~~~

*******************************************************************************
Entr�e : pcfilename le chemin d'acc�s au fichier (chaine de caract�re), une matrice de type MType
Necessit� : le chemin d'acc�s est valide
Sortie : Rien
Entraine : La matrice a �t� enregistr� au bon format r�cup�rable dans le bon fichier
******************************************************************************/
template<typename MType> void Cparseur::PAREnregistrerMatrice(char * pcfilename, CMatrice<MType> & MTMATMatrice) // Pour une possible extension
{

}
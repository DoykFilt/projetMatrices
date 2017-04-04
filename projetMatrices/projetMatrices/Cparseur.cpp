#include <fstream>
#include <iostream>
#include "Cparseur.h"
#include <string.h>

using namespace std;

Cparseur::Cparseur()
{	
	pctabBalisesValeurs[0][0] = _strdup(TYPEMATRICE);
	pctabBalisesValeurs[0][1] = _strdup("");
	pctabBalisesValeurs[1][0] = _strdup(NBLIGNES);
	pctabBalisesValeurs[1][1] = _strdup("");
	pctabBalisesValeurs[2][0] = _strdup(NBCOLONNES);
	pctabBalisesValeurs[2][1] = _strdup("");
	pctabBalisesValeurs[3][0] = _strdup(MATRICE);
	pctabBalisesValeurs[3][1] = _strdup("");

	pcType = nullptr;
}

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
Entrée : pcfilename le chemin d'accès au fichier (chaîne de caractère)
Necessité : Le fichier existe
Sortie : Un objet CMatrice de type MType
Entraine : la matrice est lue puis retourné
******************************************************************************/
void Cparseur::PARLireMatrice(char * pcfilename)
{
	unsigned int uiCompteur = 0;
	unsigned int uiCompteurpcLigne = 0, uiCompteurpcTemp = 0;
	char * pcLigne = (char *) malloc(sizeof(char) * 256);
	char * pcTemp;
		
	pcTemp = (char *) malloc(sizeof(char));
	if(pcTemp == nullptr)
	{
		//erreur d'allocation
	}
	pcTemp[uiCompteurpcTemp] = '\0';


	// *************** On collecte d'abord les lignes et éléments ************************
	ifstream fichier(pcfilename, ios::in);
	if(fichier.fail())
	{
		//erreur le fichier n'existe pas
		cout << "Fichier non trouvé !"<<endl;
	}

	while(fichier.getline(pcLigne, 256))
	{
		uiCompteurpcLigne = 0;
		_strupr_s(pcLigne, strlen(pcLigne) + 1);

		if(strstr(pcLigne, pctabBalisesValeurs[0][0]) != NULL)
		{
			pctabBalisesValeurs[0][1] = PARrecupererElement(pcLigne);
		}
		else if(strstr(pcLigne, pctabBalisesValeurs[1][0]) != NULL)
		{
			pctabBalisesValeurs[1][1] = PARrecupererElement(pcLigne);
		}
		else if(strstr(pcLigne, pctabBalisesValeurs[2][0]) != NULL)
		{
			pctabBalisesValeurs[2][1] = PARrecupererElement(pcLigne);
		}
		else if(strstr(pcLigne, pctabBalisesValeurs[3][0]) != NULL)
		{
			//On avance jusqu'à '['
			while(pcLigne[uiCompteurpcLigne] != '[')
			{
				if(pcLigne[uiCompteurpcLigne] == '\0')
				{
					if(!fichier.getline(pcLigne, 256))
					{
						//Erreur fin du fichier atteint, '[' recherché !
					}
					uiCompteurpcLigne = 0;
				}
				else
					uiCompteurpcLigne++;
			}
			uiCompteurpcLigne++;
			//Ensuite on prend tout jusqu'au ']' ou jusqu'à la fin du fichier
			while(pcLigne[uiCompteurpcLigne] != ']')
			{
				if(pcLigne[uiCompteurpcLigne] == '\0')
				{
					pcTemp = (char *) realloc(pcTemp, sizeof(char) * (strlen(pcTemp) + 1));
					if(pcTemp == nullptr)
					{
						//erreur reallocation échouée
					}
					pcTemp[uiCompteurpcTemp] = ' ';
					uiCompteurpcTemp++;

					if(!fichier.getline(pcLigne, 256))
					{
						//Erreur fin du fichier atteint, ']' recherché !
					}
					uiCompteurpcLigne = 0;
				}
				else
				{
					pcTemp = (char *) realloc(pcTemp, sizeof(char) * (strlen(pcTemp) + 1));
					if(pcTemp == nullptr)
					{
						//erreur reallocation échouée
					}
					pcTemp[uiCompteurpcTemp] = pcLigne[uiCompteurpcLigne];
					uiCompteurpcLigne++;
					uiCompteurpcTemp++;
				}
			}
			pcTemp[uiCompteurpcTemp] = '\0';
			pctabBalisesValeurs[3][1] = _strdup(pcTemp);
		}
	}
	fichier.close();
	free(pcLigne);
	free(pcTemp);


	//On test si tout a bien été récupéré
	for(uiCompteur = 0; uiCompteur < NBRBALISES; uiCompteur++)
	{
		if(strcmp(pctabBalisesValeurs[uiCompteur][1], ""))
		{
			//erreur toute les informations n'ont pas été renseignées
		}
	}
		
	//et on essaie de reconnaitre le type
	PARreconnaitreType(pctabBalisesValeurs[0][1]);
}

/******************************************************************************
PARcreerMatrice
*******************************************************************************
Entrée : Une matrice de chaîne de caractères contenant les données brut de la matrice
Necessité : Les données sont cohérentes
Sortie : Un objet CMatrice de type MType
Entraine : L'objet retourné a bien été initialisé avec des valeurs cohérente
******************************************************************************/
CMatrice<double> * Cparseur::PARcreerDoubleMatrice()
{
	if(strcmp(pcType, DOUBLE) != 0)
		return nullptr;

	double ** ppdMatrice;
	unsigned int uiNbrLignes, uiNbrColonnes;
	unsigned int uiCptrLignes, uiCptrColonnes;
	char * pcEnd;
	
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
			{
				//erreur le nombre de ligne ou de colonnes ne correspond pas à la matrice rentrée
			}
		}
		uiCptrColonnes = 0;
	}

	CMatrice<double> * dMATMatrice = new CMatrice<double>(ppdMatrice, uiNbrColonnes, uiNbrLignes);
	
	delete ppdMatrice;
	
	return dMATMatrice;
}

/******************************************************************************
PARreconnaitreType
*******************************************************************************
Entrée : une chaîne de caractères
Necessité : Néant
Sortie : Le type détecté (chaîne de caractères prédéfinie) ou nullptr si pas de type reconnu
Entraine : Le bon type a été détecté ou aucun ne l'a été
******************************************************************************/
void Cparseur::PARreconnaitreType(char * pcElm)
{
	free(pcType);

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
	{
		//erreur valeur en parametre inconnu
		pcType = nullptr;
	}
	
	if(pcType == nullptr || strcmp(pcType, DOUBLE) != 0)
	{
		//erreur cette version ne prend en compte que des mtrices de DOUBLE
	}

	pctabBalisesValeurs[0][1] = _strdup(pcType);
}

const char * Cparseur::PARgetType()
{
	return (const char *)pcType;
}

/******************************************************************************
PARreconnaitreTaille
*******************************************************************************
Entrée : une chaîne de caractères
Necessité : le paramètre est convertible en int
Sortie : L'entier détecté
Entraine : L'entier retourné est une taille valide
******************************************************************************/
unsigned int Cparseur::PARreconnaitreTaille(char * pcElm)
{
	long int liTemp;
	liTemp = strtol(pcElm, NULL, 0);
	if(liTemp == 0L || liTemp == liTemp * (-1))
	{
		//erreur paramètre non valide
	}
	return (unsigned int)liTemp;
}

/******************************************************************************
PARrecupererElement
*******************************************************************************
Entrée : une chaîne de caractères
Necessité : La balise est associé à un élément
Sortie : L'élément associé à la balise (chaîne de caractère)
Entraine : Un élément a été détecté et retourné
******************************************************************************/
char * Cparseur::PARrecupererElement(char * pcElm)
{
	char * pcTemp;
	char * pcRetour = nullptr;
	unsigned int uiCptr = 0;

	if(pcRetour == nullptr)
	{
		//erreur d'allocation
	}

	pcTemp = strchr(pcElm, '=');
	if(pcTemp == nullptr)
	{
		//erreur : pas de valeur trouvé pour la balise, elle doit se trouver sur la même ligne
	}
	if(*(pcTemp) != '\0')
	{
		pcTemp++;
		while(*(pcTemp) == ' ' && *(pcTemp) != '\0')
			pcTemp++;
		while(*(pcTemp) != ' ' && *(pcTemp) != '\0')
		{
			if(pcRetour == nullptr)
				pcRetour = (char*)malloc(sizeof(char));
			else
				pcRetour = (char *)realloc(pcRetour, sizeof(char) *(strlen(pcRetour) + 1));
			if(pcRetour == nullptr)
			{
				//erreur d'allocation
			}
			pcRetour[uiCptr] = *pcTemp;
			pcTemp++;
			uiCptr++;
		}
		pcRetour[uiCptr] = '\0';
	}
	else pcRetour = nullptr;

	if(pcRetour == nullptr || strlen(pcRetour) == 0)
	{
		//erreur : pas de valeur trouvé pour la balise, elle doit se trouver sur la même ligne
	}

	return pcRetour;
}

/******************************************************************************
PAREnregistrerMatrice

~~~~~~~Fonction vide préparée pour une possible amélioration de la classe~~~~~~

*******************************************************************************
Entrée : pcfilename le chemin d'accès au fichier (chaine de caractère), une matrice de type MType
Necessité : le chemin d'accès est valide
Sortie : Rien
Entraine : La matrice a été enregistré au bon format récupérable dans le bon fichier
******************************************************************************/
template<typename MType> void Cparseur::PAREnregistrerMatrice(char * pcfilename, CMatrice<MType> & MTMATMatrice) // Pour une possible extension
{

}
#include <fstream>
#include <iostream>
#include "Cparseur.h"
#include <string.h>

using namespace std;

/******************************************************************************
Constructeur
*******************************************************************************
Entrée : Rien
Necessité : Néant
Sortie : Rien
Entraine : L'objet a été initialisé
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
Entrée : Référence sur un objet de type Cparseur
Necessité : Néant
Sortie : Rien
Entraine : L'objet a été initialisé par recopie de l'objet en paramètre
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
Entrée : Rien
Necessité : Néant
Sortie : Rien
Entraine : L'espace alloué pour les attributs de l'objet a été libéré
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
Entrée : pcfilename le chemin d'accès au fichier (chaîne de caractère)
Necessité : Le fichier existe
Sortie : Un objet CMatrice de type MType
Entraine : la matrice est lue puis retourné
******************************************************************************/
void Cparseur::PARLireMatrice(char * pcfilename)
{
	unsigned int uiCompteur = 0;
	unsigned int uiCompteurpcLigne, uiCompteurpcTempMat = 0;
	char pcLigne[256]; //Stocke une ligne du fichier sur laquelle on va faire nos opérations
	char * pcTempMat; //Tampon utilisé dans la lecture du corps de la matrice
	char * pcTemp; //Tampon utilisé dans la lecture de tout le fichier
		
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
		//On place le compteur de la ligne au début et on la met en majuscule
		uiCompteurpcLigne = 0;
		_strupr_s(pcLigne, strlen(pcLigne) + 1);

		pcTemp = pcLigne;//pour pouvoir manipuler la chaîne

		//On cherche la première balise sur la ligne : TYPEMATRICE
		pcTemp = strstr(pcLigne, pctabBalisesValeurs[0][0]);
		if(pcTemp != nullptr)
		{
			pctabBalisesValeurs[0][1] = PARrecupererElement(pcTemp); // on récupère le dît Elmt
			PAReffacerElmt(pctabBalisesValeurs[0][0], pctabBalisesValeurs[0][1], pcTemp); // et on l'efface du tampon
		}
		
		//On cherche la deuxième balise sur la même ligne : NBLIGNES
		pcTemp = strstr(pcLigne, pctabBalisesValeurs[1][0]);
		if(pcTemp!= nullptr)
		{
			pctabBalisesValeurs[1][1] = PARrecupererElement(pcTemp); // on récupère le dît Elmt
			PAReffacerElmt(pctabBalisesValeurs[1][0], pctabBalisesValeurs[1][1], pcTemp); // et on l'efface du tampon
		}
		
		//On cherche la troisième balise sur la même ligne : NBCOLONNES
		pcTemp = strstr(pcLigne, pctabBalisesValeurs[2][0]);
		if(pcTemp != nullptr)
		{
			pctabBalisesValeurs[2][1] = PARrecupererElement(pcTemp); // on récupère le dît Elmt
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

			//Ensuite on prend tout jusqu'au ']' ou jusqu'à la fin du fichier
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


	//Puis test si tout a bien été récupéré
	for(uiCompteur = 0; uiCompteur < NBRBALISES; uiCompteur++)
	{
		if(pctabBalisesValeurs[uiCompteur][1] == nullptr)
			throw Cexception(6, "Fin du fichier , toute les informations n'ont pas été renseignées");
	}
		
	//et on essaie de reconnaitre le type
	PARreconnaitreType(pctabBalisesValeurs[0][1]);

	//Pour finalement fermer le fichier et libérer les variables intermédiaires
	fichier.close();
	free(pcTempMat);
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
Entrée : une chaîne de caractères
Necessité : Néant
Sortie : Le type détecté (chaîne de caractères prédéfinie) ou nullptr si pas de type reconnu
Entraine : Le bon type a été détecté ou aucun ne l'a été
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
Entrée : Rien
Necessité : Néant
Sortie : Retourne la valeur non modifiable du type de la dernière matrice nulle
Entraine : L'objet a été initialisé
******************************************************************************/
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
		throw Cexception(6, "Impossible de reconnaitre la taille donnee pour la matrice");

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

	pcTemp = strchr(pcElm, '=');
	if(pcTemp == nullptr)
		throw Cexception(6, "Pas de valeur trouvé pour la matrice, elle doit se trouver sur la même ligne que la balise");

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
		throw Cexception(6, "Pas de valeur trouvé pour la matrice, elle doit se trouver sur la même ligne que la balise");

	return pcRetour;
}

/******************************************************************************
PAReffacerElmt
*******************************************************************************
Entrée : trois chaînes de caractères : les deux élément à supprimer de la troisième
Necessité : Néant
Sortie : Rien
Entraine : Les deux chaînes et le égal ont été supprimés de la chaîne pcSrc
******************************************************************************/
void Cparseur::PAReffacerElmt(char * pcElmt, char * pcValeur, char * pcSrc)
{
	unsigned int uiCptrBalise, uiCptrValeur;

	//On efface la balise
	for(uiCptrBalise = 0; uiCptrBalise < strlen(pcElmt); uiCptrBalise++)
		pcSrc[uiCptrBalise] = ' ';

	//On efface les blancs et l'égal
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
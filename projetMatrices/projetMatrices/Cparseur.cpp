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
	pcPARtabBalisesValeurs[0][0] = _strdup(TYPEMATRICE);
	pcPARtabBalisesValeurs[0][1] = nullptr;
	pcPARtabBalisesValeurs[1][0] = _strdup(NBLIGNES);
	pcPARtabBalisesValeurs[1][1] = nullptr;
	pcPARtabBalisesValeurs[2][0] = _strdup(NBCOLONNES);
	pcPARtabBalisesValeurs[2][1] = nullptr;
	pcPARtabBalisesValeurs[3][0] = _strdup(MATRICE);
	pcPARtabBalisesValeurs[3][1] = nullptr;

	pcPARType = nullptr;
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
	pcPARtabBalisesValeurs[0][0] = _strdup(PARObjet.pcPARtabBalisesValeurs[0][0]);
	pcPARtabBalisesValeurs[0][1] = _strdup(PARObjet.pcPARtabBalisesValeurs[0][1]);
	pcPARtabBalisesValeurs[1][0] = _strdup(PARObjet.pcPARtabBalisesValeurs[1][0]);
	pcPARtabBalisesValeurs[1][1] = _strdup(PARObjet.pcPARtabBalisesValeurs[1][1]);
	pcPARtabBalisesValeurs[2][0] = _strdup(PARObjet.pcPARtabBalisesValeurs[2][0]);
	pcPARtabBalisesValeurs[2][1] = _strdup(PARObjet.pcPARtabBalisesValeurs[2][1]);
	pcPARtabBalisesValeurs[3][0] = _strdup(PARObjet.pcPARtabBalisesValeurs[3][0]);
	pcPARtabBalisesValeurs[3][1] = _strdup(PARObjet.pcPARtabBalisesValeurs[3][1]);

	pcPARType = _strdup(PARObjet.pcPARType);
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
	free(pcPARtabBalisesValeurs[0][0]);
	free(pcPARtabBalisesValeurs[0][1]);
	free(pcPARtabBalisesValeurs[1][0]);
	free(pcPARtabBalisesValeurs[1][1]);
	free(pcPARtabBalisesValeurs[2][0]);
	free(pcPARtabBalisesValeurs[2][1]);
	free(pcPARtabBalisesValeurs[3][0]);
	free(pcPARtabBalisesValeurs[3][1]);

	free(pcPARType);
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
		pcTemp = strstr(pcLigne, pcPARtabBalisesValeurs[0][0]);
		if(pcTemp != nullptr)
		{
			pcPARtabBalisesValeurs[0][1] = PARrecupererElement(pcTemp); // on récupère le dît Elmt
			PAReffacerElmt(pcPARtabBalisesValeurs[0][0], pcPARtabBalisesValeurs[0][1], pcTemp); // et on l'efface du tampon
		}
		
		//On cherche la deuxième balise sur la même ligne : NBLIGNES
		pcTemp = strstr(pcLigne, pcPARtabBalisesValeurs[1][0]);
		if(pcTemp!= nullptr)
		{
			pcPARtabBalisesValeurs[1][1] = PARrecupererElement(pcTemp); // on récupère le dît Elmt
			PAReffacerElmt(pcPARtabBalisesValeurs[1][0], pcPARtabBalisesValeurs[1][1], pcTemp); // et on l'efface du tampon
		}
		
		//On cherche la troisième balise sur la même ligne : NBCOLONNES
		pcTemp = strstr(pcLigne, pcPARtabBalisesValeurs[2][0]);
		if(pcTemp != nullptr)
		{
			pcPARtabBalisesValeurs[2][1] = PARrecupererElement(pcTemp); // on récupère le dît Elmt
			PAReffacerElmt(pcPARtabBalisesValeurs[2][0], pcPARtabBalisesValeurs[2][1], pcTemp); // et on l'efface du tampon
		}
		
		//Puis on cherche la matrice : MATRICE
		pcTemp = strstr(pcLigne, pcPARtabBalisesValeurs[3][0]);
		if(pcTemp != nullptr)
		{
			//On avance jusqu'au '['
			while(pcTemp[uiCompteurpcLigne] != '[')
			{
				if(pcTemp[uiCompteurpcLigne] == '\0')
				{
					if(!fichier.getline(pcTemp, 256))
						throw Cexception(6, "Fin du fichier atteint, ']' attendu");

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
			pcPARtabBalisesValeurs[3][1] = _strdup(pcTempMat);
		}
	}


	//Puis test si tout a bien été récupéré
	for(uiCompteur = 0; uiCompteur < NBRBALISES; uiCompteur++)
	{
		if(pcPARtabBalisesValeurs[uiCompteur][1] == nullptr)
			throw Cexception(6, "Fin du fichier , toutes les informations n'ont pas ete renseignees");
	}
		
	//et on essaie de reconnaitre le type
	PARreconnaitreType(pcPARtabBalisesValeurs[0][1]);

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

	CMatrice<double> * dMATMatrice;
	
	//sept variables utilisées pour la reconnaissance des chiffres
	char * pcfix, *pcdef;
	char * pctemp;
	unsigned int uicfix = 0, uicdef = 0, uitemplen = 0;

	//Cette fonction ne peut retourner qu'une matrice de type double
	if(strcmp(pcPARType, DOUBLE) != 0)
		return nullptr;


	uiNbrLignes = PARreconnaitreTaille(pcPARtabBalisesValeurs[1][1]);
	uiNbrColonnes = PARreconnaitreTaille(pcPARtabBalisesValeurs[2][1]);

	ppdMatrice = new double*[uiNbrLignes];
	for(uiCptrLignes = 0; uiCptrLignes < uiNbrLignes; uiCptrLignes++)
		ppdMatrice[uiCptrLignes] = new double[uiNbrColonnes];
	
	pcfix = pcPARtabBalisesValeurs[3][1];
	pcdef = pcPARtabBalisesValeurs[3][1];
	pctemp = (char *)malloc(uitemplen + 1);
	pctemp[0] = '\0';

	for(uiCptrLignes = 0; uiCptrLignes < uiNbrLignes; uiCptrLignes++)
	{
		for(uiCptrColonnes = 0; uiCptrColonnes < uiNbrColonnes; uiCptrColonnes++)
		{
			while(pcfix[uicfix] == ' ' && pcfix[uicfix] != '\0') uicfix++;
			uicdef = uicfix;
			while(pcdef[uicdef] != ' ' && pcdef[uicdef] != '\0') uicdef++;

			if(pcfix[uicfix] == '\0')
			{
				free(pctemp);
				throw Cexception(6, "La taille de la Matrice lue ne correspond pas a la taille reelle");
			}

			for(int i = 0; uicfix + i < uicdef; i++)
			{
				uitemplen ++;
				pctemp = (char *)realloc(pctemp, uitemplen + 1);
				pctemp[i] = pcfix[uicfix + i];
				pctemp[i + 1] = '\0';
			}
			ppdMatrice[uiCptrLignes][uiCptrColonnes] = atof(pctemp);
			uicfix = uicdef;
			uitemplen = 0;
			pctemp = (char *)realloc(pctemp, uitemplen + 1);
			pctemp[0] = '\0';
		}
	}

	dMATMatrice = new CMatrice<double>(ppdMatrice, uiNbrLignes, uiNbrColonnes);
	
	delete ppdMatrice;
	free(pctemp);
	
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
		pcPARType= _strdup(DOUBLE);
	else if(strcmp(pcElm, INTEGER) == 0)
		pcPARType = _strdup(INTEGER);
	else if(strcmp(pcElm, FLOAT) == 0)
		pcPARType = _strdup(FLOAT);
	else if(strcmp(pcElm, CHARACTER) == 0)
		pcPARType = _strdup(CHARACTER);
	else
		pcPARType = nullptr;
	
	if(pcPARType == nullptr || strcmp(pcPARType, DOUBLE) != 0)
	{
		throw Cexception(6, "Type inconnu (cette version ne prend en compte que le type Double)");
	}

	pcPARtabBalisesValeurs[0][1] = _strdup(pcPARType);
}

/******************************************************************************
PARgetType
*******************************************************************************
Entrée : Rien
Necessité : Néant
Sortie : Retourne la valeur non modifiable du type de la dernière matrice nulle
Entraine : L'objet a été initialisé
******************************************************************************/
inline const char * Cparseur::PARgetType()
{
	return (const char *)pcPARType;
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
	//on utilise strtol au cas où l'utilisateur aurait rentré un long ou un double au lieu d'un int
	liTemp = strtol(pcElm, NULL, 0);
	if(liTemp == 0L || liTemp == liTemp * (-1))
		throw Cexception(6, "Impossible de reconnaitre la taille donnee pour la matrice");

	if(liTemp < 0)
		throw Cexception(6, "La taille de la matrice doit être positive");

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
		throw Cexception(6, "Pas de valeur trouve pour la matrice, elle doit se trouver sur la meme ligne que la balise");

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
		throw Cexception(6, "Pas de valeur trouve pour la matrice, elle doit se trouver sur la meme ligne que la balise");

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
surcharge de l'opérateur d'affectation
*******************************************************************************
	Entrée : un objet du même type
	Necessité : Néant
	Sortie : Une référence sur l'objet en cours qui a été modifié
	Entraine : L'objet en cours est une copie de l'objet en paramètre
******************************************************************************/
Cparseur & Cparseur::operator=(Cparseur const & PARparseur)
{
	free(pcPARtabBalisesValeurs[0][1]);
	free(pcPARtabBalisesValeurs[1][1]);
	free(pcPARtabBalisesValeurs[2][1]);
	free(pcPARtabBalisesValeurs[3][1]);
	free(pcPARType);

	pcPARtabBalisesValeurs[0][1] = _strdup(PARparseur.pcPARtabBalisesValeurs[0][1]);
	pcPARtabBalisesValeurs[1][1] = _strdup(PARparseur.pcPARtabBalisesValeurs[1][1]);
	pcPARtabBalisesValeurs[2][1] = _strdup(PARparseur.pcPARtabBalisesValeurs[2][1]);
	pcPARtabBalisesValeurs[3][1] = _strdup(PARparseur.pcPARtabBalisesValeurs[3][1]);

	pcPARType = _strdup(PARparseur.pcPARType);

	return *this;
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
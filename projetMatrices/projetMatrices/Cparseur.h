#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "Cmatrice.h"

#define NBRBALISES 4 // nbr de balises
//Nom des balises
#define TYPEMATRICE "TYPEMATRICE"
#define NBLIGNES "NBLIGNES"
#define NBCOLONNES "NBCOLONNES"
#define MATRICE "MATRICE"
//Les différents type détectables
#define DOUBLE "DOUBLE"
#define INTEGER "INT"
#define FLOAT "FLOAT"
#define CHARACTER "CHAR"

/******************************************************************************
class Cparseur
*******************************************************************************

	Cette classe permet de trnasformer les données d'un fichier en données
	brut à l'aide de balises et d'en sortir une matrice

	Attributs
		pcType : Le type de matrice détecté
		pctabBalisesValeurs : Les données brutes relevées du fichier, chaque
			ligne correspond à une balise : la première colonne le nom de la 
			balise et la seconde sa valeur détecté

******************************************************************************/

class Cparseur
{
private :
	char * pcType;
	char * pctabBalisesValeurs[NBRBALISES][2];

public :
	//Constructeurs et destructeurs
	Cparseur();
	Cparseur(Cparseur & PARObjet);
	~Cparseur();

	//Méthodes de lecture/écriture dans un fichier
	void PARLireMatrice(char * pcfilename);
	template<typename MType> void PAREnregistrerMatrice(char * pcfilename, CMatrice<MType> & MTMATMatrice); // Pour une possible extension
	const char * PARgetType();
	//Fonctions pour générer une matrice avec les données brute
	CMatrice<double> * PARcreerDoubleMatrice();
	CMatrice<int> * PARcreerIntMatrice(); //Pour une amélioration possible
	CMatrice<char> * PARcreerCharMatrice(); //Pour une amélioration possible
	CMatrice<float> * PARcreerFloatMatrice(); //Pour une amélioration possible

private :
	//Méthodes utilisé en interne pour la reconnaissance de la matrice
	void PARreconnaitreType(char * pcElm);
	unsigned int PARreconnaitreTaille(char * pcElm);
	char * PARrecupererElement(char * pcElm);
	void PAReffacerElmt(char * pcElmt, char * pcValeur, char * pcSrc); //utilisé pour ne pas bouclé sur les phases repérage balise/récupération de valeurs
};

#endif
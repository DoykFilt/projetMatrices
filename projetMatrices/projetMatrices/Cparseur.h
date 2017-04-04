#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "Cmatrice.h"

#define NBRBALISES 4 // nbr de balises
//Nom des balises
#define TYPEMATRICE "TYPEMATRICE"
#define NBLIGNES "NBLIGNES"
#define NBCOLONNES "NBCOLONNES"
#define MATRICE "MATRICE"
//Les diff�rents type d�tectables
#define DOUBLE "DOUBLE"
#define INTEGER "INT"
#define FLOAT "FLOAT"
#define CHARACTER "CHAR"

/******************************************************************************
class Cparseur
*******************************************************************************

	Cette classe permet de trnasformer les donn�es d'un fichier en donn�es
	brut � l'aide de balises et d'en sortir une matrice

	Attributs
		pcType : Le type de matrice d�tect�
		pctabBalisesValeurs : Les donn�es brutes relev�es du fichier, chaque
			ligne correspond � une balise : la premi�re colonne le nom de la 
			balise et la seconde sa valeur d�tect�

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

	//M�thodes de lecture/�criture dans un fichier
	void PARLireMatrice(char * pcfilename);
	template<typename MType> void PAREnregistrerMatrice(char * pcfilename, CMatrice<MType> & MTMATMatrice); // Pour une possible extension
	const char * PARgetType();
	//Fonctions pour g�n�rer une matrice avec les donn�es brute
	CMatrice<double> * PARcreerDoubleMatrice();
	CMatrice<int> * PARcreerIntMatrice(); //Pour une am�lioration possible
	CMatrice<char> * PARcreerCharMatrice(); //Pour une am�lioration possible
	CMatrice<float> * PARcreerFloatMatrice(); //Pour une am�lioration possible

private :
	//M�thodes utilis� en interne pour la reconnaissance de la matrice
	void PARreconnaitreType(char * pcElm);
	unsigned int PARreconnaitreTaille(char * pcElm);
	char * PARrecupererElement(char * pcElm);
	void PAReffacerElmt(char * pcElmt, char * pcValeur, char * pcSrc); //utilis� pour ne pas boucl� sur les phases rep�rage balise/r�cup�ration de valeurs
};

#endif
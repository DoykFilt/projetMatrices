#ifndef CPARSEUR_H
#define CPARSEUR_H

#include "CMatrice.h"

#define NBRBALISES 4
#define TYPEMATRICE "TYPEMATRICE"
#define NBLIGNES "NBLIGNES"
#define NBCOLONNES "NBCOLONNES"
#define MATRICE "MATRICE"
#define DOUBLE "DOUBLE"
#define INTEGER "INT"
#define FLOAT "FLOAT"
#define CHARACTER "CHAR"

class Cparseur
{
private :
	char * pcType;
	char * pctabBalisesValeurs[NBRBALISES][2];

public :
	//Constructeurs
	Cparseur();
	Cparseur(Cparseur & PARObjet);
	~Cparseur();
	//Méthodes de lecture/écriture dans un fichier
	void PARLireMatrice(char * pcfilename);
	template<typename MType> void PAREnregistrerMatrice(char * pcfilename, CMatrice<MType> & MTMATMatrice); // Pour une possible extension
	
	const char * PARgetType();

	CMatrice<double> * PARcreerDoubleMatrice();
	CMatrice<int> * PARcreerIntMatrice();
	CMatrice<char> * PARcreerCharMatrice();
	CMatrice<float> * PARcreerFloatMatrice();

private :
	//Méthodes utilisé en interne pour la reconnaissance de la matrice
	void PARreconnaitreType(char * pcElm);
	unsigned int PARreconnaitreTaille(char * pcElm);
	char * PARrecupererElement(char * pcElm);
	void PAReffacerElmt(char * pcElmt, char * pcValeur, char * pcSrc);
};

#endif
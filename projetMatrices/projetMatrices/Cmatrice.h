#ifndef CMATRICE_H
#define CMATRICE_H

/******************************************************************************
class CMatrice<class MType>
*******************************************************************************

	Ce Canvas de classe permet de g�n�r� une matrice de type g�n�rique et de
	faire des manipulations sur en entre matrices.

	Attributs
		uiMATnbLignes : Le nombre de lignes de la matrice
		uiMATnbColonnes : Le nombre de colonne de la matrice
		ppMTMATMatrice : La matrice

******************************************************************************/

template <class MType> class CMatrice
{
private :
	//Attributs
	unsigned int uiMATnbLignes;
	unsigned int uiMATnbColonnes;
	MType ** ppMTMATMatrice;

public :
	//Constructeurs-Destructeurs
	CMatrice();
	CMatrice(const CMatrice<MType> & MTMATMatrice);
	CMatrice(MType ** & ppMTMatrice, unsigned int uiLignes, unsigned int uiColonnes);
	CMatrice(unsigned int uiLignes, unsigned int uiColonnes); // Cr�er une matrice vide de taille uiLignes*uiColonnes
	~CMatrice();

	//Methodes
	CMatrice<MType> & MTMATTransposeeMatrice() const;
	void MTMATAfficherMatrice() const;

	//Accesseurs
	unsigned int MTMATgetNbLignes() const;
	unsigned int MTMATgetNbColonnes() const;
	MType MTMATget(unsigned int uiLigne, unsigned int uiColonne) const;
	void MTMATset(unsigned int uiLigne, unsigned int uiColonne, MType MTValeur);
	void MTMATsetMatrice(const MType ** ppMTMatrice, const unsigned int uiLignes, const unsigned int uiColonnes);

	//Surcharges d'operateurs
	CMatrice<MType> & operator=(CMatrice<MType> const & MTMATMatrice);
};

//Fichiers .cpp � garder hors de la g�n�ration du projet pour son bon fonctionnement
#include "Cmatrice.cpp"; //Le corps de la classe g�n�rique CMatrice<MType>
#include "SurchargesOperateurs.cpp"; //Toutes les surcharges li�es � la classe g�n�rique CMatrice<MType>

#endif
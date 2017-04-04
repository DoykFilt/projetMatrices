#ifndef CMATRICE_H
#define CMATRICE_H

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
	CMatrice(unsigned int uiLignes, unsigned int uiColonnes); // Créer une matrice vide de taille uiLignes*uiColonnes
	~CMatrice();

	//Methodes
	CMatrice<MType> & MTMATTransposeeMatrice() const;
	void MTMATAfficherMatrice() const;

	//Accesseurs
	unsigned int MTMATgetNbLignes() const;
	unsigned int MTMATgetNbColonnes() const;
	MType MTMATget(unsigned int uiLigne, unsigned int uiColonne);
	MType MTMATset(unsigned int uiLigne, unsigned int uiColonne, MType MTValeur);
	void MTMATsetMatrice(const MType ** MTMATMatrice, const unsigned int uiLignes, const unsigned int uiColonnes);

	//Surcharges d'operateurs
	CMatrice<MType> & operator=(CMatrice<MType> const & MTMATMatrice);
};

#include "CMAtrice.cpp";

#endif
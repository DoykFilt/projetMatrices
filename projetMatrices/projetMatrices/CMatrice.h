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
	//Constructeurs-Desctructeurs
	CMatrice();
	CMatrice(const CMatrice<MType> & MTMATMatrice);
	CMatrice(MType ** & ppMTMatrice, unsigned int uiLignes, unsigned int uiColonnes);
	CMatrice(unsigned int uiLignes, unsigned int uiColonnes); // Créer une matrice vide de taille uiLignes*uiColonnes

	~CMatrice();

	//Methodes
	CMatrice<MType> & MTMATTransposeeMatrice() const;
	void MATAfficherMatrice() const;

	//Accesseurs
	unsigned int MATgetNbLignes() const;
	unsigned int MATgetNbColonnes() const;
	void MATsetMatrice(const MType ** MTMATMatrice, const unsigned int uiLignes, const unsigned int uiColonnes);

	//Operateurs
	CMatrice<MType> & operator*(MType MTValeur);
	CMatrice<MType> & operator*(CMatrice<MType> const & MTMATMatrice);
	CMatrice<MType> & operator/(MType MTValeur);
	CMatrice<MType> & operator+(CMatrice<MType> const & MTMATMatrice);
	CMatrice<MType> & operator-(CMatrice<MType> const & MTMATMatrice);
	CMatrice<MType> & operator=(CMatrice<MType> const & MTMATMatrice);
};

#include "CMAtrice.cpp";

#endif
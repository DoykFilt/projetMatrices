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
	CMatrice(CMatrice<MType> MTMATMatrice);
	CMatrice(MType ** & ppMTMatrice, unsigned int uiLignes, unsigned int uiColonnes);

	~CMatrice();

	//Methodes
	CMatrice<MType> MTMATTransposeeMatrice() const;
	void MATAfficherMatrice() const;

	//Accesseurs
	unsigned int MATgetNbLignes() const;
	unsigned int MATgetNbColonnes() const;
	MType ** & MATgetMatrice() const;
	void MATsetMatrice(MType ** & MTMATMatrice, unsigned int uiLignes, unsigned int uiColonnes);

	//Operateurs
	CMatrice<MType> & operator*(MType MTValeur);
	CMatrice<MType> & MType::operator*(MTMATMatrice);
	CMatrice<MType> & operator*(CMatrice<MType> MTMATMatrice);
	CMatrice<MType> & operator/(MType MTValeur);
	CMatrice<MType> & operator+(CMatrice<MType> MTMATMatrice);
	CMatrice<MType> & operator-(CMatrice<MType> MTMATMatrice);
};

#include "CMAtrice.cpp";

#endif
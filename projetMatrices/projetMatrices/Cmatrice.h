#ifndef Cmatrice_H
#define Cmatrice_H

/******************************************************************************
class Cmatrice<class MType>
*******************************************************************************

	Ce Canvas de classe permet de g�n�r� une matrice de type g�n�rique et de
	faire des manipulations sur en entre matrices.

	Attributs
		uiMATnbLignes : Le nombre de lignes de la matrice
		uiMATnbColonnes : Le nombre de colonne de la matrice
		ppMTMATMatrice : La matrice

******************************************************************************/

template <class MType> class Cmatrice
{
private :
	//Attributs
	unsigned int uiMATnbLignes;
	unsigned int uiMATnbColonnes;
	MType ** ppMTMATMatrice;

public :
	//########## Constructeurs et destructeurs ##########//
	/******************************************************************************
	Constructeur par d�faut
	*******************************************************************************
		Entr�e : Rien
		Necessit� : N�ant
		Sortie : Rien
		Entraine : L'objet en cours est initialis�.
	******************************************************************************/
	Cmatrice();
	/******************************************************************************
	Constructeur de recopie
	*******************************************************************************
		Entr�e : Objet de la m�me classe
		Necessit� : N�ant
		Sortie : Rien
		Entraine : L'objet en cours est initialis� par recopie
	******************************************************************************/
	Cmatrice(const Cmatrice<MType> & MTMATMatrice);
	/******************************************************************************
	Constructeur de confort 1
	*******************************************************************************
		Entr�e : une matrice de type MType, uiLignes et uiColonnes deux naturels
		Necessit� : la matrice est de taille uiLignes * uiColonnes
		Sortie : Rien
		Entraine : L'objet en cours est initialis�.
	******************************************************************************/
	Cmatrice(MType ** & ppMTMatrice, unsigned int uiLignes, unsigned int uiColonnes);
	/******************************************************************************
	Constructeur de confort 2
	*******************************************************************************
		Entr�e : uiLignes et uiColonnes deux naturels
		Necessit� : N�ant
		Sortie : Rien
		Entraine : L'objet en cours est initialis�, sa matrice est de taille uiLignes * uiColonnes remplir de 0;
	******************************************************************************/
	Cmatrice(unsigned int uiLignes, unsigned int uiColonnes);
	/******************************************************************************
	Destructeur
	*******************************************************************************
		Entr�e : Rien
		Necessit� : N�ant
		Sortie : Rien
		Entraine : L'objet en cours d�sallou�
	******************************************************************************/
	~Cmatrice();

	//########## M�thodes ##########//


	/*************************************************************************************************************************************/
	CMatrice<MType> & MTMATEchelonnageMatrice()const;
	unsigned int MTMATCalculRang();
	/*************************************************************************************************************************************/


	/******************************************************************************
	MATAfficherMatrice
	*******************************************************************************
		Entr�e : Rien
		Necessit� : N�ant
		Sortie : Rien
		Entraine : Affiche la matrice
	******************************************************************************/
	void MTMATAfficherMatrice() const;
	/******************************************************************************
	MTMATgetNbLignes
	*******************************************************************************
		Entr�e : Rien
		Necessit� : N�ant
		Sortie : naturel
		Entraine : Retourne le nombre de lignes de la matrice
	******************************************************************************/
	unsigned int MTMATgetNbLignes() const;
	/******************************************************************************
	MTMATgetNbColonnes
	*******************************************************************************
		Entr�e : Rien
		Necessit� : N�ant
		Sortie : naturel
		Entraine : Retourne le nombre de colonnes de la matrice
	******************************************************************************/
	unsigned int MTMATgetNbColonnes() const;
	/******************************************************************************
	MTMATget
	*******************************************************************************
		Entr�e : uiLigne, uiColonnes deux naturel
		Necessit� : uiLigne et uiColonne ne sont pas plus grand que les dimensions de la matrice
		Sortie : MType
		Entraine : Retourne l'�l�ment de la matrice � la ligne uiLigne et � la colonne uiColonne
	******************************************************************************/
	MType MTMATget(unsigned int uiLigne, unsigned int uiColonne) const;
	/******************************************************************************
	MTMATset
	*******************************************************************************
		Entr�e : uiLigne, uiColonnes deux naturel, MTValeur la valeur � stocker
		Necessit� : uiLigne et uiColonne ne sont pas plus grand que les dimensions de la matrice
		Sortie : Rien
		Entraine : L'�l�ment � la position uiLigne, uiColonnes a �t� remplac�
	******************************************************************************/
	void MTMATset(unsigned int uiLigne, unsigned int uiColonne, MType MTValeur);
	/******************************************************************************
	MTMATsetMatrice
	*******************************************************************************
		Entr�e : uiLigne, uiColonnes deux naturel, ppMTMatrice une matrice de type MType
		Necessit� : ppMTMatrice est de taille uiLignes * uiColonne
		Sortie : Rien
		Entraine : Les attributs de l'objet ont �t� remplac�s
	******************************************************************************/
	void MTMATsetMatrice(const MType ** ppMTMatrice, const unsigned int uiLignes, const unsigned int uiColonnes);

	//########## Surcharges d'op�rateurs ##########//
	/******************************************************************************
	surcharge de l'op�rateur d'affectation
	*******************************************************************************
		Entr�e : un objet du m�me type
		Necessit� : N�ant
		Sortie : Une r�f�rence sur l'objet en cours qui a �t� modifi�
		Entraine : L'objet en cours est une copie de l'objet en param�tre
	******************************************************************************/
	Cmatrice<MType> & operator=(Cmatrice<MType> const & MTMATMatrice);
};

//Fichiers .cpp � garder hors de la g�n�ration du projet pour son bon fonctionnement
#include "Cmatrice.cpp"; //Le corps de la classe g�n�rique Cmatrice<MType>
#include "SurchargesOperateurs.cpp"; //Toutes les surcharges li�es � la classe g�n�rique Cmatrice<MType>

#endif
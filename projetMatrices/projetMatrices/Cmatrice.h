#ifndef Cmatrice_H
#define Cmatrice_H

/******************************************************************************
class Cmatrice<class MType>
*******************************************************************************

	Ce Canvas de classe permet de généré une matrice de type générique et de
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
	Constructeur par défaut
	*******************************************************************************
		Entrée : Rien
		Necessité : Néant
		Sortie : Rien
		Entraine : L'objet en cours est initialisé.
	******************************************************************************/
	Cmatrice();
	/******************************************************************************
	Constructeur de recopie
	*******************************************************************************
		Entrée : Objet de la même classe
		Necessité : Néant
		Sortie : Rien
		Entraine : L'objet en cours est initialisé par recopie
	******************************************************************************/
	Cmatrice(const Cmatrice<MType> & MTMATMatrice);
	/******************************************************************************
	Constructeur de confort 1
	*******************************************************************************
		Entrée : une matrice de type MType, uiLignes et uiColonnes deux naturels
		Necessité : la matrice est de taille uiLignes * uiColonnes
		Sortie : Rien
		Entraine : L'objet en cours est initialisé.
	******************************************************************************/
	Cmatrice(MType ** & ppMTMatrice, unsigned int uiLignes, unsigned int uiColonnes);
	/******************************************************************************
	Constructeur de confort 2
	*******************************************************************************
		Entrée : uiLignes et uiColonnes deux naturels
		Necessité : Néant
		Sortie : Rien
		Entraine : L'objet en cours est initialisé, sa matrice est de taille uiLignes * uiColonnes remplir de 0;
	******************************************************************************/
	Cmatrice(unsigned int uiLignes, unsigned int uiColonnes);
	/******************************************************************************
	Destructeur
	*******************************************************************************
		Entrée : Rien
		Necessité : Néant
		Sortie : Rien
		Entraine : L'objet en cours désalloué
	******************************************************************************/
	~Cmatrice();

	//########## Méthodes ##########//


	/*************************************************************************************************************************************/
	CMatrice<MType> & MTMATEchelonnageMatrice()const;
	unsigned int MTMATCalculRang();
	/*************************************************************************************************************************************/


	/******************************************************************************
	MATAfficherMatrice
	*******************************************************************************
		Entrée : Rien
		Necessité : Néant
		Sortie : Rien
		Entraine : Affiche la matrice
	******************************************************************************/
	void MTMATAfficherMatrice() const;
	/******************************************************************************
	MTMATgetNbLignes
	*******************************************************************************
		Entrée : Rien
		Necessité : Néant
		Sortie : naturel
		Entraine : Retourne le nombre de lignes de la matrice
	******************************************************************************/
	unsigned int MTMATgetNbLignes() const;
	/******************************************************************************
	MTMATgetNbColonnes
	*******************************************************************************
		Entrée : Rien
		Necessité : Néant
		Sortie : naturel
		Entraine : Retourne le nombre de colonnes de la matrice
	******************************************************************************/
	unsigned int MTMATgetNbColonnes() const;
	/******************************************************************************
	MTMATget
	*******************************************************************************
		Entrée : uiLigne, uiColonnes deux naturel
		Necessité : uiLigne et uiColonne ne sont pas plus grand que les dimensions de la matrice
		Sortie : MType
		Entraine : Retourne l'élément de la matrice à la ligne uiLigne et à la colonne uiColonne
	******************************************************************************/
	MType MTMATget(unsigned int uiLigne, unsigned int uiColonne) const;
	/******************************************************************************
	MTMATset
	*******************************************************************************
		Entrée : uiLigne, uiColonnes deux naturel, MTValeur la valeur à stocker
		Necessité : uiLigne et uiColonne ne sont pas plus grand que les dimensions de la matrice
		Sortie : Rien
		Entraine : L'élément à la position uiLigne, uiColonnes a été remplacé
	******************************************************************************/
	void MTMATset(unsigned int uiLigne, unsigned int uiColonne, MType MTValeur);
	/******************************************************************************
	MTMATsetMatrice
	*******************************************************************************
		Entrée : uiLigne, uiColonnes deux naturel, ppMTMatrice une matrice de type MType
		Necessité : ppMTMatrice est de taille uiLignes * uiColonne
		Sortie : Rien
		Entraine : Les attributs de l'objet ont été remplacés
	******************************************************************************/
	void MTMATsetMatrice(const MType ** ppMTMatrice, const unsigned int uiLignes, const unsigned int uiColonnes);

	//########## Surcharges d'opérateurs ##########//
	/******************************************************************************
	surcharge de l'opérateur d'affectation
	*******************************************************************************
		Entrée : un objet du même type
		Necessité : Néant
		Sortie : Une référence sur l'objet en cours qui a été modifié
		Entraine : L'objet en cours est une copie de l'objet en paramètre
	******************************************************************************/
	Cmatrice<MType> & operator=(Cmatrice<MType> const & MTMATMatrice);
};

//Fichiers .cpp à garder hors de la génération du projet pour son bon fonctionnement
#include "Cmatrice.cpp"; //Le corps de la classe générique Cmatrice<MType>
#include "SurchargesOperateurs.cpp"; //Toutes les surcharges liées à la classe générique Cmatrice<MType>

#endif
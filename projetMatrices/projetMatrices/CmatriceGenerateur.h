#ifndef CmatriceGENERATEUR_H
#define CmatriceGENERATEUR_H

#include "Cparseur.h"
#include "Cmatrice.h"

/******************************************************************************
class CmatriceGenerateur
*******************************************************************************

	Cette classe permet de cr�er une Cmatrice de type Double � partir des donn�es brutes du parseur

	Attributs
		pPARGRGparseur : le parseur o� sont contenues les donn�es brutes

******************************************************************************/
class CmatriceGenerateur
{
private :
	Cparseur * pPARMGRparseur;

public :
	//########## Constructeurs - Desctructeur ##########//
	/******************************************************************************
	Constructeur
	*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet a �t� initialis�
	******************************************************************************/
	CmatriceGenerateur();
	/******************************************************************************
	Constructeur avec un argument
	*******************************************************************************
	Entr�e : un pointeur sur un objet de type Cparseur
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet a �t� initialis�
	******************************************************************************/
	CmatriceGenerateur(Cparseur * pPARparseur);
	/******************************************************************************
	Constructeur de recopie
	*******************************************************************************
	Entr�e : R�f�rence sur un objet de type CgraphGenerateur
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet a �t� initialis� par recopie de l'objet en param�tre
	******************************************************************************/
	CmatriceGenerateur(CmatriceGenerateur & MGRObjet);
	/******************************************************************************
	Destructeur
	*******************************************************************************
	Entr�e : Rien
	Necessit� : L'arbre a �t� d�sallou�
	Sortie : Rien
	Entraine : L'espace allou� pour les attributs de l'objet a �t� lib�r�
	******************************************************************************/
	~CmatriceGenerateur();
	/******************************************************************************
	GRGgenererMatrice
	*******************************************************************************
	Entr�e : Rien
	Necessit� : Le parseur a r�cup�r� les donn�es brutes pr�alablement
	Sortie : l'objet reconnu de type Cmatrice<double> 
	Entraine : un objet de type Cmatrice<double> a �t� allou� et retourn�
	******************************************************************************/
	Cmatrice<double> * MGRgenererMatrice();
	/******************************************************************************
	GRGsetParseur
	*******************************************************************************
	Entr�e : Un pointeur sur un objet de type Cparseur
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'ancien parseur a �t� remplac� par le nouveau
	******************************************************************************/
	void MGRsetParseur(Cparseur * pPARparseur);
	/******************************************************************************
	GRGgetParseur
	*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : Un poiteur sur le parseur
	Entraine : Le pointeur a �t� retourn�
	******************************************************************************/
	Cparseur * MGRgetParseur();
	/******************************************************************************
	GRGreconnaitreEntier
	*******************************************************************************
	Entr�e : une chaine de caract�re contenant l'entier � reconnaitre
	Necessit� : La chaine est convertible en entier
	Sortie : L'entier reconnu
	Entraine : L'entier a �t� reconnu et renvoy�
	******************************************************************************/
	unsigned int MGRreconnaitreEntier(char * pcElm);

	//########## Surcharge d'operateur ##########//
	/******************************************************************************
	surcharge de l'op�rateur d'affectation
	*******************************************************************************
	Entr�e : un objet du m�me type
	Necessit� : N�ant
	Sortie : Une r�f�rence sur l'objet en cours qui a �t� modifi�
	Entraine : L'objet en cours est une copie de l'objet en param�tre
	******************************************************************************/
	CmatriceGenerateur & operator=(CmatriceGenerateur const & MGRObjet);
};

#endif
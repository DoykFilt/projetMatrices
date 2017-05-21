#ifndef CmatriceGENERATEUR_H
#define CmatriceGENERATEUR_H

#include "Cparseur.h"
#include "Cmatrice.h"

/******************************************************************************
class CmatriceGenerateur
*******************************************************************************

	Cette classe permet de créer une Cmatrice de type Double à partir des données brutes du parseur

	Attributs
		pPARGRGparseur : le parseur où sont contenues les données brutes

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
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet a été initialisé
	******************************************************************************/
	CmatriceGenerateur();
	/******************************************************************************
	Constructeur avec un argument
	*******************************************************************************
	Entrée : un pointeur sur un objet de type Cparseur
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet a été initialisé
	******************************************************************************/
	CmatriceGenerateur(Cparseur * pPARparseur);
	/******************************************************************************
	Constructeur de recopie
	*******************************************************************************
	Entrée : Référence sur un objet de type CgraphGenerateur
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet a été initialisé par recopie de l'objet en paramètre
	******************************************************************************/
	CmatriceGenerateur(CmatriceGenerateur & MGRObjet);
	/******************************************************************************
	Destructeur
	*******************************************************************************
	Entrée : Rien
	Necessité : L'arbre a été désalloué
	Sortie : Rien
	Entraine : L'espace alloué pour les attributs de l'objet a été libéré
	******************************************************************************/
	~CmatriceGenerateur();
	/******************************************************************************
	GRGgenererMatrice
	*******************************************************************************
	Entrée : Rien
	Necessité : Le parseur a récupéré les données brutes préalablement
	Sortie : l'objet reconnu de type Cmatrice<double> 
	Entraine : un objet de type Cmatrice<double> a été alloué et retourné
	******************************************************************************/
	Cmatrice<double> * MGRgenererMatrice();
	/******************************************************************************
	GRGsetParseur
	*******************************************************************************
	Entrée : Un pointeur sur un objet de type Cparseur
	Necessité : Néant
	Sortie : Rien
	Entraine : L'ancien parseur a été remplacé par le nouveau
	******************************************************************************/
	void MGRsetParseur(Cparseur * pPARparseur);
	/******************************************************************************
	GRGgetParseur
	*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Un poiteur sur le parseur
	Entraine : Le pointeur a été retourné
	******************************************************************************/
	Cparseur * MGRgetParseur();
	/******************************************************************************
	GRGreconnaitreEntier
	*******************************************************************************
	Entrée : une chaine de caractère contenant l'entier à reconnaitre
	Necessité : La chaine est convertible en entier
	Sortie : L'entier reconnu
	Entraine : L'entier a été reconnu et renvoyé
	******************************************************************************/
	unsigned int MGRreconnaitreEntier(char * pcElm);

	//########## Surcharge d'operateur ##########//
	/******************************************************************************
	surcharge de l'opérateur d'affectation
	*******************************************************************************
	Entrée : un objet du même type
	Necessité : Néant
	Sortie : Une référence sur l'objet en cours qui a été modifié
	Entraine : L'objet en cours est une copie de l'objet en paramètre
	******************************************************************************/
	CmatriceGenerateur & operator=(CmatriceGenerateur const & MGRObjet);
};

#endif
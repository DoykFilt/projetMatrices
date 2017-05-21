#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include <string.h>
#include <stdlib.h>
using namespace std;

#define ERREUR_DEFAUT 0
#define MESSAGE_DEFAUT "Erreur non definie"
#define MESSAGE_SUPP_DEFAUT ""
#define ERREUR_ALLOCATION 1
#define MESSAGE_ALLOCATION "Echec de l'allocation"
#define ERREUR_REALLOCATION 2
#define MESSAGE_REALLOCATION "Echec de la reallocation"
#define ERREUR_CALCUL 3
#define MESSAGE_CALCUL "Calculs imcompatibles"
#define ERREUR_PARAM 4
#define MESSAGE_PARAM "Parametres inappriopries"
#define ERREUR_FICHIER 5
#define MESSAGE_FICHIER "Echec de l'ouverture du fichier"
#define ERREUR_PARSEUR 6
#define MESSAGE_PARSEUR "Echec lors du parsage"
#define ERREUR_PRECONDITIONS 7
#define MESSAGE_PRECONDITIONS "Impossible d'utiliser la methode/fonction"

/******************************************************************************
class Cexception
*******************************************************************************

	Cette classe permet de conte nir les informations n�cessaire � la 
	compr�hension d'erreurs lev�es

	Attributs
		uiEXCValeur : la valeur associ�e � l'erreur
		pcEXCMessage : le message automatiquement associ� suivant la valeur
		pcEXCMessageDetail : un message compl�mentaire optionnel

******************************************************************************/
class Cexception
{
private :
	//###############################//
	//########## Attributs ##########//
	//###############################//
	unsigned int uiEXCValeur;
	char * pcEXCMessage;
	char * pcEXCMessageDetail;

public :

	//###################################################//
	//########## Constructeurs et destructeurs ##########//
	//###################################################//
	/******************************************************************************
	Constructeur par d�faut
	*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet en cours est initialis�.
	******************************************************************************/
	Cexception(); 
	/******************************************************************************
	Constructeur de recopie
	*******************************************************************************
	Entr�e : Un objet de la classe.
	Necessit� : N�ant
	Sortie :Rien
	Entraine : Cr�ation d'un objet par recopie.
	******************************************************************************/
	Cexception(const Cexception & EXCObjet);
	/******************************************************************************
	Constructeur � 2 arguments
	*******************************************************************************
	Entr�e : La valeur et le message associ�.
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet en cours est initialis� avec un message d�taill� de l'erreur.
	******************************************************************************/
	Cexception(unsigned int uiValeur, char * pcMessageDetail=MESSAGE_SUPP_DEFAUT); 
	/******************************************************************************
	Destructeur par d�faut
	*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'espace allou� par l'objet a �t� lib�r�
	******************************************************************************/
	~Cexception();

	//##############################//
	//########## Methodes ##########//
	//##############################//
	/******************************************************************************
	M�thode de lecture de la valeur
	*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : Valeur
	Entraine : Retourne la valeur.
	******************************************************************************/
	unsigned int EXCLire_Valeur() const;
	/******************************************************************************
	M�hode de modification de la valeur
	*******************************************************************************
	Entr�e : Valeur
	Necessit� : Valeur existante.
	Sortie : N�ant
	Entraine : Modification de la valeur et du message associ�.
	******************************************************************************/
	void EXCModifier_Valeur(unsigned int uiValeur, bool reinitSuppMessage=false);
	/******************************************************************************
	M�thode de lecture du message
	*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : char * le message
	Entraine : Retourne le message entier (concat�nation entre celui par d�faut et l'optionnel)
	******************************************************************************/
	char * EXCLire_Message() const;
	/******************************************************************************
	M�hode de modification du message
	*******************************************************************************
	Entr�e : Char * Message
	Necessit� : N�ant
	Sortie : Rien
	Entraine : Modification du message.
	******************************************************************************/
	void EXCModifier_Message(char * pcMessage);

	//#############################################//
	//########## Surcharges d'op�rateurs ##########//
	//#############################################//
	/******************************************************************************
	Surcharge de l'op�rateur d'affectation
	*******************************************************************************
	Entr�e : r�f�rence sur un objet de type Cexception
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet a �t� affect� par recopie de l'objet en param�tre
	******************************************************************************/
	Cexception & operator=(Cexception const & EXCexception);
};

#endif
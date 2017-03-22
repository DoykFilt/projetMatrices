#include "Cexception.h"

/******************************************************************************
Constructeur par défaut
*******************************************************************************
	Entrée : Rien
	Necessité : Néant
	Sortie : Rien
	Entraine : L'objet en cours est initialisé.
******************************************************************************/
Cexception::Cexception()
{
	uiEXCValeur = ERREUR_DEFAUT;
	pcEXCMessage = MESSAGE_DEFAUT;
	pcEXCMessageDetail = MESSAGE_SUPP_DEFAUT;
}

/******************************************************************************
Constructeur à 1 argument
*******************************************************************************
Entrée : La valeur et le message associé.
Necessité : Néant
Sortie : Rien
Entraine : L'objet en cours est initialisé.
******************************************************************************/
Cexception::Cexception(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
	switch(uiEXCValeur)
	{
		case 1 : pcEXCMessage = MESSAGE_ALLOCATION;
			break;
		case 2 : pcEXCMessage = MESSAGE_REALLOCATION;
			break;
		case 3 : pcEXCMessage = MESSAGE_TAILLE_MATRICE;
			break;
		default : pcEXCMessage = MESSAGE_DEFAUT;
	}
	pcEXCMessageDetail = MESSAGE_SUPP_DEFAUT;
}

/******************************************************************************
Constructeur de recopie
*******************************************************************************
Entrée : Un objet de la classe.
Necessité : Néant
Sortie :Rien
Entraine : Création d'un objet par recopie.
******************************************************************************/
Cexception::Cexception(const Cexception & EXCObjet)
{
	uiEXCValeur = EXCObjet.uiEXCValeur;
	pcEXCMessage =EXCObjet.pcEXCMessage;
	pcEXCMessageDetail =EXCObjet.pcEXCMessageDetail;
}

/******************************************************************************
Destructeur par défaut
*******************************************************************************
Entrée : Rien
Necessité : Néant
Sortie : Rien
Entraine : Néant
******************************************************************************/
Cexception::~Cexception()
{}

/******************************************************************************
Méthode de lecture de la valeur
*******************************************************************************
Entrée : Rien
Necessité : Néant
Sortie : Valeur
Entraine : Retourne la valeur.
******************************************************************************/
inline unsigned int Cexception::EXCLire_Valeur() const
{
	return uiEXCValeur;
}

/******************************************************************************
Méhode de modification de la valeur
*******************************************************************************
Entrée : Valeur
Necessité : Valeur existante.
Sortie : Néant
Entraine : Modification de la valeur.
******************************************************************************/
inline void Cexception::EXCModifier_Valeur(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
	switch(uiEXCValeur)
	{
		case 1 : pcEXCMessage = MESSAGE_ALLOCATION;
			break;
		case 2 : pcEXCMessage = MESSAGE_REALLOCATION;
			break;
		case 3 : pcEXCMessage = MESSAGE_TAILLE_MATRICE;
			break;
		default : pcEXCMessage = MESSAGE_DEFAUT;
	}
}

/******************************************************************************
Méthode de lecture de la valeur
*******************************************************************************
Entrée : Rien
Necessité : Néant
Sortie : Valeur
Entraine : Retourne la valeur.
******************************************************************************/
inline char * Cexception::EXCLire_Message() const
{
	return pcEXCMessage; // concaténation du message supp
}

/******************************************************************************
Méhode de modification du message
*******************************************************************************
Entrée : Message
Necessité : Néant
Sortie : Rien
Entraine : Modification du message.
******************************************************************************/
inline void Cexception::EXCModifier_Message(char * pcMessage)
{
	pcEXCMessageDetail = pcMessage;
}

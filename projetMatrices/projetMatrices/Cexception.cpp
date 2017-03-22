#include "Cexception.h"

/******************************************************************************
Constructeur par d�faut
*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet en cours est initialis�.
******************************************************************************/
Cexception::Cexception()
{
	uiEXCValeur = ERREUR_DEFAUT;
	pcEXCMessage = MESSAGE_DEFAUT;
	pcEXCMessageDetail = MESSAGE_SUPP_DEFAUT;
}

/******************************************************************************
Constructeur � 1 argument
*******************************************************************************
Entr�e : La valeur et le message associ�.
Necessit� : N�ant
Sortie : Rien
Entraine : L'objet en cours est initialis�.
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
Entr�e : Un objet de la classe.
Necessit� : N�ant
Sortie :Rien
Entraine : Cr�ation d'un objet par recopie.
******************************************************************************/
Cexception::Cexception(const Cexception & EXCObjet)
{
	uiEXCValeur = EXCObjet.uiEXCValeur;
	pcEXCMessage =EXCObjet.pcEXCMessage;
	pcEXCMessageDetail =EXCObjet.pcEXCMessageDetail;
}

/******************************************************************************
Destructeur par d�faut
*******************************************************************************
Entr�e : Rien
Necessit� : N�ant
Sortie : Rien
Entraine : N�ant
******************************************************************************/
Cexception::~Cexception()
{}

/******************************************************************************
M�thode de lecture de la valeur
*******************************************************************************
Entr�e : Rien
Necessit� : N�ant
Sortie : Valeur
Entraine : Retourne la valeur.
******************************************************************************/
inline unsigned int Cexception::EXCLire_Valeur() const
{
	return uiEXCValeur;
}

/******************************************************************************
M�hode de modification de la valeur
*******************************************************************************
Entr�e : Valeur
Necessit� : Valeur existante.
Sortie : N�ant
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
M�thode de lecture de la valeur
*******************************************************************************
Entr�e : Rien
Necessit� : N�ant
Sortie : Valeur
Entraine : Retourne la valeur.
******************************************************************************/
inline char * Cexception::EXCLire_Message() const
{
	return pcEXCMessage; // concat�nation du message supp
}

/******************************************************************************
M�hode de modification du message
*******************************************************************************
Entr�e : Message
Necessit� : N�ant
Sortie : Rien
Entraine : Modification du message.
******************************************************************************/
inline void Cexception::EXCModifier_Message(char * pcMessage)
{
	pcEXCMessageDetail = pcMessage;
}

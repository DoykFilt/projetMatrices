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
	sEXCMessage = MESSAGE_DEFAUT;
}

/******************************************************************************
Constructeur � 2 arguments
*******************************************************************************
Entr�e : La valeur et le message associ�.
Necessit� : N�ant
Sortie : Rien
Entraine : L'objet en cours est initialis�.
******************************************************************************/
Cexception::Cexception(unsigned int uiValeur, string sMessage)
{
	uiEXCValeur = uiValeur;
	sEXCMessage = sMessage;
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
	sEXCMessage =EXCObjet.sEXCMessage;
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
}

/******************************************************************************
M�thode de lecture de la valeur
*******************************************************************************
Entr�e : Rien
Necessit� : N�ant
Sortie : Valeur
Entraine : Retourne la valeur.
******************************************************************************/
inline string Cexception::EXCLire_Message() const
{
	return sEXCMessage;
}

/******************************************************************************
M�hode de modification du message
*******************************************************************************
Entr�e : Message
Necessit� : N�ant
Sortie : Rien
Entraine : Modification du message.
******************************************************************************/
inline void Cexception::EXCModifier_Message(string sMessage)
{
	sEXCMessage = sMessage;
}

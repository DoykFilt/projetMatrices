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
	sEXCMessage = MESSAGE_DEFAUT;
}

/******************************************************************************
Constructeur à 2 arguments
*******************************************************************************
Entrée : La valeur et le message associé.
Necessité : Néant
Sortie : Rien
Entraine : L'objet en cours est initialisé.
******************************************************************************/
Cexception::Cexception(unsigned int uiValeur, string sMessage)
{
	uiEXCValeur = uiValeur;
	sEXCMessage = sMessage;
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
	sEXCMessage =EXCObjet.sEXCMessage;
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
}

/******************************************************************************
Méthode de lecture de la valeur
*******************************************************************************
Entrée : Rien
Necessité : Néant
Sortie : Valeur
Entraine : Retourne la valeur.
******************************************************************************/
inline string Cexception::EXCLire_Message() const
{
	return sEXCMessage;
}

/******************************************************************************
Méhode de modification du message
*******************************************************************************
Entrée : Message
Necessité : Néant
Sortie : Rien
Entraine : Modification du message.
******************************************************************************/
inline void Cexception::EXCModifier_Message(string sMessage)
{
	sEXCMessage = sMessage;
}

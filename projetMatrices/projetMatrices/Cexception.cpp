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
	pcEXCMessage = _strdup(MESSAGE_DEFAUT);
	pcEXCMessageDetail = _strdup(MESSAGE_SUPP_DEFAUT);
}

/******************************************************************************
Constructeur � 2 arguments
*******************************************************************************
Entr�e : La valeur et le message associ�.
Necessit� : N�ant
Sortie : Rien
Entraine : L'objet en cours est initialis� avec un message d�taill� de l'erreur.
******************************************************************************/
Cexception::Cexception(unsigned int uiValeur, char * pcMessageDetail)
{
	uiEXCValeur = uiValeur;
	switch(uiEXCValeur)
	{
	case 1 :pcEXCMessage = _strdup(MESSAGE_ALLOCATION);
			break;
	case 2 : pcEXCMessage = _strdup(MESSAGE_REALLOCATION);
			break;
	case 3 : pcEXCMessage = _strdup(MESSAGE_TAILLE_MATRICE);
			break;
		default : pcEXCMessage = _strdup(MESSAGE_DEFAUT);
	}
	pcEXCMessageDetail = _strdup(pcMessageDetail);
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
	pcEXCMessage =_strdup(EXCObjet.pcEXCMessage);
	pcEXCMessageDetail =_strdup(EXCObjet.pcEXCMessageDetail);
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
{
	//probleme lors de la destruction des objets de la classe.
	free(pcEXCMessage);
	free(pcEXCMessageDetail);
}

/******************************************************************************
M�thode de lecture de la valeur
*******************************************************************************
Entr�e : Rien
Necessit� : N�ant
Sortie : Valeur
Entraine : Retourne la valeur.
******************************************************************************/
unsigned int Cexception::EXCLire_Valeur() const
{
	return uiEXCValeur;
}

/******************************************************************************
M�hode de modification de la valeur
*******************************************************************************
Entr�e : Valeur
Necessit� : Valeur existante.
Sortie : N�ant
Entraine : Modification de la valeur et du message associ�.
******************************************************************************/
void Cexception::EXCModifier_Valeur(unsigned int uiValeur, bool reinitSuppMessage)
{
	uiEXCValeur = uiValeur;
	switch(uiEXCValeur)
	{
		case 1 : free(pcEXCMessage);
			pcEXCMessage = _strdup(MESSAGE_ALLOCATION);
			break;
		case 2 : free(pcEXCMessage);
			pcEXCMessage = _strdup(MESSAGE_REALLOCATION);
			break;
		case 3 : free(pcEXCMessage);
			pcEXCMessage = _strdup(MESSAGE_TAILLE_MATRICE);
			break;
		default : free(pcEXCMessage);
			pcEXCMessage = _strdup(MESSAGE_DEFAUT);
	}
	if(reinitSuppMessage ==true)
	{
		free(pcEXCMessageDetail);
		pcEXCMessageDetail= _strdup(MESSAGE_SUPP_DEFAUT);
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
char * Cexception::EXCLire_Message() const
{
	size_t TailleMessage =(strlen(pcEXCMessage)+strlen(pcEXCMessageDetail) +1);
	char* pcMessageComplet = _strdup( pcEXCMessage); // concat�nation du message supp
	strcat_s( pcMessageComplet, TailleMessage, pcEXCMessageDetail);
	return pcMessageComplet;
} 

/******************************************************************************
M�hode de modification du message
*******************************************************************************
Entr�e : Message
Necessit� : N�ant
Sortie : Rien
Entraine : Modification du message.
******************************************************************************/
void Cexception::EXCModifier_Message(char * pcMessage)
{
	free(pcEXCMessageDetail);
	pcEXCMessageDetail = _strdup(pcMessage);
}

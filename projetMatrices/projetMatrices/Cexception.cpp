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
	pcEXCMessage = _strdup(MESSAGE_DEFAUT);
	pcEXCMessageDetail = _strdup(MESSAGE_SUPP_DEFAUT);
}

/******************************************************************************
Constructeur à 2 arguments
*******************************************************************************
Entrée : La valeur et le message associé.
Necessité : Néant
Sortie : Rien
Entraine : L'objet en cours est initialisé avec un message détaillé de l'erreur.
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
Entrée : Un objet de la classe.
Necessité : Néant
Sortie :Rien
Entraine : Création d'un objet par recopie.
******************************************************************************/
Cexception::Cexception(const Cexception & EXCObjet)
{
	uiEXCValeur = EXCObjet.uiEXCValeur;
	pcEXCMessage =_strdup(EXCObjet.pcEXCMessage);
	pcEXCMessageDetail =_strdup(EXCObjet.pcEXCMessageDetail);
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
{
	//probleme lors de la destruction des objets de la classe.
	free(pcEXCMessage);
	free(pcEXCMessageDetail);
}

/******************************************************************************
Méthode de lecture de la valeur
*******************************************************************************
Entrée : Rien
Necessité : Néant
Sortie : Valeur
Entraine : Retourne la valeur.
******************************************************************************/
unsigned int Cexception::EXCLire_Valeur() const
{
	return uiEXCValeur;
}

/******************************************************************************
Méhode de modification de la valeur
*******************************************************************************
Entrée : Valeur
Necessité : Valeur existante.
Sortie : Néant
Entraine : Modification de la valeur et du message associé.
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
Méthode de lecture de la valeur
*******************************************************************************
Entrée : Rien
Necessité : Néant
Sortie : Valeur
Entraine : Retourne la valeur.
******************************************************************************/
char * Cexception::EXCLire_Message() const
{
	size_t TailleMessage =(strlen(pcEXCMessage)+strlen(pcEXCMessageDetail) +1);
	char* pcMessageComplet = _strdup( pcEXCMessage); // concaténation du message supp
	strcat_s( pcMessageComplet, TailleMessage, pcEXCMessageDetail);
	return pcMessageComplet;
} 

/******************************************************************************
Méhode de modification du message
*******************************************************************************
Entrée : Message
Necessité : Néant
Sortie : Rien
Entraine : Modification du message.
******************************************************************************/
void Cexception::EXCModifier_Message(char * pcMessage)
{
	free(pcEXCMessageDetail);
	pcEXCMessageDetail = _strdup(pcMessage);
}

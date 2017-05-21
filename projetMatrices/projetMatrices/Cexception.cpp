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
		case ERREUR_ALLOCATION :
			pcEXCMessage = _strdup(MESSAGE_ALLOCATION);
			break;
		case ERREUR_REALLOCATION : 
			pcEXCMessage = _strdup(MESSAGE_REALLOCATION);
			break;
		case ERREUR_CALCUL :
			pcEXCMessage = _strdup(MESSAGE_CALCUL);
			break;
		case ERREUR_PARAM :
			pcEXCMessage = _strdup(MESSAGE_PARAM);
			break;
		case ERREUR_FICHIER :
			pcEXCMessage = _strdup(MESSAGE_FICHIER);
			break;
		case ERREUR_PARSEUR :
			pcEXCMessage = _strdup(MESSAGE_PARSEUR);
			break;
		case ERREUR_PRECONDITIONS :
			pcEXCMessage = _strdup(MESSAGE_PRECONDITIONS);
			break;
		default : 
			pcEXCMessage = _strdup(MESSAGE_DEFAUT);
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
	pcEXCMessage = _strdup(EXCObjet.pcEXCMessage);
	pcEXCMessageDetail = _strdup(EXCObjet.pcEXCMessageDetail);
}

/******************************************************************************
Destructeur par d�faut
*******************************************************************************
Entr�e : Rien
Necessit� : N�ant
Sortie : Rien
Entraine : L'espace allou� par l'objet a �t� lib�r�
******************************************************************************/
Cexception::~Cexception()
{
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
		case ERREUR_ALLOCATION :
			pcEXCMessage = _strdup(MESSAGE_ALLOCATION);
			break;
		case ERREUR_REALLOCATION : 
			pcEXCMessage = _strdup(MESSAGE_REALLOCATION);
			break;
		case ERREUR_CALCUL :
			pcEXCMessage = _strdup(MESSAGE_CALCUL);
			break;
		case ERREUR_PARAM :
			pcEXCMessage = _strdup(MESSAGE_PARAM);
			break;
		case ERREUR_FICHIER :
			pcEXCMessage = _strdup(MESSAGE_FICHIER);
			break;
		case ERREUR_PARSEUR :
			pcEXCMessage = _strdup(MESSAGE_PARSEUR);
			break;
		case ERREUR_PRECONDITIONS :
			pcEXCMessage = _strdup(MESSAGE_PRECONDITIONS);
			break;
		default : 
			pcEXCMessage = _strdup(MESSAGE_DEFAUT);
	}

	if(reinitSuppMessage == true)
	{
		free(pcEXCMessageDetail);
		pcEXCMessageDetail= _strdup(MESSAGE_SUPP_DEFAUT);
	}
}

/******************************************************************************
M�thode de lecture du message
*******************************************************************************
Entr�e : Rien
Necessit� : N�ant
Sortie : char * le message
Entraine : Retourne le message entier
******************************************************************************/
char * Cexception::EXCLire_Message() const
{
	size_t stTailleMessage = strlen(pcEXCMessage) + strlen(pcEXCMessageDetail) + 2;
	char* pcMessageComplet = new char[stTailleMessage + 1];
	unsigned int uiCompteurMessage, uiCompteurDetail;

	for(uiCompteurMessage = 0; uiCompteurMessage < strlen(pcEXCMessage); uiCompteurMessage++)
		pcMessageComplet[uiCompteurMessage] = pcEXCMessage[uiCompteurMessage];

	if(strlen(pcEXCMessageDetail) > 0)
	{
		pcMessageComplet[uiCompteurMessage] = ' ';
		uiCompteurMessage++;
		pcMessageComplet[uiCompteurMessage] = '-';
		uiCompteurMessage++;
		pcMessageComplet[uiCompteurMessage] = ' ';
		uiCompteurMessage++;
	}

	for(uiCompteurDetail = 0; uiCompteurDetail < strlen(pcEXCMessageDetail); uiCompteurDetail++)
		pcMessageComplet[uiCompteurMessage + uiCompteurDetail] = pcEXCMessageDetail[uiCompteurDetail];
	pcMessageComplet[uiCompteurMessage + uiCompteurDetail] = '\0';

	return pcMessageComplet;
} 

/******************************************************************************
M�hode de modification du message
*******************************************************************************
Entr�e : Char * Message
Necessit� : N�ant
Sortie : Rien
Entraine : Modification du message.
******************************************************************************/
void Cexception::EXCModifier_Message(char * pcMessage)
{
	free(pcEXCMessageDetail);
	pcEXCMessageDetail = _strdup(pcMessage);
}

/******************************************************************************
Surcharge de l'op�rateur d'affectation
*******************************************************************************
Entr�e : r�f�rence sur un objet de type Cexception
Necessit� : N�ant
Sortie : Rien
Entraine : L'objet a �t� affect� par recopie de l'objet en param�tre
******************************************************************************/
Cexception & Cexception::operator=(Cexception const & EXCexception)
{
	uiEXCValeur = EXCexception.uiEXCValeur;
	free(pcEXCMessage);
	pcEXCMessage = _strdup(EXCexception.pcEXCMessage);
	free(pcEXCMessageDetail);
	pcEXCMessageDetail = _strdup(EXCexception.pcEXCMessageDetail);

	return *this;
}
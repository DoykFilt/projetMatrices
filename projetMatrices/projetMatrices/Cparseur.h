#ifndef CPARSEUR_H
#define CPARSEUR_H

/******************************************************************************
class Cparseur
*******************************************************************************

	Cette classe permet de trnasformer les donn�es d'un fichier en donn�es
	brut � l'aide de balises et d'en sortir un graph

	Attributs
		uiPARNbrBalises : le nombre de balises d�tectables
		ppcPARBalises : Les balises � rep�rer dans le texte
		pcPARtabBalisesValeurs : Les donn�es brutes relev�es du fichier, chaque
			ligne correspond � une balise : la premi�re colonne le nom de la 
			balise et la seconde sa valeur d�tect�

******************************************************************************/
class Cparseur
{
private :
	unsigned int uiPARNbrBalises;
	char ** ppcPARBalises;
	char *** pppcPARtabBalisesValeurs;

public :
	//########## Constructeurs et destructeurs ##########//
	/******************************************************************************
	Constructeur
	*******************************************************************************
	Entr�e : char ** tableau contenant les noms de balise, unsigned int le nombre de balise
	Necessit� : uiNbrBalises correspond au nombre de balises dans pcBalises
	Sortie : Rien
	Entraine : L'objet a �t� initialis�
	******************************************************************************/
	Cparseur(char ** ppcBalises, unsigned int uiNbrBalises);
	/******************************************************************************
	Constructeur de recopie
	*******************************************************************************
	Entr�e : R�f�rence sur un objet de type Cparseur
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet a �t� initialis� par recopie de l'objet en param�tre
	******************************************************************************/
	Cparseur(Cparseur & PARObjet);
	/******************************************************************************
	Destructeur
	*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'espace allou� pour les attributs de l'objet a �t� lib�r�
	******************************************************************************/
	~Cparseur();

	//########## M�thodes ##########//
	/******************************************************************************
	PARbrut
	*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : char *** un pointeur sur la matrice contenant les donn�es brutes
	Entraine : la matrice a �t� renvoy�e
	******************************************************************************/
	char *** PARbrut(){ return pppcPARtabBalisesValeurs; }
	/******************************************************************************
	PARvaleurSuivante
	*******************************************************************************
	Entr�e : (2 cha�nes de caract�res)pcBalise et pcChaine
	Necessit� : il y a une valeur associ�e � la balise dans la cha�ne de caract�re
	Sortie : une chaine de caract�re, la valeur associ�e
	Entraine : la valeur est trouv�e, renvoi�e et �ffac� de la cha�ne de caract�re
	******************************************************************************/
	char * PARvaleurSuivante(char * pcBalise, char * pcChaine);
	//Permet de r�colter les donn�es d'un fichier et de les stocker sous un format brut
	/******************************************************************************
	PARLire (inspir� par les m�thodes de compilation)
	*******************************************************************************
	Entr�e : pcfilename le chemin d'acc�s au fichier (cha�ne de caract�re)
	Necessit� : Le fichier existe et les donn�es dont au bon format dans le fichier
	Sortie : Rien
	Entraine : les donn�es sont lues et stock�es sous format brut
	******************************************************************************/
	void PARLire(char * pcfilename);
	/******************************************************************************
	PARLireNbrBalise
	*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : unsigned int, le nombre de balises
	Entraine : uiPARNbrBalises a �t� renvoy�
	******************************************************************************/
	unsigned int PARLireNbrBalise() { return uiPARNbrBalises; }

private :
	//M�thodes utilis� en interne pour le parsage
	/******************************************************************************
	PARreconnaitreBalise
	*******************************************************************************
	Entr�e : pcSource(cha�ne de caract�re)
	Necessit� : Rien
	Sortie : cha�ne de caract�res la balise reconnue
	Entraine : La balise est reconnue ou lev�e d'une exception
	******************************************************************************/
	char * PARreconnaitreBalise(char * pcSource);
	/******************************************************************************
	PARstockerValeur
	*******************************************************************************
	Entr�e : (2 cha�nes de caract�res)pcBalise et pcValeur, la valeur � stocker dans la balise
	Necessit� : La balise existe
	Sortie : Rien
	Entraine : La valeur a �t� associ�e � la bonne balise dans la matrice
	******************************************************************************/
	void PARstockerValeur(char * pcBalise, char * pcValeur);

public :
	//########## Surcharges d'op�rateurs ##########//
	/******************************************************************************
	surcharge de l'op�rateur d'affectation
	*******************************************************************************
	Entr�e : un objet du m�me type
	Necessit� : N�ant
	Sortie : Une r�f�rence sur l'objet en cours qui a �t� modifi�
	Entraine : L'objet en cours est une copie de l'objet en param�tre
	******************************************************************************/
	Cparseur & operator=(Cparseur const & PARparseur);
};

#endif
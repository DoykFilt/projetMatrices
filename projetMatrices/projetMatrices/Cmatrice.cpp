#include "Cmatrice.h"
#include "Cexception.h"

/******************************************************************************
Constructeur par d�faut
*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet en cours est initialis�.
******************************************************************************/
template<class MType> Cmatrice<MType>::Cmatrice()
{
	uiMATnbLignes = 0;
	uiMATnbColonnes = 0;

	ppMTMATMatrice = (MType **)malloc(0);
	if(ppMTMATMatrice == nullptr)
		throw Cexception(2, "Dans le constructeur de Cmatrice");
}

/******************************************************************************
Constructeur de recopie
*******************************************************************************
	Entr�e : Objet de la m�me classe
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet en cours est initialis� par recopie
******************************************************************************/
template<class MType> Cmatrice<MType>::Cmatrice(const Cmatrice<MType> & MTMATMatrice)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = MTMATMatrice.uiMATnbLignes;
	uiMATnbColonnes = MTMATMatrice.uiMATnbColonnes;

	ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbLignes);
	if(ppMTMATMatrice == nullptr)
		throw Cexception(2, "Dans le constructeur de recopie de Cmatrice");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
			throw Cexception(2, "Dans le constructeur de recopie de Cmatrice");

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];
	}
}

/******************************************************************************
Constructeur de confort 1
*******************************************************************************
	Entr�e : une matrice de type MType, uiLignes et uiColonnes deux naturels
	Necessit� : la matrice est de taille uiLignes * uiColonnes
	Sortie : Rien
	Entraine : L'objet en cours est initialis�.
******************************************************************************/
template<class MType> Cmatrice<MType>::Cmatrice(MType ** & ppMTMatrice, unsigned int uiLignes, unsigned int uiColonnes)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = uiLignes;
	uiMATnbColonnes = uiColonnes;
	ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbLignes);
	if(ppMTMATMatrice == nullptr)
		throw Cexception(2, "Dans le constructeur de recopie de Cmatrice");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
			throw Cexception(2, "Dans le constructeur de recopie de Cmatrice");

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMatrice[uiCompteurLignes][uiCompteurColonnes];
	}
}

/******************************************************************************
Constructeur de confort 2
*******************************************************************************
	Entr�e : uiLignes et uiColonnes deux naturels
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet en cours est initialis�, sa matrice est de taille uiLignes * uiColonnes remplie de 0;
******************************************************************************/
template<class MType> Cmatrice<MType>::Cmatrice(unsigned int uiLignes, unsigned int uiColonnes)
{
	unsigned int uiCompteurLignes;
	unsigned int uiCompteurColonnes;

	uiMATnbLignes = uiLignes;
	uiMATnbColonnes =uiColonnes;
	ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * uiMATnbLignes);
	if(ppMTMATMatrice == nullptr)
		throw Cexception(2, "Dans le constructeur de recopie de Cmatrice");

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * uiMATnbColonnes);
		if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
			throw Cexception(2, "Dans le constructeur de recopie de Cmatrice");

		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = (MType)0;
	}
}

/******************************************************************************
Destructeur
*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : Rien
	Entraine : L'objet en cours d�sallou�
******************************************************************************/
template<class MType> Cmatrice<MType>::~Cmatrice()
{
	unsigned int uiCompteurLignes;

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		free(ppMTMATMatrice[uiCompteurLignes]);
	free(ppMTMATMatrice);
}

/******************************************************************************
MATAfficherMatrice
*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : Rien
	Entraine : Affiche la matrice
******************************************************************************/
template<class MType> void Cmatrice<MType>::MTMATAfficherMatrice() const
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
	{
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			cout << ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] << " ";
		cout << endl;
	}
}

/******************************************************************************
MTMATgetNbLignes
*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : naturel
	Entraine : Retourne le nombre de lignes de la matrice
******************************************************************************/
template<class MType> inline unsigned int Cmatrice<MType>::MTMATgetNbLignes() const
{
	return uiMATnbLignes;
}

/******************************************************************************
MTMATgetNbColonnes
*******************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : naturel
	Entraine : Retourne le nombre de colonnes de la matrice
******************************************************************************/
template<class MType> inline unsigned int Cmatrice<MType>::MTMATgetNbColonnes() const
{
	return uiMATnbColonnes;
}

/******************************************************************************
MTMATget
*******************************************************************************
	Entr�e : uiLigne, uiColonnes deux naturel
	Necessit� : uiLigne et uiColonne ne sont pas plus grand que les dimensions de la matrice
	Sortie : MType
	Entraine : Retourne l'�l�ment de la matrice � la ligne uiLigne et � la colonne uiColonne
******************************************************************************/
template<class MType> inline MType Cmatrice<MType>::MTMATget(unsigned int uiLigne, unsigned int uiColonne) const
{
	if(uiLigne > uiMATnbLignes || uiColonne > uiMATnbColonnes)
		throw Cexception(4, "Indices en parametre trop grands (Methode MTMATget)");

	return ppMTMATMatrice[uiLigne][uiColonne];
}

/******************************************************************************
MTMATset
*******************************************************************************
	Entr�e : uiLigne, uiColonnes deux naturel, MTValeur la valeur � stocker
	Necessit� : uiLigne et uiColonne ne sont pas plus grand que les dimensions de la matrice
	Sortie : Rien
	Entraine : L'�l�ment � la position uiLigne, uiColonnes a �t� remplac�
******************************************************************************/
template<class MType> inline void Cmatrice<MType>::MTMATset(unsigned int uiLigne, unsigned int uiColonne, MType MTValeur)
{
	if(uiLigne > uiMATnbLignes || uiColonne > uiMATnbColonnes)
		throw Cexception(4, "Indices en parametre trop grands (Methode MTMATset)");

	ppMTMATMatrice[uiLigne][uiColonne] = MTValeur;
}

/******************************************************************************
MTMATsetMatrice
*******************************************************************************
	Entr�e : uiLigne, uiColonnes deux naturel, ppMTMatrice une matrice de type MType
	Necessit� : ppMTMatrice est de taille uiLignes * uiColonne
	Sortie : Rien
	Entraine : Les attributs de l'objet ont �t� remplac�s
******************************************************************************/
template<class MType> inline void Cmatrice<MType>::MTMATsetMatrice(const MType ** ppMTMatrice, const unsigned int uiLignes, const unsigned int uiColonnes)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	if(uiLignes > uiMATnbLignes)
	{
		ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * uiLignes);
		if(ppMTMATMatrice == nullptr)
			throw Cexception(2, "Dans la methode MTMATsetMatrice");
	}
	else if(uiLignes < uiMATnbLignes)
	{
		for(uiCompteurLignes = uiMATnbLignes; uiCompteurLignes > uiLignes; uiCompteurLignes--)
			free(ppMTMATMatrice[uiCompteurLignes]);

		ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * uiLignes);
		if(ppMTMATMatrice == nullptr)
			throw Cexception(2, "Dans la methode MTMATsetMatrice");
	}
	uiMATnbLignes = uiLignes;

	if(uiColonnes > uiMATnbColonnes || uiColonnes < uiMATnbColonnes)
	{
		for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		{
			ppMTMATMatrice[uiCompteurLignes] = (MType *)realloc(ppMTMATMatrice[uiCompteurLignes], sizeof(MType) * uiColonnes);
			if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
				throw Cexception(2, "Dans la methode MTMATsetMatrice");
		}
	}
	uiMATnbColonnes = uiColonnes;

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = ppMTMatrice[uiCompteurLignes][uiCompteurColonnes];
}

/******************************************************************************
surcharge de l'op�rateur d'affectation
*******************************************************************************
	Entr�e : un objet du m�me type
	Necessit� : N�ant
	Sortie : Une r�f�rence sur l'objet en cours qui a �t� modifi�
	Entraine : L'objet en cours est une copie de l'objet en param�tre
******************************************************************************/
template<class MType> Cmatrice<MType> & Cmatrice<MType>::operator=(Cmatrice<MType> const & MTMATMatrice)
{
	unsigned int uiCompteurLignes, uiCompteurColonnes;

	//Dans le cas o� notre objet n'a pas �t� pr�alablement allou�
	if(ppMTMATMatrice == nullptr)
	{
		ppMTMATMatrice = (MType **)malloc(sizeof(MType *) * MTMATMatrice.uiMATnbLignes);
		if(ppMTMATMatrice == nullptr)
			throw Cexception(2, "Lors d'une affectation d'une Cmatrice dans une autre");
		uiMATnbLignes = MTMATMatrice.uiMATnbLignes;
		
		for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		{
			ppMTMATMatrice[uiCompteurLignes] = (MType *)malloc(sizeof(MType) * MTMATMatrice.uiMATnbColonnes);
			if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
				throw Cexception(2, "Lors d'une affectation d'une Cmatrice dans une autre");
		}
		uiMATnbColonnes = MTMATMatrice.uiMATnbColonnes;
	}
	else //Sinon on realloue de la bonne taille
	{
		if(MTMATMatrice.uiMATnbLignes > uiMATnbLignes)
		{
			ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * MTMATMatrice.uiMATnbLignes);
			if(ppMTMATMatrice == nullptr)
				throw Cexception(2, "Lors d'une affectation d'une Cmatrice dans une autre");
		}
		else if(MTMATMatrice.uiMATnbLignes < uiMATnbLignes)
		{
			for(uiCompteurLignes = uiMATnbLignes; uiCompteurLignes > MTMATMatrice.uiMATnbLignes; uiCompteurLignes--)
				free(ppMTMATMatrice[uiCompteurLignes]);
			ppMTMATMatrice = (MType **)realloc(ppMTMATMatrice, sizeof(MType *) * MTMATMatrice.uiMATnbLignes);
			if(ppMTMATMatrice == nullptr)
				throw Cexception(2, "Lors d'une affectation d'une Cmatrice dans une autre");
		}
		uiMATnbLignes = MTMATMatrice.uiMATnbLignes;

		if(MTMATMatrice.uiMATnbColonnes > uiMATnbColonnes || MTMATMatrice.uiMATnbColonnes < uiMATnbColonnes)
		{
			for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
			{
				ppMTMATMatrice[uiCompteurLignes] = (MType *)realloc(ppMTMATMatrice[uiCompteurLignes], sizeof(MType) * MTMATMatrice.uiMATnbColonnes);
				if(ppMTMATMatrice[uiCompteurLignes] == nullptr)
					throw Cexception(2, "Lors d'une affectation d'une Cmatrice dans une autre");
			}
		}
		uiMATnbColonnes = MTMATMatrice.uiMATnbColonnes;
	}

	for(uiCompteurLignes = 0; uiCompteurLignes < uiMATnbLignes; uiCompteurLignes++)
		for(uiCompteurColonnes = 0; uiCompteurColonnes < uiMATnbColonnes; uiCompteurColonnes++)
			ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes] = MTMATMatrice.ppMTMATMatrice[uiCompteurLignes][uiCompteurColonnes];

	return *this;
}





/************************************************************************************************************************************************************
MTMATEchelonnageMatrice
*************************************************************************************************************************************************************
	Entr�e : Rien
	Necessit� : N�ant
	Sortie : r�f�rence sur un objet de type CMatrice<MType>
	Entraine : Retourne la matrice echelonn�e
************************************************************************************************************************************************************/
template<class MType> CMatrice<MType> & CMatrice<MType>::MTMATEchelonnageMatrice() const
{
	//constructeur de recopie de la matrice existante
	CMatrice<MType> * MTMATMatrice = new CMatrice(* MTMATMatrice);

	//compteurs de parcours de la matrice pour les diff�rents calculs
	unsigned int uiCompteurLignes, uiCompteurColonnes; 	
	unsigned int uiCompteurColonnesInterne;

	//  = r  ligne dernier pivot trouv�
	unsigned int uiDernierPivot=0; 
	
	//position du pivot d'une colonne
	unsigned int uiPositionPivot; 

	//valeur du pivot + tampon pour inversion des lignes -> voir nommage
	MType pivot; 
	MType tamponInversion;

	//boucle exterieure, pour r�duire avec un pivot sur chaque colonne
	for(uiCompteurColonnes=0, uiCompteurColonnes< uiMATnbColonnes, uiCompteurColonnes++)
	{
		//pivot initialise comme la valeur a la ligne apres celle du dernier pivot + num ligne
		pivot = MTMATMatrice[uiCompteurColonnes][uiDernierPivot];
		uiPositionPivot = uiDernierPivot;

		//parcours des lignes pour trouver le max -> nouveau pivot
		for(uiCompteurLignes=uiPositionPivot+1, uiCompteurLignes<uiMATnbLignes, uiCompteurLignes++)
		{
			if(pivot < abs(Matrice[uiCompteurColonnes][uiCompteurLignes]))
			{
				//remplacement du pivot et du num ligne
				pivot = MTMATMatrice[uiCompteurColonnes][uiCompteurLignes];
				uiPositionPivot = uiCompteurLignes;
			}
		}

		if(pivot !=0)
		{
			//division de la ligne du pivot pour mettre celui ci a 1
			//inversion entre ligne pivot et ancien pivot +1 
			for(uiCompteurColonnesInterne=0, uiCompteurColonnesInterne < uiMATnbColonnes, uiCompteurColonnesInterne++)
			{
				MTMATMatrice[uiCompteurColonnesInterne][uiPositionPivot]/=pivot;
				tamponInversion =MTMATMatrice[uiCompteurColonnesInterne][uiPositionPivot];
				MTMATMatrice[uiCompteurColonnesInterne][uiPositionPivot] = MTMATMatrice[uiCompteurColonnesInterne][uiDernierPivot];
				MTMATMatrice[uiCompteurColonnesInterne][uiDernierPivot] = MTMATMatrice[uiCompteurColonnesInterne][uiPositionPivot];
			}
			uiPositionPivot = uiDernierPivot; // remplacement ligne pivot par sa nouvelle valeur

			//soustraction des lignes par celle du pivot multipli� par le valeur sur ligne pivot -> mise a zero de la colonne du pivot
			for(uiCompteurLignes=0, uiCompteurLignes < uiMATnbLignes, uiCompteurLignes++)
			{
				if(uiCompteurLignes != uiDernierPivot)
				{
					for(uiCompteurColonnesInterne=0, uiCompteurColonnesInterne < uiMATnbColonnes, uiCompteurColonnesInterne++)
						MTMATMatrice[uiCompteurColonnesInterne][uiCompteurLignes] -= MTMATMatrice[uiCompteurColonnes][uiCompteurLignes] * MTMATMatrice[uiCompteurColonnesInterne][uiPositionPivot];
				}
			}
			uiDernierPivot++;
		}
		else
			throw Cexception(4, "matrice non inversible"); // warning ? non necessaire pour l'echelonnage

	}
	return *MTMATMatrice;
}


/************************************************************************************************************************************************************
MTMATCalculRang
*************************************************************************************************************************************************************
	Entr�e : Rien
	Necessit� : matrice echelonn�e en parametre
	Sortie : Rang de la matrice echelonn�e
	Entraine : N�ant
************************************************************************************************************************************************************/
template<class MType> unsigned int CMatrice<MType>::MTMATCalculRang()
{
	unsigned int uiRang=0;
	unsigned int uiCompteurLignes, uiCompteurColonnes; 
	bool bLigneVide;
	
	for(uiCompteurLignes=0, uiCompteurLignes < uiMATnbLignes, uiCompteurLignes++)
	{
		bLigneVide=true;
		for(uiCompteurColonnes=0, uiCompteurColonnes < uiMATnbColonnes, uiCompteurColonnes++)
		{
			if(ppMTMATMatrice[uiCompteurColonnes][uiCompteurLignes] != 0)
				bLigneVide=false;
		}
		if(bLigneVide == false)
			uiRang++;
	}

	return uiRang;
}
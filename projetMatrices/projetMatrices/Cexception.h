#ifndef CEXCEPTION
#define CEXCEPTION

#include <string>
using namespace std;

#define ERREUR_DEFAUT 0
#define MESSAGE_DEFAUT "Message defaut"
#define MESSAGE_SUPP_DEFAUT ""
#define ERREUR_ALLOCATION 1
#define MESSAGE_ALLOCATION "L'allocation a échoué"
#define ERREUR_REALLOCATION 2
#define MESSAGE_REALLOCATION "La reallocation a échoué"
#define ERREUR_TAILLE_MATRICE 3
#define MESSAGE_TAILLE_MATRICE "Calcul sur des matrices de tailles incompatibles"

class Cexception
{
private :

	//Attributs
	unsigned int uiEXCValeur;
	char * pcEXCMessage;
	char * pcEXCMessageDetail;

public :

	//Constructeurs et destructeurs
	Cexception(); 
	Cexception(unsigned int uiValeur);
	//Cexception(unsigned int uiValeur, char * pcMessage); 
	Cexception(const Cexception & EXCObjet);
	~Cexception();

	//Methodes
	unsigned int EXCLire_Valeur() const;
	void EXCModifier_Valeur(unsigned int uiValeur);
	char * EXCLire_Message() const;
	void EXCModifier_Message(char * pcMessage);
};

#endif
#ifndef CEXCEPTION
#define CEXCEPTION

#include <string>
using namespace std;

#define ERREUR_DEFAUT 0
#define MESSAGE_DEFAUT "Message defaut"

class Cexception
{
private :

	//Attributs
	unsigned int uiEXCValeur;
	string sEXCMessage;

public :

	//Constructeurs et destructeurs
	Cexception(); 
	Cexception(unsigned int uiValeur, string sMessage);
	Cexception(const Cexception & EXCObjet);
	~Cexception();

	//Methodes
	unsigned int EXCLire_Valeur() const;
	void EXCModifier_Valeur(unsigned int uiValeur);
	string EXCLire_Message() const;
	void EXCModifier_Message(string sMessage);

};

#endif
#include "Cexception.h"
#include <iostream>

void main()
{
	Cexception * exception1 = new Cexception();
	Cexception * exception2 = new Cexception(2);
	Cexception * exception3 = new Cexception(1, "allocation mal faite");
	Cexception * exception4 = new Cexception(* exception2);
	Cexception * exception5 = new Cexception(2,"erreur");

	cout<<exception1->EXCLire_Valeur()<<endl;
	cout<<exception1->EXCLire_Message()<<endl;

	cout<<exception2->EXCLire_Valeur()<<endl;
	cout<<exception2->EXCLire_Message()<<endl;
	
	cout<<exception3->EXCLire_Valeur()<<endl;
	cout<<exception3->EXCLire_Message()<<endl;
	
	cout<<exception4->EXCLire_Valeur()<<endl;
	cout<<exception4->EXCLire_Message()<<endl;
	
	cout<<exception5->EXCLire_Valeur()<<endl;
	cout<<exception5->EXCLire_Message()<<endl;

	
	exception1->EXCModifier_Valeur(2);
	exception1->EXCModifier_Message("nouveau message");
	cout<<exception1->EXCLire_Message()<<endl;
	
	exception1->EXCModifier_Message("nouveau messageb");
	cout<<exception1->EXCLire_Message()<<endl;

	exception1->EXCModifier_Message("allocation mal faite");
	cout<<exception1->EXCLire_Message()<<endl;

	exception1->EXCModifier_Message("allocation mal faite2");
	cout<<exception1->EXCLire_Message()<<endl;

	exception1->EXCModifier_Message("allocation mal faite2tres tres tres tres tres long");
	cout<<exception1->EXCLire_Message()<<endl;
	
	delete exception1;
	delete exception2;
	delete exception3;
	delete exception4;
	delete exception5;
	while(1);
	
}
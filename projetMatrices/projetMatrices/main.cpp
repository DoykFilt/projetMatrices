#include "Cexception.h"
#include "CMatrice.h"
#include "Cparseur.h"
#include <iostream>

using namespace std;

void main(int argc, char * argv[])
{
	unsigned int uiCmptr;
	Cparseur * PARparseur = new Cparseur();
/*
	for(uiCmptr = 1; uiCmptr < argc; uiCmptr++)
	{
		cout << argv[uiCmptr];
		PARparseur->PARLireMatrice(argv[uiCmptr]);
	}*/
	PARparseur->PARLireMatrice("C:\\Users\\thiba\\git_projects\\projetMatrices\\projetMatrices\\matrice1.txt");
	CMatrice<double> * dMATMatrice = PARparseur->PARcreerDoubleMatrice();

	dMATMatrice->MTMATAfficherMatrice();
}
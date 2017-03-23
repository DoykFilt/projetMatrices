#include <fstream>

using namespace std;

template<class MType> CMatrice<MType> LireMatrice(char * filename)
{
	char * pcLignes;
	char * pcElm;

	ifstream fichier(filename, ios::in);

	while(getline(fichier, pcLignes)
	{
		pcElm = strchr(pcLignes, '=')
	}

	fichier.close();

}
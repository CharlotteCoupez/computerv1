#include <iostream>
#include "PolynomialeClass.h"
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		PolynomialeClass equation(argv[1]);
		// pour bonus faire ici une fonction equation.formatWell avant de cree les attribut de l'objet
		equation.resolve(argv[1]);
		std::cout << "FIN" << std::endl;
	}
	else
	{
		std::cout <<"vous n'avez pas envoyé d'équation à résoudre" << std::endl;
	}

	return 0;
}

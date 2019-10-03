#include <iostream>
#include "PolynomialeClass.h"
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			PolynomialeClass equation(argv[i]);
			equation.resolve(argv[i]);
			i++;
		}
	}
	else
		std::cout <<"vous n'avez pas envoyé d'équation à résoudre" << std::endl;
	return 0;
}

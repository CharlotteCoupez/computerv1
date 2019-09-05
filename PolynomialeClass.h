#ifndef DEF_POLYNOMIALECLASS
#define DEF_POLYNOMIALECLASS

#include <string>
#include <vector>

class PolynomialeClass
{
	public:

		PolynomialeClass(); //Constructeur
		PolynomialeClass(std::string argv); // autre constructeur avec un parametre
		int reducePolynomiale(std::string argv);
		float calculDiscriminant();
		void resolve(std::string argv);
		void resolveEqDegreTwo();
		void resolveEqDegreOne();
		float racinecarree(float num);

	  private:

		std::vector<float> m_values;
		std::vector<int> m_puissances;
		std::string m_test; //Pas de using namespace std, il faut donc mettrestd:: devant string
		int degre;
		float discriminant;
		void sortTabs();
};

#endif

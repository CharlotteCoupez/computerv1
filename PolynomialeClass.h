#ifndef DEF_POLYNOMIALECLASS
#define DEF_POLYNOMIALECLASS

#include <string>
#include <vector>

class PolynomialeClass
{
	public:

		PolynomialeClass();
		PolynomialeClass(std::string argv);
		void	resolve(std::string argv);

	  private:
		int					degre;
		double				discriminant;
		std::string			m_test;
		std::vector<double>	m_values;
		std::vector<int>	m_puissances;
		void	sortTabs();
		void	printInfos();
		void	resolveEqDegreTwo();
		void	resolveEqDegreOne();
		double	calculDiscriminant();
		double	racinecarree(double num);
		int		reducePolynomiale(std::string argv);
};

#endif

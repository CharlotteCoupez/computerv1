#include <iostream>
#include "PolynomialeClass.h"
#include <stdlib.h>
#include <math.h>

using namespace std;

PolynomialeClass::PolynomialeClass(string argv)
{
	double sign = 1;

	argv.erase(std::remove(argv.begin(), argv.end(), ' '), argv.end());
	for (size_t i = 0; i < argv.size();i++)
	{
		string tmp;
		if (argv[i] == '=')
			sign = -1;
		if (isdigit(argv[i]) || argv[i] == '-')
		{
			while (i < argv.size() && (isdigit(argv[i + 1]) || argv[i + 1] == '.' || argv[i] == '-'))
				tmp.push_back(argv[i++]);
			tmp.push_back(argv[i]);
			if (m_values.size() == m_puissances.size())
				m_values.push_back(atof(tmp.c_str()) * sign);
			else
				m_puissances.push_back(atoi(tmp.c_str()));
		}
	}
}

void PolynomialeClass::resolve(string argv)
{
	if (reducePolynomiale(argv))
	{
		sortTabs();
		printInfos();
		if (degre == 2)
			resolveEqDegreTwo();
		else if (degre == 1)
			resolveEqDegreOne();
		else if (degre == 0)
			std::cout << "There is no solution " << std::endl;
	}
}

int PolynomialeClass::reducePolynomiale(string argv)
{
	m_test = argv;

	for (size_t i = 0; i < m_puissances.size(); i++)
	{
		if (m_values[i] == 0)
		{
			m_values.erase(m_values.begin() + i);
			m_puissances.erase(m_puissances.begin() + i);
			i--;
		}
		for (size_t j = i + 1; j < m_puissances.size(); j++)
		{
			if (m_puissances[i] == m_puissances[j])
			{
				m_values[i] = m_values[i] + m_values[j];
				m_values.erase(m_values.begin() + j);
				m_puissances.erase(m_puissances.begin() + j);
				j--;
			}
			if (m_values[i] == 0)
			{
				m_values.erase(m_values.begin() + i);
				i--;
				m_puissances.erase(m_puissances.begin() + i);
			}
		}
	}
	if (m_values.size() == 0 && m_puissances.size() == 0)
	{
		std::cout << "All real numbers are solution! " << std::endl;
		return 0;
	}
	return 1;
}

void PolynomialeClass::sortTabs()
{
	size_t	i;
	double	tmpValue;
	int		tmpPuissance;

	i = 0;
	while ( i < m_puissances.size() -1)
	{
		if (m_puissances[i] < m_puissances[i + 1])
		{
			tmpValue = m_values[i];
			tmpPuissance = m_puissances[i];
			m_values[i] = m_values[i + 1];
			m_puissances[i] = m_puissances[i + 1];
			m_values[i + 1] = tmpValue;
			m_puissances[i + 1] = tmpPuissance;
			i = 0;
		}
		else
			i++;
	}
}

void PolynomialeClass::printInfos()
{
	std::cout << "Reduced form:";
	for (size_t j = 0; j < m_values.size(); j++)
	{
		std::cout << " " << m_values[j];
		std::cout << " * X^" << m_puissances[j];
		if (j + 1 < m_values.size() && m_values[j + 1] >= 0)
			std::cout << " +";
	}
	std::cout << " = 0" << std::endl;
	if (m_puissances[0] > 2)
	{
		std::cout << "Polynomial degree: : " << m_puissances[0] << std::endl;
		std::cout << "The polynomial degree is stricly greater than 2, I can't solve." << std::endl;
		degre = m_puissances[0];
		return;
	}
	if (m_puissances[m_puissances.size() - 1] < 0)
	{
		std::cout << "Polynomial degree: : " << m_puissances[m_puissances.size() - 1] << std::endl;
		std::cout << "The polynomial degree is negative, I can't solve." << std::endl;
		degre = m_puissances[m_puissances.size() - 1];
		return;
	}
	std::cout << "Polynomial degree: : " << m_puissances[0] << std::endl;
	degre = m_puissances[0];
}

double PolynomialeClass::calculDiscriminant()
{
	discriminant = (m_values[1] * m_values[1]) - (4 * m_values[0] * m_values[2]); // discriminant = b^2 - 4ac
	return discriminant;
}

void PolynomialeClass::resolveEqDegreTwo()
{
	double s1;
	double s2;

	calculDiscriminant();
	if (discriminant > 0)
	{
		std::cout << "Discriminant is strictly positive, the two solutions are:" << std::endl;
		s1 = (-m_values[1] - racinecarree(discriminant)) / (2 * m_values[0]);
		s2 = (-m_values[1] + racinecarree(discriminant)) / (2 * m_values[0]);
		std::cout << s1 << "\n" << s2 << std::endl;
	}
	else if (discriminant == 0)
	{
		std::cout << "Discriminant is null, the solution is:" << std::endl;
		s1 = -m_values[1] / (2 * m_values[0]);
		std::cout << s1 << std::endl;
	}
	else if (discriminant < 0)
		std::cout << "Discriminant is strictly negative, no real solution existe." << std::endl;
}

void PolynomialeClass::resolveEqDegreOne()
{
	double s;

	s = -m_values[1] / m_values[0];
	std::cout << "The solution is: " << std::endl << s << std::endl;
}

double PolynomialeClass::racinecarree(double num) // méthode de Newton
{
	double x = 1;
	int i = 0;
	while (i++ < 20)
		x = 0.5 * (x + num / x);
	return x;
}

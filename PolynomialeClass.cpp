#include <iostream>
#include "PolynomialeClass.h"
#include <stdlib.h>
#include <math.h>

using namespace std;


PolynomialeClass::PolynomialeClass(string argv)
{
	int sign = 1;
	int afterEq = 0;

	for (int i = 0; i < argv.size();)
	{
		string tmp;
		while (argv[i] == ' ')
			i++;
		if (argv[i] == '=')
		{
			afterEq = 1;
			sign = -1;
		}
		if (argv[i] == '-' || (argv[i] == '+' && afterEq))
			sign = -1;
		if (argv[i] == '+' || (argv[i] == '-' && afterEq))
			sign = 1;
		if (isdigit(argv[i]))
		{
			while (isdigit(argv[i]) || argv[i] == '.')
				tmp.push_back(argv[i++]);

			if (m_values.size() == m_puissances.size())
				m_values.push_back(atof(tmp.c_str()) * sign);
			else
				m_puissances.push_back(atof(tmp.c_str()));
		}
		i++;
	}
}

float PolynomialeClass::racinecarree(float num) // méthode de Newton
{
	float x = 1;
	int i = 0;
	while (i++ < 20)
		x = 0.5 * (x + num / x);
	return x;
}

int PolynomialeClass::reducePolynomiale(string argv)
{
	m_test = argv;
	std::cout << "vous avez envoyé une équation à résoudre on reduce lequation" << m_test << std::endl;
	for (int i = 0; i < m_values.size(); i++)
	{
		std::cout << "m_values[i] : " << m_values[i] << std::endl;
	}
	for (int i = 0; i < m_puissances.size(); i++)
	{
		std::cout << "m_puissances[i] : " << m_puissances[i] << std::endl;
	}
	for (int i = 0; i < m_puissances.size(); i++)
	{
		for (int j = i + 1; j < m_puissances.size(); j++)
		{
			if (m_puissances[i] == m_puissances[j])
			{
				m_values[i] = m_values[i] + m_values[j];
				m_values.erase(m_values.begin() + j);
				m_puissances.erase(m_puissances.begin() + j);
				if (m_values[i] == 0)
				{
					m_values.erase(m_values.begin() + i);
					m_puissances.erase(m_puissances.begin() + i);
					i = 0;
					j = 0;
				}
			}
		}
	}
	std::cout << "aa m_values[i] : " << m_values[0] << m_values.size() << std::endl;
	std::cout << "aa m_puissances[i] : " << m_puissances[0] << m_puissances.size() << std::endl;
	if (m_values.size() == 0 && m_puissances.size() == 0)
	{
		std::cout << "all real numbers are solution... " << std::endl;
		return 0;
	}
		for (int i = 0; i < m_values.size();)
		{
			std::cout << "apres parse m_values[i] : " << m_values[i] << std::endl;
			i++;
		}
	for (int i = 0; i < m_puissances.size();)
	{
		std::cout << "apres parse m_puissances[i] : " << m_puissances[i] << std::endl;
		i++;
	}
	return 1;
}

void PolynomialeClass::sortTabs()
{
	float tmpValue;
	float tmpPuissance;
	float i = 0;

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
	std::cout << "Polynomial degree: : " << m_puissances[0] << std::endl;
	if (m_puissances[0] > 2)
		std::cout << "The polynomial degree is stricly greater than 2, I can't solve." << std::endl;
	if (m_puissances[0] < 0)
		std::cout << "The polynomial degree is negative, I can't solve." << std::endl;
	degre = m_puissances[0];
	for (int i = 0; i < m_values.size(); i++)
	{
		std::cout << "apres sort m_values[i] : " << m_values[i] << std::endl;
	}
	for (int i = 0; i < m_puissances.size(); i++)
	{
		std::cout << " apres sort m_puissances[i] : " << m_puissances[i] << std::endl;
	}
}

float PolynomialeClass::calculDiscriminant()
{
	// discriminant = b * b - 4 * a * c
	discriminant = (m_values[1] * m_values[1]) - (4 * m_values[0] * m_values[2]);
	return discriminant;
}

void PolynomialeClass::resolveEqDegreTwo()
{
	float s1 = 0;
	float s2 = 0;

	calculDiscriminant();
	if (discriminant > 0)
	{
		std::cout << "Discriminant is strictly positive, the two solutions are:" << std::endl;
		s1 = (-m_values[1] - racinecarree(discriminant)) / (2 * m_values[0]);
		s2 = (-m_values[1] + racinecarree(discriminant)) / (2 * m_values[0]);
		std::cout << s1 << "\n" << s2 << std::endl;
	}
	if (discriminant == 0)
	{
		std::cout << "Discriminant is null, the solution is:" << std::endl;
		s1 = -m_values[1] / (2 * m_values[0]);
		std::cout << "s1 : " << s1 << std::endl;
	}
	if (discriminant < 0)
		std::cout << "Discriminant is strictly negative, no real solution existe." << std::endl;
}

void PolynomialeClass::resolveEqDegreOne()
{
	std::cout << "degre one" << std::endl;
	float s;

	s = -m_values[1] / m_values[0];
	std::cout << "s" << s << std::endl;
}

void PolynomialeClass::resolve(string argv)
{
	// a faire : resoudre equation de degre 1 et le cas ou il n'y a plus de x aussi ou ou toute les valeurs son ok genre 42x = 42X
	if (reducePolynomiale(argv))
	{
		std::cout << "resolve" << std::endl;
		sortTabs();
		if (degre == 2)
			resolveEqDegreTwo();
		else if (degre == 1)
			resolveEqDegreOne();
		else
			std::cout << "this is not an equation." << std::endl;
	}
}

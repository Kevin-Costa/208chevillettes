//
// chevillettes.cpp for 208 in /home/alexandre/Projects/B4/maths/208chevillettes
// 
// Made by Alexandre Vanhoutte
// Login   <alexandre@epitech.net>
// 
// Started on  Tue May 26 11:14:10 2015 Alexandre Vanhoutte
// Last update Sat May 30 11:23:42 2015 Alexandre Vanhoutte
//

#include	<iostream>
#include	<stdlib.h>
#include	<math.h>
#include	<list>
#include	<iomanip>
#include	"Chevillettes.hh"

Chevillettes::Chevillettes() {}

Chevillettes::~Chevillettes() {}

bool		Chevillettes::checkArguments(int ac, char **av)
{
  int		i;
  int		j;

  if (ac != 10)
    {
      std::cerr << "\033[1;31mLe programme a besoin de 9 arguments\033[1;0m" << std::endl;
      return (false);
    }
  i = 1;
  while (av[i])
    {
      j = 0;
      while (av[i][j])
	{
	  if (av[i][j] < '0' || av[i][j] > '9')
	    {
	      std::cout << i << " " << j << std::endl;
	      std::cerr << "\033[1;31mLes arguments doivent être uniquement composés de chiffres\033[1;0m" << std::endl;
	      return (false);
	    }
	  j++;
	}
      i++;
    }
  int		result = 0;
  i = 1;
  while (av[i])
    {
      result += atoi(av[i]);
      i++;
    }
  if (result != 100)
    {
      std::cerr << "\033[1;31mL'ensemble des arguments doit être égale à 100.\033[1;0m" << std::endl;
      return (false);
    }
  return (true);
}

bool		Chevillettes::displayTab(char **ox)
{
  // int			nbCol;
  std::list<double>	newOX;
  std::list<double>	newTX;
  int			i;
  int			tmp;
  double		p;
  double		result;
  double		totalTX = 0;
  double		X2 = 0;
  int			v = 0;
  int			min;
  int			max;
  int			p2;
  int			i2;
  double		tabX2[11][14] =
    {
      {0, 99, 90, 80, 70, 60, 50, 40, 30, 20, 10, 5, 3, 1},
      {1, 0.00, 0.02, 0.06, 0.15, 0.27, 0.45, 0.71, 1.07, 1.64, 2.71, 3.84, 5.41, 6.63},
      {2, 0.02, 0.21, 0.45, 0.71, 1.02, 1.39, 1.83, 2.41, 3.22, 4.61, 5.99, 7.82, 9.21},
      {3, 0.11, 0.58, 1.01, 1.42, 1.87, 2.37, 2.95, 3.66, 4.64, 6.25, 7.81, 9.84, 11.34},
      {4, 0.30, 1.06, 1.65, 2.19, 2.75, 3.36, 4.04, 4.88, 5.99, 7.78, 9.49, 9.84, 11.34},
      {5, 0.55, 1.61, 2.34, 3.00, 3.66, 4.35, 5.13, 6.06, 7.29, 9.24, 11.07, 11.67, 13.28},
      {6, 0.7, 2.20, 3.07, 3.83, 4.57, 5.35, 6.21, 7.23, 8.56, 10.64, 12.59, 15.03, 16.81},
      {7, 1.24, 2.83, 3.82, 4.67, 5.49, 6.35, 7.28, 8.38, 9.80, 12.02, 14.07, 16.62, 18.48},
      {8, 1.65, 3.49, 4.59, 5.53, 6.42, 7.34, 8.35, 9.52, 11.03, 13.36, 15.51, 18.17, 20.09},
      {9, 2.09, 4.17, 5.38, 6.39, 7.63, 8.34, 9.41, 10.66, 12.24, 14.68, 16.92, 19.68, 21.67},
      {10, 2.56, 4.87, 6.18, 7.27, 8.30, 9.34, 10.47, 11.78, 13.44, 15.99, 18.31, 21.16, 23.21}
    };
  int			contr = 0;

  p = (atoi(ox[1]) * 0 + atoi(ox[2]) * 1 + atoi(ox[3]) * 2 + atoi(ox[4]) * 3 + atoi(ox[5]) * 4 + atoi(ox[6]) * 5 + atoi(ox[7]) * 6 + atoi(ox[8]) * 7 + atoi(ox[9]) * 8) / 10000.0;
  i = 1;
  tmp = 0;
  std::cout << " \033[1;31mx\t\033[1;32m|\033[1;34m ";
  result = 0;
  while (i < 10)
    {
      if (tmp == 0 && (atoi(ox[i - 1]) != 0 || (i - 1) == 0))
      	std::cout << "\033[1;31m" << i - 1;
      tmp += atoi(ox[i]);
      result += 100 * combinaison(i - 1, 100) * pow(p, i - 1) * pow((1 - p), 100 - (i - 1));
      if (tmp >= 10)
	{
	  std::cout << "\033[1;31m";
	  if (tmp != atoi(ox[i]) || atoi(ox[i - 1]) == 0)
	    std::cout << "-" << i - 1;
	  else
	    contr++;
	  std::cout << "\t\033[1;32m|\033[1;34m";
	  newOX.push_back(tmp);
	  i2++;
	  if (i != 9)
	    {
	      newTX.push_back(result);
	      result = 0;
	      tmp = 0;

	    }
	}
      i++;
    }
  if (tmp < 10)
    {
      newOX.push_back(tmp);
      std::cout << "\t\033[1;32m|\033[1;34m";
    }
  while (i < 50)
    {
      result += 100 * combinaison(i - 1, 100) * pow(p, i - 1) * pow((1 - p), 100 - (i - 1));
      i++;
    }
  newTX.push_back(result);
  std::cout << "\033[1;31m total" << std::endl;
  std::cout << "\033[1;32m------------------------------------------------------------------------\033[1;34m" << std::endl;
  std::list<double>::iterator	it = newOX.begin();
  std::cout << " \033[1;31mOx\t\033[1;32m|\033[1;34m ";
  while (it != newOX.end())
    {
      std::cout << *it << "\t\033[1;32m|\033[1;34m ";
      it++;
    }
  std::cout << "\033[1;33m 100" << std::endl;
  std::cout << "\033[1;32m------------------------------------------------------------------------" << std::endl;
  std::list<double>::iterator it2 = newTX.begin();
  std::cout << " \033[1;31mTx\t\033[1;32m|\033[1;34m " << std::fixed << std::setprecision(1);
  while (it2 != newTX.end())
    {
      std::cout << *it2 << "\033[1;32m\t|\033[1;34m ";
      totalTX += *it2;
      it2++;
    }
  std::cout << " \033[1;33m" << std::setprecision(0) << totalTX  << std::endl << std::endl;
  std::cout << "\033[1;32mloi choisie :\t\t\t\033[1;34mB(\033[1;31m" << std::setprecision(0) << totalTX << std::setprecision(4) << "\033[1;34m,\033[1;31m " << p << "\033[1;34m)" << std::endl;
  it = newOX.begin();
  it2 = newTX.begin();
  i = 0;
  while (it != newOX.end())
    {
      X2 += pow(*it - *it2, 2) / *it2;
      it++;
      it2++;
      i++;
    }
  std::cout << "\033[1;32msomme des carrés des écarts :\t\033[1;34mX² = \033[1;31m" << std::setprecision(3) << X2 << std::endl;
  p2 = i2 - (i2 - contr);
  std::cout << "\033[1;32mdegrés de liberté :\t\t\033[1;34mv = \033[1;31m" << std::setprecision(0) << p2 << std::setprecision(3) << std::endl;
  i = 1;
  while (i != 14)
    {
      if (X2 >= tabX2[p2][i] && X2 <= tabX2[p2][i + 1])
	{
	  max = tabX2[0][i];
	  min = tabX2[0][i + 1];
	  break;
	}
      else
	{
	  max = 1;
	  min = 0;
	}
      i++;
    }
  std::cout << "\033[1;32mvalidité de l'ajustement :\t\033[1;31m" << min << "\033[1;34m% < \033[1;31mP\033[1;34m < \033[1;31m" << max << "\033[1;34m%\033[1;0m" << std::endl;

}

double		factorielle(double lim)
{
  double		result = 1;
  double		i = 2;

  while (i <= lim)
    {
      result *= i;
      i++;
    }
  return (result);
}

double		combinaison(int n, int k)
{
  double num;
  double denum1;
  double denum2;

  num = factorielle(k);
  denum1 = factorielle(n);
  denum2 = factorielle(k - n);
  denum1 *= denum2;
  return (num / denum1);
}

bool		Chevillettes::run(int ac, char **ox)
{
  if ((checkArguments(ac, ox)) == false)
    return (false);
  displayTab(ox);
}

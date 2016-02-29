//
// chevillettes.hh for chevillettes in /home/alexandre/Projects/B4/maths/208chevillettes
// 
// Made by Alexandre Vanhoutte
// Login   <alexandre@epitech.net>
// 
// Started on  Tue May 26 11:14:53 2015 Alexandre Vanhoutte
// Last update Thu May 28 15:20:46 2015 Kevin Costa
//

class		Chevillettes
{
public:
  Chevillettes();
  ~Chevillettes();
  bool		run(int, char **);
  bool		checkArguments(int, char **);
  bool		displayTab(char **);
};

double factorielle(double lim);
double combinaison(int n, int k);

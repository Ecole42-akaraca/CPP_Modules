#include <iostream>

int main( int argc, char **argv )
{
	argc--;
	argv++;

	if (argc == 0)
	{
		// using namespace std; Since its use is prohibited, we have to add "std::" at the beginning.
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		int i;

		i = 0;
		while (argv[i])
		{
			int l;
			
			l = 0;
			while (argv[i][l])
			{
				std::cout << (char)toupper(argv[i][l]);
				l++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}

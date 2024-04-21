#include <iostream>

static	void	changeCase(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
	std::cout << c;
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for(int i = 1; i < argc; i++)
		{
			int j = 0;
			while (argv[i][j])
			{
				changeCase(argv[i][j]);
				j++;
			}
		}
	}
	std::cout << std::endl;
}

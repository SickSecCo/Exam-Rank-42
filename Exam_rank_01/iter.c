#include <unistd.h>

int check_back(char *s, int i)
{
	int k = 0;
	while (k < i)
	{
		if (s[k] == s[i])
			return (0);
		k++;
	}
	return (1);
}

int main (int ac, char **av)
{
	int i = 0, j = 0;
	if (ac == 3){
		while (av[1][i]){
			while (av[2][j] && check_back(av[1], i)){
				if (av[1][i] == av[2][j]){
					write(1, &av[1][i], 1);
					break;
				}
				j++;
			}
			j = 0;
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
#include <unistd.h>
#include <stdio.h>

#include "main_proc.h"


void	ft_exit(int argc, char **argv, char **current)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	ft_env(current);
	while (current[++i])
	{
		if (strncmp(current[i], "SHLVL=", 6) == 0)
		{
			j = current[i][6] - '0';
			j--;
			j += '0';
			current[i][6] = j;
			exit(0);
		}
	}
}
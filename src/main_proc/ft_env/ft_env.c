#include <unistd.h>
#include <stdio.h>

#include "main_proc.h"


void	ft_env(char **current)
{
	int	i;

	i = -1;
	while (current[++i])
	{
		if (strchr(current[i], '=') != NULL)
			printf("%s\n", current[i]);
	}
}

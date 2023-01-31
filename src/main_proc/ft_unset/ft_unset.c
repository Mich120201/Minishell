#include <unistd.h>
#include <stdio.h>

#include "main_proc.h"

void	ft_unset(int argc, char **argv, char **current)
{
	int			i;
	int			position;

	i = -1;
	ft_env(current);
	while (current[++i])
	{
		position = ft_strchrp(current[i], '=');
		if (ft_strncmp(current[i], argv[2], position) == 0)
		{
			free(current[i]);
			current[i] = (current[i + 1]);
			i++;
		}
	}
	ft_env(current);
}
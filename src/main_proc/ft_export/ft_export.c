#include <unistd.h>
#include <stdio.h>

#include "main_proc.h"

char	**sort(char **sorting)
{
	int		i;
	int		j;
	int		c;
	char	**sort_env;

	i = 0;
	while (sorting[i])
		++i;
	sort_env = malloc(sizeof(char *) * (i + 1));
	sort_env[i] = NULL;
	i = -1;
	while (sorting[++i])
	{
		j = -1;
		c = 0;
		while (sorting[++j])
			if (ft_strncmp(sorting[i], sorting[j], ft_strlen(sorting[i])) > 0)
				c++;
		sort_env[c] = sorting[i];
	}
	return (sort_env);
}

void	ft_export(int argc, char **argv, t_shell shell)
{
	shell.exp.i = -1;
	shell.exp.j = -1;
	if (argc == 2)
	{
		shell.exp.sort_env = sort(shell.env.current);
		shell.exp.i = -1;
		while (shell.exp.sort_env[++shell.exp.i])
			printf("declare -x %s\n", shell.exp.sort_env[shell.exp.i]);
	}
	while (shell.env.current[++shell.exp.i])
	{
		shell.exp.pos = ft_strchrp(shell.env.current[shell.exp.i], '=');
		if (ft_strncmp(shell.env.current[shell.exp.i], \
					argv[2], shell.exp.pos + 1) == 0)
		{
			shell.env.current[shell.exp.i] = argv[2];
			shell.exp.j = 0;
		}
	}
	if (shell.exp.j == -1)
	{
		shell.env.current[shell.exp.i] = argv[2];
		shell.env.current[shell.exp.i + 1] = NULL;
	}
	return ;
}
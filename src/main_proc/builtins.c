#include <unistd.h>
#include <stdio.h>

#include "main_proc.h"

void	get_env(char **envp, t_shell *env_list)
{
	int	c;
	int	i;

	c = -1;
	i = -1;
	while (envp[++i])
		;
	env_list->env.current = (char **)malloc(sizeof(char *) * 400000);
	while (envp[++c])
	{
		env_list->env.current[c] = ft_strdup(envp[c]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int			i;
	t_shell		shell;

	get_env(envp, &shell);
	i = -1;
	while (argv[++i])
	{
		if (strncmp(argv[i], "pwd", 4) == 0)
			ft_pwd();
		else if (strncmp(argv[i], "echo", 5) == 0)
			ft_echo(argc, argv, shell);
		else if (strncmp(argv[i], "cd", 3) == 0)
			ft_cd(argc, argv, shell);
		else if (strncmp(argv[i], "env", 4) == 0)
			ft_env(shell.env.current);
		else if (strncmp(argv[i], "exit", 5) == 0)
			ft_exit(argc, argv, shell.env.current);
		else if (strncmp(argv[i], "export", 7) == 0)
			ft_export(argc, argv, shell);
		else if (strncmp(argv[i], "unset", 6) == 0)
			ft_unset (argc, argv, shell.env.current);
	}
	return (0);
}

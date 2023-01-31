#include <unistd.h>
#include <stdio.h>

#include "main_proc.h"

void	ft_cd(int argc, char **argv, t_shell shell)
{
	shell.cd.i = -1;
	ft_env(shell.env.current);
	printf("\n\n\n\n\n");
	shell.cd.oldpwd = ft_pwd();
	shell.cd.s = chdir(argv[2]);
	while (shell.env.current[++shell.cd.i])
	{
		if (strncmp(shell.env.current[shell.cd.i], "OLDPWD", 6) == 0)
		{
				shell.cd.pwd = ft_strjoin("OLDPWD=", shell.cd.oldpwd);
				shell.env.current[shell.cd.i] = shell.cd.pwd;
		}
		if (strncmp(shell.env.current[shell.cd.i], "PWD", 3) == 0)
		{
			shell.cd.pwd2 = ft_strjoin("PWD=", ft_pwd());
			shell.env.current[shell.cd.i] = shell.cd.pwd2;
		}
	}
	ft_env(shell.env.current);
}
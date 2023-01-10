#include <unistd.h>
#include <stdio.h>

#include "main_proc.h"

int ft_exit(t_shell *shell)
{
    int i;

    i = -1;
    while(env.current.)
    printf("%s[i]\n", shell->env.current);
    return(0);
}

int ft_pwd()
{
     char h[1049];

    printf("%s\n", getcwd(h,sizeof(h)));
    return(0);
}

void	get_env(char **envp, t_shell *env_list)
{
	int	c;

	c = -1;
	env_list->env.current = (char **)malloc(sizeof(char *) * 40000000);
	while (envp[++c])
	{
		env_list->env.current[c] = ft_strdup(envp[c]);
	}
}

int main(int argc,char **argv, char **envp)
{
    int i;
    t_shell shell;

    get_env(envp, &shell);
    i = -1;
    while(argv[++i])
    {
    if(strncmp(argv[i],"pwd",4) == 0)
        ft_pwd();
    if(strncmp(argv[i],"exit",5) == 0)
    {
        ft_exit(&shell);
    }
    }
    return(0);
}
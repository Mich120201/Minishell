#include <unistd.h>
#include <stdio.h>

#include "main_proc.h"

size_t	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}


char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

//     void ft_cd(int argc, char **argv, char **envp)
// {
//     int i;

//     i = -1;

//     void *oldpwd;
//     void *pwd;

//     oldpwd = ft_pwd();

//     while(strncmp(envp[++i])
//         if(strncmp(envp[i], "pwd", 4) == 0)

//     int s;
//     i = 2;
//     s = chdir(argv[2]);
//     printf("%d", s);
// }

void ft_echo(int argc, char **argv)
{
    int i;
    int j;

    i = 2;
    j = 0;
    while (j < 1)
    {
        if (argc == 2)
            printf("\n");
        else if(strncmp(argv[i], "-n", 3) == 0)
        {
            i++;
               while((strncmp(argv[i], "-n", 3) == 0))
                    i++;
               while(argv[i])
                {
                    printf("%s ", argv[i]);
                    i++;
                } 
        }
        else
        {
            while(argv[i])
            {
                printf("%s\n", argv[i]);
                i++;
            } 
        }
        j++;
    }
}

// int ft_exit(t_shell *shell)
// {

//     printf("exit");
//     return(0);
//     // int i;

//     // i = -1;
//     // while(shell->env.current)
//     // printf("%s[i]\n", shell->env.current);
//     // return(0);
// }

void ft_pwd()
{
     char h[1049];

    printf("%s\n", getcwd(h,sizeof(h)));
}

void ft_env(char **current)
{
    int i;

    i = -1;

    while(current[++i])
    {
        if(strchr(current[i],'=') != NULL)
            printf("%s\n", current[i]);
    }
}

// void ft_env(t_shell shell)
// {
//     int i;

//     i = -1;

//     char *s;
//     s = *envp;

//     while(envp[++i])
//     {
//         if(strchr(envp[i],'=') != NULL)
//             printf("%s\n", envp[i]);
//     }
// }


void	get_env(char **envp, t_shell *env_list)
{
	int	c;
    int i;

	c = -1;
    i = -1;
    while (envp[++i])
        ;
	env_list->env.current = (char **)malloc(sizeof(char *) * (i + 1));
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
    // if(strncmp(argv[i],"exit",5) == 0)
    //     ft_exit(&shell);
    if(strncmp(argv[i],"echo",5) == 0)
        ft_echo(argc, argv);
    // if(strncmp(argv[i],"cd",3) == 0)
    //     ft_cd(argc, argv,envp);
    if(strncmp(argv[i],"env",4) == 0)
        ft_env(shell.env.current);
    // {
    //     ft_exit(&shell);
    // }
    }
    return(0);
}
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

//     void ft_cd(int argc, char **argv, char **envp)
// {
//     int i;

//     i = -1;

//     char *oldpwd;
//     char *pwd;

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


// void ft_pwd()
// {
//      char h[1049];

//     printf("%s\n", getcwd(h,sizeof(h)));
// }

void ft_exit(int argc, char **argv,char **current)
{
    int i;

    i = -1;
    
    ft_env(current);
    while(current[++i])
    {
        if(strncmp(current[i],"SHLVL=2", 8) == 0)
        {
            // ft_env(current);
            printf("kadhiuhd");
            exit(0);
        }
        else
        {
            printf("iijdisjdopfd");
            exit(0);
        }
    }
    exit(0);
}

char *ft_pwd()
{
    char *s;

    s=(char *)malloc(100*sizeof(char));

    printf("%s\n", getcwd(s,100));
    return(s);
}

void ft_cd(int argc, char **argv,char **current)
{
    char *oldpwd;
    char *newpwd;
    int i;
    char *name;
    
    name = "OLDPWD=";

    i = -1;
    oldpwd = ft_pwd();

    ft_env(current);
    printf("\n\n\n\n");
    int s;
    s = chdir(argv[2]);
    while(current[++i])
    {
        if(strncmp(current[i],"OLDPWD",6) == 0)
            {
                current[i] = name;
                // current[i] = oldpwd;
                newpwd = ft_pwd();
            }
    }
    printf("%d\n", s);
    // newpwd = ft_pwd();
    ft_env(current);
    
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
    else if(strncmp(argv[i],"echo",5) == 0)
        ft_echo(argc, argv);
    else if(strncmp(argv[i],"cd",3) == 0)
        ft_cd(argc, argv,shell.env.current);
    else if(strncmp(argv[i],"env",4) == 0)
        ft_env(shell.env.current);
     else if(strncmp(argv[i],"exit",5) == 0)
        ft_exit(argc,argv,shell.env.current);
    // else
    //     printf("command not found");
    // {
    //     ft_exit(&shell);
    // }
    }
    return(0);
}
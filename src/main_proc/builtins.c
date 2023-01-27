#include <unistd.h>
#include <stdio.h>

#include "main_proc.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = (char *)b;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (b);
}


int	ft_strchrp(const char *s, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return (i);
		i++;
	}
	if (s[i] == find)
		return (i);
	return (1);
}


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	*b2;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (b1[i] != b2[i] || b1[i] == 0 || b2[i] == 0)
			return (b1[i] - b2[i]);
		i++;
	}
	return (0);
}

void	arr_add_back(char **env, char *copy)
{
	int	i;
	int	l;

	i = -1;
	while (env[++i])
		;
	l = i + 1;
	env = (char **)realloc(env, l);
	env[i] = ft_strdup(copy);
	env[l] = NULL;
}

size_t	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!str)
			return (NULL);
		i = 0;
		j = 0;
		while (s1[i])
			str[j++] = s1[i++];
		i = 0;
		while (s2[i])
			str[j++] = s2[i++];
		str[j] = 0;
		return (str);
	}
	return (0);
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

void ft_exit(int argc, char **argv,char **current)
{
    int i;
    int j;

    i = -1;
    j = -1;

    ft_env(current);
    while(current[++i])
    {
        if(strncmp(current[i],"SHLVL=", 6) == 0)
        {
            j = current[i][6] - '0';
            j--;
            j += '0';
            current[i][6] = j;
            exit(0);
        }
    }
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
    char *pwd;
    int i;
    char *name;
    char *pwd2;

    pwd2 = "PWD=";
        
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
                pwd = ft_strjoin(name, oldpwd);
                current[i] = pwd;
            }
        if(strncmp(current[i],"PWD",3) == 0)
        {
            pwd2 = ft_strjoin(pwd2, ft_pwd());
            current[i] = pwd2;
        }
    }
    printf("\n\n\n\n%d\n", s);
    ft_env(current);
        
}

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

void    ft_export(int argc, char **argv,char **current)
{
    int  i;
    int  j;
    int  position;
    char	**sort_env;

    i = -1;
    j = -1;
    ft_env(current);
    if (argc == 2)
    {
        //printf("ciao\n");
        sort_env = sort(current);
		i = -1;
		while (sort_env[++i])
			printf("declare -x %s\n", sort_env[i]);
    }
    while(current[++i])
    {
        position = ft_strchrp(current[i], '=');
        if (ft_strncmp(current[i], argv[2], position + 1) == 0)
        {
            current[i] = argv[2];
            j = 0;
        }
    }
    if(j == -1)
    {
        current[i] = argv[2];
        current[i + 1] = NULL;
    }
    ft_env(current);
    return ;
}

void       ft_unset(int argc, char **argv,char **current)
{   
    int i;
    int position;

    i = -1;
    ft_env(current);
    while(current[++i])
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

void	get_env(char **envp, t_shell *env_list)
{
	int	c;
    int i;

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
        else if(strncmp(argv[i],"echo",5) == 0)
            ft_echo(argc, argv);
        else if(strncmp(argv[i],"cd",3) == 0)
            ft_cd(argc, argv,shell.env.current);
        else if(strncmp(argv[i],"env",4) == 0)
            ft_env(shell.env.current);
        else if(strncmp(argv[i],"exit",5) == 0)
            ft_exit(argc,argv,shell.env.current);
        else if(strncmp(argv[i],"export",7) == 0)
            ft_export(argc, argv, shell.env.current);
        else if(strncmp(argv[i],"unset",6) == 0)
            ft_unset(argc, argv, shell.env.current);
    }
    return(0);
}
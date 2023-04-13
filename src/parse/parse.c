/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:02:56 by mvolpi            #+#    #+#             */
/*   Updated: 2023/04/13 12:31:06 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

size_t	ft_strlenr(const char *s)
{
	int	l;
	int	c;

	l = -1;
	c = 0;
	while (s[++l] != '\0')
	{
		if (is_red(s[l]) == 1)
			c++;
	}
	return (c);
}

int	check_pipe(char *string)
{
	size_t	i;

	i = ft_strlen(string);
	if (i > 1)
	{
		printf("minishell: double pipe is not allowed\n");
		g_exit = 2;
	}
	return (g_exit);
}

int	check_redirection(char *string, t_shell *shell)
{
	size_t	i;

	if (shell->check_redirection == 0)
		shell->check_redirection = 1;
	else
	{
		printf("minishell: syntax error near unexpected token redirection\n");
		return (g_exit = 2);
	}
	i = ft_strlenr(string);
	if (i > 2)
	{
		printf("minishell: syntax error near unexpected token redirection\n");
		return (g_exit = 258);
	}
	if (i > 1 && (string[0] == '>' && string[0] != string[1]))
	{
		printf("minishell: redirection >< is not allowed\n");
		return (g_exit = 2);
	}
	return (g_exit);
}

int	check_quote(char *string)
{
	size_t	i;
	int		count_quote;
	int		count_single;

	i = 0;
	count_quote = 0;
	count_single = 0;
	count_quote = double_count(string, i, count_quote);
	count_single = single_count(string, i, count_single);
	if (count_quote % 2 != 0 || count_single % 2 != 0)
	{
		printf("minishell: quote not closed\n");
		g_exit = 2;
	}
	return (g_exit);
}

int	check_parameter(char *string, char c, t_shell *shell)
{
	if (c == '|')
		return (g_exit = check_pipe(string));
	if (c == '<' || c == '>')
		return (g_exit = check_redirection(string, shell));
	return (g_exit);
}

int	parse(char **string, t_shell *shell)
{
	int	i;

	g_exit = control(string[0]);
	if (string[0][0] == '|')
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		g_exit = 258;
	}
	else
	{
		i = -1;
		while (string[++i])
		{
			if (string[i][0] == '|' || string[i][0] == '<'
				|| string[i][0] == '>')
			{
				g_exit = check_parameter(string[i], string[i][0], shell);
				if (g_exit != 0)
					return (g_exit);
			}
		}
		g_exit = check_quote(shell->lst.input);
	}
	return (g_exit);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:02:56 by mvolpi            #+#    #+#             */
/*   Updated: 2023/02/02 17:57:24 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

int	check_redirection(char *string)
{
	size_t	i;

	i = ft_strlen(string);
	if (i > 2)
	{
		printf("minishell: syntax error near unexpected token redirection\n");
		g_exit = 258;
	}
	if (i > 1 && (string[0] == '>' && string[0] != string[1]))
	{
		printf("minishell: redirection >< is not allowed\n");
		g_exit = 2;
	}
	return (g_exit);
}

int	check_quote(char *string)
{
	size_t i;
	int	count_quote;
	int count_single;

	i = 0;
	count_quote = 0;
	count_single = 0;
	while(string[i])
	{
		if (string[i] == 34)
			count_quote++;
		else if (string[i] == 39)
			count_single++;
		i++;
	}
	i = ft_strlen(string);
	if (i == 2)
	{
		printf("minishell: command not found\n");
		g_exit = 127;
	}
	if (count_quote % 2 != 0 || count_single % 2 != 0)
	{
		printf("minishell: quote not closed\n");
		g_exit = 2;
	}
	return (g_exit);
}

int	check_parameter(char *string, char c)
{
	if (c == '|')
		return (g_exit = check_pipe(string));
	if (c == '<' || c == '>')
		return (g_exit = check_redirection(string));
	return (g_exit);
}

int	parse(char **string)
{
	int	i;

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
				|| string[i][0] == '>' || string[i][0] == 34
				|| string[i][0] == 39)
			{
				g_exit = check_parameter(string[i], string[i][0]);
				return (g_exit);
			}
			g_exit = check_quote(string[i]);
		}
	}
	return (g_exit);
}

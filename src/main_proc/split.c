/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:02:27 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/12 11:09:15 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_proc.h"

int	is_separator(char c)
{
	if (c == '\0')
		return (1);
	else if (c == '|')
		return (2);
	else if (c == '>')
		return (3);
	else if (c == '<')
		return (4);
	else if (c == '\0')
		return (1);
	else if (c == 34 || c == 39)
		return (-1);
	return (0);
}

int	words(char *str)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i] == -1))
			w++;
		if (is_separator(str[i] == 2))
			w++;
		if (is_separator(str[i] == 3))
			w++;
		if (is_separator(str[i] == 4))
			w++;
		if (is_separator(str[i]) == 0
			&& is_separator(str[i + 1]) == 2)
			w++;
		i++;
	}
	return (w);
}

int	write_word(char *dest, char *src)
{
	int	i;
	int	c;
	int	p;

	i = 0;
	p = 0;
	c = 0;
	// printf("entrata funzione\n");
	// printf("src = %c\n", src[i]);
	if (is_separator(src[i]) == 0)
	{
		while (is_separator(src[i]) == 0)
		{
			dest[i] = src[i];
			i++;
			c++;
		}
		if (is_separator(src[i]) == -1)
		{
			dest[i] = src[i];
			i++;
			if (is_separator(src[i]) == -1)
			{
				dest[i] = src[i];
				i++;
			}
			while (is_separator(src[i]) != -1)
			{
				dest[i] = src[i];
				i++;
				c++;
			}
			dest[i] = src[i];
			i++;
			if (is_separator(src[i]) == -1)
			{
				dest[i] = src[i];
				i++;
			}
			c += 2;
		}
	}
	else if (is_separator(src[i]) == -1)
	{
		dest[i] = src[i];
		i++;
		if (is_separator(src[i]) == -1)
		{
			dest[i] = src[i];
			i++;
			c++;
		}
		while (is_separator(src[i]) != -1)
		{
			dest[i] = src[i];
			i++;
			c++;
		}
		dest[i] = src[i];
		i++;
		if (is_separator(src[i]) == -1)
		{
			dest[i] = src[i];
			i++;
			c++;
		}
		c += 2;
		if (is_separator(src[i]) == 0)
		{
			while (is_separator(src[i]) == 0)
			{
				dest[i] = src[i];
				i++;
				c++;
			}
		}
	}
	dest[i] = '\0';
	return (c);
}

int	write_split(char **split, char *str)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i]) > 0)
		{
			split[w] = (char *)malloc(sizeof(char) * (3));
			i = control_sep(str, split[w], i);
			w++;
		}
		else
		{
			j = 0;
			while (is_separator(str[i + j]) <= 0)
				j++;
			split[w] = (char *)malloc(sizeof(char) * (j + 1));
			i += write_word(split[w], str + i);
			w++;
		}
	}
	return (1);
}

char	**split_cmd(char const *s)
{
	int		w;
	char	**rtn;

	if (!s)
		return (NULL);
	w = words((char *)s);
	rtn = (char **)malloc(sizeof(char *) * (w + 1));
	if (!rtn)
		return (NULL);
	if (!(write_split(rtn, (char *) s)))
	{
		w = -1;
		while (rtn + ++w)
			free(rtn + w);
		free(rtn);
	}
	rtn[w] = 0;
	return (rtn);
}

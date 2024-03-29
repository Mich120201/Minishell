/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:44:30 by mvolpi            #+#    #+#             */
/*   Updated: 2023/04/12 11:21:39 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

int	ft_is_separator(char c, char cr)
{
	if (c == cr)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_words(char *str, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (ft_is_separator(str[i], c) == 0
			&& ft_is_separator(str[i + 1], c) == 1)
			w++;
		i++;
	}
	return (w);
}

void	ft_write_word(char *dest, char *src, char c)
{
	int	i;

	i = 0;
	while (ft_is_separator(src[i], c) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_write_split(char **split, char *str, char c)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (ft_is_separator(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_is_separator(str[i + j], c) == 0)
				j++;
			split[w] = (char *)malloc(sizeof(char) * (j + 1));
			if (!(split[w]))
				return (0);
			ft_write_word(split[w], str + i, c);
			i += j;
			w++;
		}
	}
	split[w] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		w;
	char	**rtn;

	if (!s)
		return (NULL);
	w = ft_words((char *)s, c);
	rtn = (char **)malloc(sizeof(char *) * (w + 1));
	if (!rtn)
		return (NULL);
	if (!(ft_write_split(rtn, (char *) s, c)))
	{
		w = -1;
		while (rtn[w])
			free(rtn[w]);
		free(rtn);
	}
	rtn[w] = 0;
	return (rtn);
}

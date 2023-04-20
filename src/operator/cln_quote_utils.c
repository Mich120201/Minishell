/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cln_quote_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbellucc <vbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:08:37 by mich              #+#    #+#             */
/*   Updated: 2023/04/20 10:30:10 by vbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	loop_quote(t_shell *shell, int i)
{
	i = -1;
	while (shell->lst.input[++i])
	{
		if (shell->lst.input[i] == 34)
		{
			while (shell->lst.input[++i] != 34)
			{
				if (shell->lst.input[i] == ' ')
					shell->lst.input[i] = '~';
			}
		}
		if (shell->lst.input[i] == 39)
		{
			while (shell->lst.input[++i] != 39)
			{
				if (shell->lst.input[i] == ' ' && \
					shell->lst.input[i + 1] == '$')
					shell->lst.input[i] = '\a';
				else if (shell->lst.input[i] == ' ')
					shell->lst.input[i] = '~';
			}
		}
	}
	return (i);
}

void	change_input(t_shell *shell, char *str, int j)
{
	free(shell->lst.input);
	shell->lst.input = NULL;
	shell->lst.input = ft_strdup(str);
	shell->lst.input[j] = '\0';
}

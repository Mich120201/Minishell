/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:28:13 by mvolpi            #+#    #+#             */
/*   Updated: 2023/04/18 14:48:25 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	delete_op(t_shell *shell)
{
	int	i;
	int	check_quote;

	i = -1;
	check_quote = 0;
	while (shell->lst.input[++i])
	{
		if (is_separator(shell->lst.input[i]) == -1)
		{
			if (check_quote == 0)
				check_quote = 1;
			else
				check_quote = 0;
		}
		if (is_separator(shell->lst.input[i]) > 1 && check_quote == 0)
			shell->lst.input[i] = ' ';
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:24:46 by mich              #+#    #+#             */
/*   Updated: 2023/04/15 17:31:00 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	check_double_red(t_shell *shell, char *input, int i)
{
	if (input[i] == '<' && input[i + 1] == '<')
	{
		if (shell->redirection_id != 0 && shell->redirection_id != 4)
			shell->check_mix_red = 1;
		shell->redirection_id = 4;
		return(i+=2);
	}
	else if (input[i] == '>' && input[i + 1] == '>')
	{
		printf("hello\n");
		if (shell->redirection_id != 0 && shell->redirection_id != 3)
			shell->check_mix_red = 1;
		shell->redirection_id = 3;
		return(i+=2);
	}
	return(i);
}

void	check_single_red(t_shell *shell, char *input, int i)
{
	if (input[i] == '<')
	{
		if (shell->redirection_id != 0 && shell->redirection_id != 2)
			shell->check_mix_red = 1;
		shell->redirection_id = 2;
	}
	else if (input[i] == '>')
	{
		printf("ciao2\n");
		if (shell->redirection_id != 0 && shell->redirection_id != 1)
			shell->check_mix_red = 1;
		shell->redirection_id = 1;
	}
}

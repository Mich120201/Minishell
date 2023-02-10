/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:17:02 by mich              #+#    #+#             */
/*   Updated: 2023/02/09 16:59:24 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	ft_exit(char **current, t_shell *shell)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (current[++i])
	{
		if (strncmp(current[i], "SHLVL=", 6) == 0)
		{
			j = current[i][6] - '0';
			j--;
			j += '0';
			current[i][6] = j;
			free_struct(shell);
			free_struct2(shell);
			rl_clear_history();
			exit(printf("exit\n"));
		}
	}
}

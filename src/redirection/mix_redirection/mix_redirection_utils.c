/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_redirection_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:45:20 by mich              #+#    #+#             */
/*   Updated: 2023/04/18 14:45:38 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mix_redirection.h"

void	print_cat_array(t_shell *shell)
{
	if (shell->here_cat == 1)
	{
		shell->echo.i = -1;
		while (shell->lst.cat_array[++shell->echo.i])
			printf("%s\n", shell->lst.cat_array[shell->echo.i]);
		ft_sarfree(shell->lst.cat_array, ft_sarsize(shell->lst.cat_array));
	}
	shell->redirection_out = dup(STDOUT_FILENO);
	close(shell->redirection.fd);
	shell->redirection.i++;
}

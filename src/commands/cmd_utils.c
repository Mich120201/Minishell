/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:12:50 by mich              #+#    #+#             */
/*   Updated: 2023/03/23 13:59:33 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	control_cmd(t_shell *shell)
{
	if (ft_strncmp("./minishell", shell->lst.executor[0], 12) == 0)
	{
		minishell_case(shell);
		return (1);
	}
	if (ft_strncmp("/bin/", shell->lst.executor[0], 5) == 0)
	{
		ab_path(shell);
		return (1);
	}
	return (0);
}

int	control_path(t_shell *shell)
{
	int		c;
	int		k;
	char	**path;
	char	*str;

	c = -1;
	k = -1;
	while (shell->env.current[++c])
	{
		if (ft_strncmp(shell->env.current[c], "PATH=", \
			5) == 0)
		{
			path = ft_split(shell->env.current[c] + 5, ':');
			while (path[++k])
			{
				str = ft_strjoin(path[k], "/");
				str = ft_strjoinfree(str, ft_strdup(shell->lst.executor[0]));
				if (!access(str, F_OK))
				{
					ft_fork(shell, str);
					ft_sarfree(path, ft_sarsize(path));
					return (1);
				}
				free(str);
			}
		}
	}
	ft_sarfree(path, ft_sarsize(path));
	return (0);
}

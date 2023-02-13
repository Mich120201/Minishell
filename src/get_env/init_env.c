/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzodimascia <lorenzodimascia@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:20:28 by mvolpi            #+#    #+#             */
/*   Updated: 2023/02/13 15:59:12 by lorenzodima      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_env.h"

/**
 * @brief Takes the working enviroment and save it in a list
 * 
 * @param envp array of the enviroment that already exists in
 * the computer as argv that we copy to our list with ft_strdup
 * @param env_list created list that we use to save the enviroment
 */
void	get_env(char **envp, t_shell *env_list)
{
	int	c;
	int	i;

	c = -1;
	i = ft_count_arraystr(envp);
	env_list->env.current = (char **)malloc(sizeof(char *) * (i + 1));
	while (++c < i)
	{
		env_list->env.current[c] = ft_strdup(envp[c]);
	}
	env_list->env.current[c] = NULL;
}

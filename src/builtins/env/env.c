/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzodimascia <lorenzodimascia@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:15:42 by mich              #+#    #+#             */
/*   Updated: 2023/02/13 15:50:31 by lorenzodima      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	ft_env(char **current)
{
	int	i;

	i = -1;
	while (current[++i])
	{
		if (strchr(current[i], '=') != NULL)
			printf("%s\n", current[i]);
	}
	current[i] = NULL;
}

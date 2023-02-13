/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzodimascia <lorenzodimascia@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:24:24 by mich              #+#    #+#             */
/*   Updated: 2023/02/13 15:03:15 by lorenzodima      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

char	*ft_pwd(void)
{
	char	*s;

	s = (char *)malloc(100 * sizeof(char));
	getcwd(s, 100);
	return (s);
}

void	pwd(void)
{
	char	*s;

	s = (char *)malloc(100 * sizeof(char));
	printf("%s\n", getcwd(s, 100));
	free(s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:48:52 by mich              #+#    #+#             */
/*   Updated: 2023/04/18 14:52:02 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_H
# define QUOTE_H

# include "../src.h"

/*clean_quote.c*/
void	clean_parse(t_shell *shell);
/*cln_quote_urils.c*/
int		loop_quote(t_shell *shell, int i);
void	change_input(t_shell *shell, char *str, int j);

#endif

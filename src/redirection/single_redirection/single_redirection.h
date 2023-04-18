/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_redirection.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:34:33 by mich              #+#    #+#             */
/*   Updated: 2023/04/18 14:52:11 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGLE_REDIRECTION_H
# define SINGLE_REDIRECTION_H

# include "../../src.h"

/*redirection_utils.c*/
int		print_here_doc(t_shell *shell, char *redirection);
int		print_heredoc_cat(t_shell *shell, int j);
/*redirection.c*/
void	red_out(int count_redirection, t_shell *shell, \
	int count_delete_str, int j);
void	red_inp(char	*redirection, t_shell *shell);
void	append(t_shell *shell, int j, \
	int count_redirection, int count_delete_str);
void	here_doc(char *redirection, t_shell *shell);
void	here_doc_cat(char *redirection, t_shell *shell);


#endif

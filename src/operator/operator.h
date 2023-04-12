/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:18:24 by mich              #+#    #+#             */
/*   Updated: 2023/04/12 11:05:36 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include "../src.h"

/*check_op.c*/
void	redirection(int c, t_shell *shell);
int		check_red(char *input, t_shell *shell, int i);
void	control_exp(t_shell *shell);
int		check_operator(t_shell *shell);
/*clean_quote.c*/
void	clean_parse(t_shell *shell);
void	clean_all_quote(t_shell *shell);
void	clean_single(t_shell *shell);
void	clean_double(t_shell *shell);
/*delete.c*/
int		is_sep(char c);
int		control_q(int q, int d);
int		control_qt(int q, int d, int s);
int		cont_quote(t_shell *shell, int i);
void	delete_op(t_shell *shell);
/*redirection.c*/
void	red_out(char *redirection, int count_redirection, t_shell *shell, \
	int count_delete_str, int j);
void	red_inp(char	*redirection);
void	append(char *redirection);
void	here_doc(char *redirection, t_shell *shell);
void	here_doc_cat(char *redirection, t_shell *shell);
/*utils.c*/
int		double_count(char *string, int i, int count_quote);
int		single_count(char *string, int i, int count_single);
void	change_word(t_shell *shell, int i, int pos);

#endif

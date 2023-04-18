/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:18:24 by mich              #+#    #+#             */
/*   Updated: 2023/04/18 14:48:12 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include "../src.h"

/*check_op_utils.c*/
void	check_double_red(t_shell *shell, char *input, int i);
void	check_single_red(t_shell *shell, char *input, int i);
/*check_op.c*/
void	redirection(t_shell *shell);
int		check_red(char *input, t_shell *shell, int i);
void	control_exp(t_shell *shell);
int		check_operator(t_shell *shell);
/*clean_quote.c*/
void	clean_parse(t_shell *shell);
void	clean_all_quote(t_shell *shell);
void	clean_single(t_shell *shell);
void	clean_double(t_shell *shell);
/*cln_quote_utils.c*/
int		loop_quote(t_shell *shell, int i);
void	change_input(t_shell *shell, char *str, int j);
/*delete.c*/
void	delete_op(t_shell *shell);
/*utils.c*/
int		double_count(char *string, int i, int count_quote);
int		single_count(char *string, int i, int count_single);
void	change_word(t_shell *shell, int i, int pos);
#endif

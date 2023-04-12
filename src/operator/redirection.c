/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:32:54 by mich              #+#    #+#             */
/*   Updated: 2023/04/12 11:19:53 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	red_out(char *redirection, int count_redirection, t_shell *shell, int count_delete_str, int j)
{
	int	i;
	int	k;

	if (j != count_redirection)
	{
		k = open(redirection, O_CREAT |
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		shell->lst.delete_str[count_delete_str] = ft_strdup(redirection);
		return ;
	}
	else
	{
		i = open(redirection, O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		shell->lst.delete_str[count_delete_str] = ft_strdup(redirection);
		dup2(i, STDOUT_FILENO);
		(void)k;
		return ;
	}
}

void	red_inp(char	*redirection, t_shell *shell)
{
	int	i;

	i = open(redirection, O_RDONLY);
	dup2(i, STDIN_FILENO);
	shell->lst.delete_str[0] = ft_strdup(redirection);
}

void	append(char *redirection, t_shell *shell, int j, int count_redirection, int count_delete_str)
{
	int	i;
	int k;

	if (j != count_redirection)
	{
		k = open(redirection, O_CREAT |
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		shell->lst.delete_str[count_delete_str] = ft_strdup(redirection);
		//ft_sarprint(shell->lst.delete_str);
		return ;
	}
	else
	{
		i = open(redirection, O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		shell->lst.delete_str[0] = ft_strdup(redirection);
		dup2(i, STDOUT_FILENO);
		(void)k;
		return ;
	}
}

void	here_doc(char *redirection, t_shell *shell)
{
	int		i;

	if (shell->here_pipe == 1 || shell->check_mix_red == 1)
		dup2(shell->stdout, STDOUT_FILENO);
	while (1)
	{
		shell->lst.doc = readline("> ");
		i = -1;
		while (redirection[++i])
			;
		if (ft_strncmp(redirection, shell->lst.doc, i + 1) == 0)
			break ;
		free(shell->lst.doc);
		shell->lst.doc = NULL;
	}
	free(shell->lst.doc);
	shell->lst.doc = NULL;
	if (shell->here_pipe == 1)
		dup2(shell->out_pipe, STDOUT_FILENO);
	if (shell->check_mix_red == 1)
	{
		dup2(shell->redirection_out, STDOUT_FILENO);
		return ;
	}
	//shell->lst.delete_str[0] = ft_strdup(redirection);
}

void	here_doc_cat(char *redirection, t_shell *shell)
{
	int	i;
	int	j;

	shell->lst.cat_array = (char **)malloc(sizeof(char *) * 40000);
	j = 0;
	if (shell->here_pipe == 1)
		dup2(shell->stdout, STDOUT_FILENO);
	while (1)
	{
		shell->lst.doc = readline("> ");
		i = -1;
		while (redirection[++i])
			;
		if (ft_strncmp(redirection, shell->lst.doc, i + 1) == 0)
			break ;
		shell->lst.cat_array[j] = ft_strdup(shell->lst.doc);
		j++;
		free(shell->lst.doc);
		shell->lst.doc = NULL;
	}
	shell->lst.cat_array[j] = NULL;
	j = -1;
	if (shell->here_pipe == 1)
		dup2(shell->out_pipe, STDOUT_FILENO);
	if (shell->check_mix_red == 1)
	{
		free(shell->lst.doc);
		shell->lst.doc = NULL;
		shell->here_cat = 1;
		return ;
	}
	while (shell->lst.cat_array[++j])
		printf("%s\n", shell->lst.cat_array[j]);
	free(shell->lst.doc);
	shell->lst.doc = NULL;
}

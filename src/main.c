/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:15:53 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/31 17:05:29 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

/**
 * @brief function that takes the structure of structures to be freed,
 * iterates cell by cell to be free and then does a general free of the
 * array
 * 
 * @param shell the structure of structures
 */
void	free_struct(t_shell *shell)
{
	int	i;

	i = -1;
	while (shell->env.current[++i])
		free(shell->env.current[i]);
	free(shell->env.current);
	free(shell->lst.input);
	i = -1;
	while (shell->lst.split[++i])
		free(shell->lst.split[i]);
	free(shell->lst.split);
}

int	check_error_cod(t_shell *shell)
{
	int	i;

	i = -1;
	shell->lst.error = ft_split(shell->lst.input, ' ');
	while (shell->lst.error[++i])
	{
		if (ft_strncmp(shell->lst.error[i], "$?", 3) == 0)
		{
			printf("%d: command not found\n", g_exit);
			g_exit = parse(shell->lst.split);
			return (g_exit);
		}
		else
		{
			g_exit = 0;
			g_exit = parse(shell->lst.split);
		}
	}
	return (g_exit);
}

/**
 * @brief the start of the program that checks for errors,
 * saves the enviroment in a list and sets up a new prompt
 * waiting for a command and for now if in input there is
 * exit the program exit with no errors
 * 
 * @param argc number of argument in input from the teminal with which
 * we check that to start the programm only ./minishell is given in input
 * @param argv counter of argument in input from the terminal that
 * we set up at void because it is not needed within the program but
 * we need to call the force to have envp
 * @param envp an array where we have all the enviroment variables and we
 * need to save in a list where we can modify each variable to our liking
 * @return int return a 0 for now
 */
int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argv;
	g_exit = 0;
	if (argc > 1)
		exit(printf("Error, there are too many argument!!"));
	get_env(envp, &shell);
	while (1)
	{
		shell.lst.input = readline("minishell: ");
		shell.lst.split = split_cmd(shell.lst.input);
		if (ft_strncmp(shell.lst.input, "", 1))
			add_history(shell.lst.input);
		if (ft_strncmp(shell.lst.input, "exit", 4) == 0)
		{
			free_struct(&shell);
			exit(0);
		}
		g_exit = check_error_cod(&shell);
	}
	return (0);
}

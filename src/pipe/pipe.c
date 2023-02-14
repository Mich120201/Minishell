/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:06:58 by mich              #+#    #+#             */
/*   Updated: 2023/02/14 17:07:52 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void    ft_pipe()
{
	#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
    int fd[2];
    pid_t pid;

    // Crea la pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Crea il processo figlio
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Processo figlio
        // Chiudi il lato di lettura della pipe
        close(fd[0]);

        // Sostituisci lo standard output con il lato di scrittura della pipe
        dup2(fd[1], STDOUT_FILENO);

        // Esegui il primo programma
        char *cmd1[] = {"ls", "-l", NULL};
        execve("/bin/ls", cmd1, NULL);
        // Se l'esecuzione arriva qui, significa che qualcosa è andato storto
        perror("execve");
        exit(EXIT_FAILURE);
    } else { // Processo padre
        // Chiudi il lato di scrittura della pipe
        close(fd[1]);

        // Sostituisci lo standard input con il lato di lettura della pipe
        dup2(fd[0], STDIN_FILENO);

        // Esegui il secondo programma
        char *cmd2[] = {"wc", "-l", NULL};
        execve("/usr/bin/wc", cmd2, NULL);

        // Se l'esecuzione arriva qui, significa che qualcosa è andato storto
        perror("execve");
        exit(EXIT_FAILURE);
    }

    // Questo codice non viene mai eseguito
    return 0;
}

    printf("iudfndnjdnklcakn");
}

int	check_single_pipe(char *str)
{
	int	i;
	int	k;
	int l;

	i = -1;
	k = -1;
	l = 0;

	while(str[++k])
		;
	while(++i < k)
	{
		if(str[i] == '|')
			l = 1;
	}
	if(l == 1)
	{
		printf("pipe");
		ft_pipe();
	}
	else
		{
			printf("non pipe");
			return(0);
		}
}

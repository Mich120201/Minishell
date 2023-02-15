#include "commands.h"

int	commands(t_shell *shell)
{
	int status;

    pid_t pid = fork();
    if (pid == 0) 
	{
        // child process
        if (execve(ft_strjoin("/bin/", shell->lst.executor[0]),shell->lst.executor, NULL) == -1) {
            perror("execve failed");
            exit(EXIT_FAILURE);
    }
    } 
	else if (pid > 0) 
	{
        // parent process
		printf("Child process created with PID %d\n", pid);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
    	{
			printf("Il processo figlio ha terminato con codice %d\n", WEXITSTATUS(status));
			return(0);
        }
    }
	else 
	{
        // fork failed
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
	return(1);
}

   

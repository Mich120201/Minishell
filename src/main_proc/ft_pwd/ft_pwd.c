#include <unistd.h>
#include <stdio.h>

#include "main_proc.h"


char	*ft_pwd(void)
{
	char	*s;

	s = (char *)malloc(100 * sizeof(char));
	printf("%s\n", getcwd(s, 100));
	return (s);
}
#include "../h_file/libft.h"

void    ft_free_str(char **str)
{
    int i;
    int j;

    i = -1;
    if (!str)
        return ;
    j = ft_count_arraystr(str);
    while(++i < j)
    {
        if (str[i])
        {
            free(str[i]);
            str[i] = NULL;
        }
    }
    free(str);
    str = NULL;
}
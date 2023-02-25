
#include "../include/pipex.h"

void	ft_exit(t_data *dta)
{
	if (dta->error > 0)
		exit(1);
	exit(0);
}

void	printf_error(t_data *dta, char *str)
{
	ft_printf("%s\n", str);
	dta->error = 1;
	ft_exit(dta);
}

void    print_tab(char **tab) 
{
    int i;

	i = 0;
	printf("--------------------------------------\n");
	while (tab[i])
	{
		printf("%s\n",tab[i]);
		i++;
	}
	printf("--------------------------------------\n");
}
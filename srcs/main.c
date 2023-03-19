/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:11:23 by bloisel           #+#    #+#             */
/*   Updated: 2023/03/19 16:52:44 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_data(t_data *dta)
{
	int	error;

	error = 0;
}

char	*look_road(char **env, t_data *dta)
{
	while (ft_strncmp("PATH", *env, 4))
	{
		env++;
	}
	dta->envh = *env + 5;
	return (*env + 5);
}

char	*path(char *env, t_data *dta, char* cm)
{
	int 	i;
	int 	j;
	char	*cmd;

	j = 0;
	i = -1;
	while (dta->path[++i])
	{
		cmd = ft_strjoin(dta->path[i], cm);
		if (!access(cmd, F_OK))
		{
			printf("%s\n",cm);
			free(cm);
			return (cmd);
		}
		free(cmd);
	}
	free(cm);
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	t_data	dta;
dta.pid1 = fork();
	printf("ok main\n");
	// dta.pid1 = fork();
	// if (argc != 5)
	// 	printf_error(&dta, "Error\n");
	// dta.infile = open(argv[1], O_RDONLY);
	// dta.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC | 0644);
	// if (dta.infile < 0 || dta.outfile < 0)
	// 	printf_error(&dta, "Error\n");
	look_road(env, &dta);
	dta.path = ft_split(dta.envh, ':');
	dta.cmd1 = path(dta.envh, &dta, ft_strjoin("/", argv[1]));
	// if (!dta.cmd1)
	// {
	// 	exit(1);
	// }
	child(argv, env, &dta);
	// dta.pid1 = fork();
	// dta.cmd2 = path(dta.envh, &dta, ft_strjoin("/", argv[3]));
	// if (!dta.cmd2)
	// {
	// 	exit(1);
	// }
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:11:23 by bloisel           #+#    #+#             */
/*   Updated: 2023/03/21 18:38:41 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_data(t_data *dta)
{
	int	error;

	error = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_data	dta;
	
	init_data(&dta);
	if (argc != 5)
		printf_error(&dta, "Error\n");
	dta.infile = open(argv[1], O_RDONLY);
	// printf("mon nombre argv %s\n",argv);
	printf("nombre argc %d\n",argc);
	dta.outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC |S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (dta.infile < 0 || dta.outfile < 0)
		printf_error(&dta, "Error\n");
	look_road(env, &dta);
	dta.path = ft_split(dta.envh, ':');
	dta.pid1 = fork();
	dta.cmd1 = path(dta.envh, &dta, ft_strjoin("/", argv[2]));
	if (!dta.cmd1)
	{
		exit(1);
	}
	if (dta.pid1 == 0)
	{
		parent_process(argv, env, &dta);
	}
	dta.cmd2 = path(dta.envh, &dta, ft_strjoin("/", argv[3]));
	if (!dta.cmd2)
	{
		exit(1);
	}	
	dta.pid2 = fork();
	if (dta.pid2 == 0)
	{
		child_process(argv, env, &dta);
	}
	waitpid(dta.pid1, NULL, 0);
	waitpid(dta.pid2, NULL, 0);
	printf("ok");	
	return (0);
}

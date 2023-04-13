/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:11:23 by bloisel           #+#    #+#             */
/*   Updated: 2023/04/13 17:52:13 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_data(t_data *dta)
{
	int	error;

	error = 0;
}

int	pathfinder2(char **argv, char **env, t_data *dta)
{
	dta->cmd_ar2 = ft_split(argv[3], ' ');
	dta->cmd2 = path(dta->envh, dta, ft_strjoin("/", dta->cmd_ar2[0]));
	if (!dta->cmd2)
	{
		exit(1);
	}
	second_process(argv, dta, env);
	return (0);
}

int	pathfinder(char **argv, char **env, t_data *dta)
{
	look_road(env, dta);
	dta->path = ft_split(dta->envh, ':');
	dta->cmd_ar = ft_split(argv[2], ' ');
	dta->cmd1 = path(dta->envh, dta, ft_strjoin("/", dta->cmd_ar[0]));
	if (!dta->cmd1)
	{
		exit(1);
	}
	if (pipe(dta->pipefd) < 0)
	{
		perror("Error pipe");
		exit(1);
	}
	dta->pid1 = fork();
	if (dta->pid1 == -1)
		exit(1);
	if (dta->pid1 == 0)
	{
		first_process(argv, dta, env);
	}
	else
	{
		pathfinder2(argv, env, dta);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_data	dta;

	init_data(&dta);
	if (argc != 5)
		printf_error(&dta, "Error\n");
	dta.infile = open(argv[1], O_RDONLY);
	dta.outfile = open(argv[argc -1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (dta.infile < 0 || dta.outfile < 0)
		printf_error(&dta, "Error");
	pathfinder(argv, env, &dta);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:11:23 by bloisel           #+#    #+#             */
/*   Updated: 2023/04/13 15:57:35 by bloisel          ###   ########.fr       */
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
	pid_t pid1;
	int status;

	init_data(&dta);
	if (argc != 5)
		printf_error(&dta, "Error\n");
	dta.infile = open(argv[1], O_RDONLY);
	dta.outfile = open(argv[argc -1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (dta.infile < 0 || dta.outfile < 0)
		printf_error(&dta, "Error");
	look_road(env, &dta);
	dta.path = ft_split(dta.envh, ':');
	dta.cmd_ar = ft_split(argv[2], ' ');
	dta.cmd1 = path(dta.envh, &dta, ft_strjoin("/", dta.cmd_ar[0]));
	if (!dta.cmd1)
	{
		exit(1);
	}
	pid1 = fork();
	printf("%s\n",dta.cmd_ar[0]);
	printf("%s\n",dta.cmd_ar[1]);
	printf("%s\n",dta.cmd1);
	if (pid1 == -1)
		exit(1);
	if (pid1 == 0)
	{
		printf("ok1\n");
		first_process(argv, &dta, env);
		printf("ok2\n");
	}
	else
	{
		waitpid(pid1, NULL, 0);	
		printf("nouykka");
		dta.cmd_ar2 = ft_split(argv[3], ' ');
		dta.cmd2 = path(dta.envh, &dta, ft_strjoin("/", dta.cmd_ar2[0]));
		second_process(argv, &dta, env, status);
	}
	close(dta.pipefd[0]);
	close(dta.pipefd[1]);
	waitpid(pid1, NULL, 0);
	printf("test\n");
	return (0);
}

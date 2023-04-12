/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:11:23 by bloisel           #+#    #+#             */
/*   Updated: 2023/04/12 18:32:09 by bloisel          ###   ########.fr       */
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
	int status;
	pid_t pid;
	init_data(&dta);
	if (argc != 5)
		printf_error(&dta, "Error\n");
	dta.infile = open(argv[1], O_RDONLY);
	dta.outfile = open(argv[argc -1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
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
	pipe(dta.pipefd);
	pid = fork();
	printf("%s\n",dta.cmd_ar[0]);
	printf("%s\n",dta.cmd_ar[1]);
	printf("%s\n",dta.cmd1);
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		printf("ok1\n");
		first_process(argv, &dta, env);
		printf("ok2\n");
	}
	else
	{
		waitpid(-1, &status, 0);
		printf("okokokko\n");
		dta.cmd_ar2 = ft_split(argv[3], ' ');
		dta.cmd2 = path(dta.envh, &dta, ft_strjoin("/", dta.cmd_ar2[0]));
		if (!dta.cmd2)
		{
			exit(1);
		}
		printf("%s\n",dta.cmd_ar2[1]);
	}
    // if (execve(dta.cmd1, &dta.cmd_ar[0], env) == -1)
    // 		perror("execve");
	printf("test\n");
	return (0);
}

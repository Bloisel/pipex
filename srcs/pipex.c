/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:17:13 by bloisel           #+#    #+#             */
/*   Updated: 2023/04/13 17:38:41 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*look_road(char **env, t_data *dta)
{
	while (ft_strncmp("PATH", *env, 4))
	{
		env++;
	}
	dta->envh = *env + 5;
	return (*env + 5);
}

char	*path(char *env, t_data *dta, char *cm)
{
	int		i;
	int		j;
	char	*cmd;

	j = 0;
	i = -1;
	while (dta->path[++i])
	{
		cmd = ft_strjoin(dta->path[i], cm);
		if (access(cmd, F_OK) == 0)
		{
			free(cm);
			return (cmd);
		}
		free(cmd);
	}
	perror("Error");
	free(cm);
	return (NULL);
}

void	first_process(char **argv, t_data *dta, char **env)
{
	dup2(dta->pipefd[1], STDOUT_FILENO);
	close(dta->pipefd[1]);
	close(dta->pipefd[0]);
	dup2(dta->infile, STDIN_FILENO);
	close(dta->outfile);
	close(dta->infile);
	if (execve(dta->cmd1, &dta->cmd_ar[0], env) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

void	second_process(char **argv, t_data *dta, char **env)
{
	dup2(dta->pipefd[0], STDIN_FILENO);
	close(dta->pipefd[1]);
	close(dta->pipefd[0]);
	dup2(dta->outfile, STDOUT_FILENO);
	close(dta->outfile);
	close(dta->infile);
	if (execve(dta->cmd2, &dta->cmd_ar2[0], env) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

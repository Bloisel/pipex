/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:17:13 by bloisel           #+#    #+#             */
/*   Updated: 2023/03/21 18:26:49 by bloisel          ###   ########.fr       */
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
			free(cm);
			return (cmd);
		}
		free(cmd);
	}
	free(cm);
	return (NULL);
}

int	parent_process(char **argv, char **env, t_data *dta)
{
	close(dta->pipefd[0]);
	dup2(dta->pipefd[1], 1);
	dup2(dta->infile, 0);
	execve(dta->cmd1, &argv[2], env);
	close(dta->pipefd[0]);
	return (0);
}

int	child_process(char **argv, char **env, t_data *dta)
{
	close(dta->pipefd[1]);
	dup2(dta->pipefd[0], 0);
	dup2(dta->outfile, 1);
	execve(dta->cmd2, &argv[3], env);
	close(dta->pipefd[1]);
	return (0);
}

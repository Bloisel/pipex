/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:11:23 by bloisel           #+#    #+#             */
/*   Updated: 2023/03/17 16:51:35 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_data(t_data *dta)
{
	int	error;

	error = 0;
}

char	*look_road(char **env,t_data *dta)
{
	while (ft_strncmp("PATH", *env, 4))
	{
		env++;
	}
	dta->envh = *env + 5;
	return(*env + 5);
}

void	path(char *env, t_data *dta, char **envb)
{
	int i;
	int j;

	j = 0;
	char	*cmd;

	i = -1;
	dta->path = ft_split(dta->envh, ':');
	ft_printf("%s\n",dta->envh);
	while (dta->path[++i])
	{
		cmd = ft_strjoin(dta->path, "/ls");
		access(cmd, F_OK);
		//execve(cmd, dta->path, envb);
		//perror("Error");
		// j++;
		free(cmd);
	}	
}

int main(int argc, char **argv, char **env)
{
	t_data dta;
	char **envb;
	envb = env;
	// usr/bin (le + de cmd)
	printf("%s\n",look_road(env, &dta));
	path(dta.envh, &dta, envb);
	return (0);
}

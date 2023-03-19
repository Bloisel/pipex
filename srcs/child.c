/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:17:13 by bloisel           #+#    #+#             */
/*   Updated: 2023/03/19 17:08:43 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int    child(char **argv, char **env, t_data *dta)
{
    int status;
    
    printf("ok\n");
    if ((dta->pid1 = fork()) == -1)
    {
        perror("fork");
        return (1);
    }
    else if (dta->pid1 == 0)
    {
    printf("je suis le fils = %d\n",getpid());
       if (execve(dta->cmd1, &argv[1], env) == -1)
        perror("execve");
       return (1); 
    }
    else 
    {
    printf("Je suis le pere %d , et voici le pid de de mon fils : %d\n", getpid(), dta->pid1);
    wait(&status);
    }
    printf("wait bloquant \n");
    return (0);
}
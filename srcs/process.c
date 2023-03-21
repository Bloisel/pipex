/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:03:30 by bloisel           #+#    #+#             */
/*   Updated: 2023/03/21 18:20:22 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// void    parent_process(int outfile, char *cmd2);

// void    child_process(int infile, char *cmd1);



// void    child_process(int infile, char *cmd1)
// {
// }

// void process (int infile, int outfile, char *cmd1, char *cmd2, t_data *dta)
// {
//     int pipefd[2];
//     pipe(pipefd);

//     int status;
//     dta->pid2 = fork();
//     if (dta->pid2 < 0) // si pid est superieur a 0 processus parent 
//         {
//             perror("fork"); 
//             return (1);
//         }
//     if (!dta->pid2) // pid egal a 0 processus qui vient detre cree 
//     {
//        child_process(infile , cmd1); 
//     }
//     else 
//     {
//         parent_process(outfile, cmd2);
//     }
// }


//int	parent_process(char **argv, char **env, t_data *dta)
//  {
//    if (dta->pid1 == -1)
	// {
	// 	perror("fork");
	// 	return (1);
	// }
	// else if (dta->pid1 == 0)
	// {
	// 	if (execve(dta->cmd1, &argv[1], env) == -1)
	//  		perror("execve");
	// return (1);
	// }
	// else
	//   wait(&status);
	// return (0);
//  }
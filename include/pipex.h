/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:09:27 by bloisel           #+#    #+#             */
/*   Updated: 2023/03/18 14:13:33 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include"../lib/libft/libft.h"
# include"../lib/ft_printf/ft_printf.h"
# include "stdio.h"
# include "fcntl.h"
# include "stdlib.h"
# include "unistd.h"
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_data
{
	char	*envh;
	char	**path;
	int		error;
	int		infile;
	char*	cmd1;
	char*	cmd2;	
	int		outfile;
}	t_data;

void    print_tab(char **tab);
void	printf_error(t_data *dta, char *str);
void	ft_exit(t_data *dta);

#endif
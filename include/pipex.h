/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:09:27 by bloisel           #+#    #+#             */
/*   Updated: 2023/02/25 16:00:45 by bloisel          ###   ########.fr       */
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

typedef struct s_data
{
	int		error;
}	t_data;

void    print_tab(char **tab);
void	printf_error(t_data *dta, char *str);
void	ft_exit(t_data *dta);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:11:16 by bloisel           #+#    #+#             */
/*   Updated: 2023/02/13 11:11:18 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_exit(t_data *dta)
{
	if (dta->error > 0)
		exit(1);
	exit(0);
}

void	printf_error(t_data *dta, char *str)
{
	ft_printf("%s\n", str);
	dta->error = 1;
	ft_exit(dta);
}

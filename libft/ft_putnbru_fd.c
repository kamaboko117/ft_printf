/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:01:01 by asaboure          #+#    #+#             */
/*   Updated: 2020/07/31 20:01:05 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_recurr(unsigned int n, int fd)
{
	char a;

	if (n >= 10)
	{
		ft_recurr(n / 10, fd);
		ft_recurr(n % 10, fd);
	}
	else
	{
		a = n + 48;
		write(fd, &a, 1);
	}
}

void		ft_putnbru_fd(unsigned int n, int fd)
{
	ft_recurr(n, fd);
}

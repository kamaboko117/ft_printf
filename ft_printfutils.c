/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:39:24 by asaboure          #+#    #+#             */
/*   Updated: 2020/02/13 16:42:22 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

#include <stdio.h>
void	chr(va_list *list)
{
	int chr;

	chr = va_arg(*list, int);
	ft_putchar_fd(chr, 1);
}

void	str(va_list *list)
{
	char	*str;

	str = va_arg(*list, char *);
	ft_putstr_fd(str, 1);
}

void	ptr(va_list *list)
{
	intptr_t	ptr;

	ptr = va_arg(*list, intptr_t);
	ft_putnbrbase_fd(ptr, "0123456789abcdef", 1);
}

void	nbr(va_list *list)
{
	int	nbr;

	nbr = va_arg(*list, int);
	ft_putnbr_fd(nbr, 1);
}

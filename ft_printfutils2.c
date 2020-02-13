/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:42:49 by asaboure          #+#    #+#             */
/*   Updated: 2020/02/11 21:25:52 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

void	*tabinit()
{
	void (*f[8])(va_list *);

	f[0] = chr;
	f[1] = str;
	f[2] = ptr;
	f[3] = nbr;
	f[4] = nbr;
	f[5] = nbr;
	f[6] = nbrhex;
	f[7] = nbrhex;
	return (*f);
}

int		find_index(char c)
{
	int		i;
	char	*tab;

	tab = "cspdiuxX";
	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	nbrhex(va_list *list)
{
	int	nbr;

	nbr = va_arg(*list, int);
	ft_putnbrbase_fd(nbr, "0123456789abcdef", 1);
}

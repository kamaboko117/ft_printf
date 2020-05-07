/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:42:49 by asaboure          #+#    #+#             */
/*   Updated: 2020/05/07 20:19:20 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int	(**tabinit(void))(va_list *, const char *)
{
	int (**f)(va_list *, const char *);
	
	if (!(f = malloc(8 * sizeof *f)))
		return(NULL);
	f[0] = chr;
	f[1] = str;
	f[2] = ptr;
	f[3] = nbr;
	f[4] = nbr;
	f[5] = nbr;
	f[6] = nbrhex;
	f[7] = nbrhexcaps;
	f[8] = leftpad;
	f[9] = zeropad;
	f[10] = dotpad;
	return (f);
}

int	find_index(char c)
{
	int		i;
	char	*tab;

	tab = "cspdiuxX-0.*";
	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	nbrhexcaps(va_list *list, const char *form)
{
	int	nbr;

	(void)form;
	nbr = va_arg(*list, int);
	ft_putnbrbase_fd(nbr, "0123456789ABCDEF", 1);
	return(ft_numlen(nbr, 16));
}

int	nbrhex(va_list *list, const char *form)
{
	int	nbr;

	(void)form;
	nbr = va_arg(*list, int);
	ft_putnbrbase_fd(nbr, "0123456789abcdef", 1);
	return(ft_numlen(nbr, 16));
}

int	zeropad(va_list *list, const char *form)
{
	int tmp;
	int	len;
	int	nb;

	tmp = 0;
	nb = va_arg(*list, int);
	if (form[1] == '.')
		dotpad(list, form + 1);
	while (form[tmp +1]  == '0')
		tmp++;
	len = ft_atoi(form + tmp);
	tmp += ft_numlen(len, 10);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		len--;
	}
	while (len-- > ft_numlen(nb, 10))
		write(1, "0", 1);
	ft_putnbr_fd(nb, 1);
	return (tmp);
}

int	dotpad(va_list *list, const char *form)
{
	int i;
	int	tmp;
	int	len;

	i = 1;
	len = ft_atoi(form + i);
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	tmp = find_index(form[i]);
	if (tmp == 1)
	{
		ft_putmaxstr(va_arg(*list, char *), len);
	}
	(void)list;
	return (1);
}

int	leftpad(va_list *list, const char *form)
{
	int	tmp;
	int	i;
	int	(**f)(va_list *, const char *);
	int	len;
	int ret;

	f = tabinit();
	i = 1;
	len = ft_atoi(form + i);
	ret = len;
	
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	tmp = find_index(form[i]);
	len -= (*f[tmp])(list, form + i);
	while(len-- > 0)
		write(1, " ", 1);
	return (ret);
}

void	ft_putmaxstr(const char *s, int len)
{
	int	i;

	i = 0;
	while (s[i] && i < len)
	{
		write(1, &s[i], 1);
		i++;
	}		
}
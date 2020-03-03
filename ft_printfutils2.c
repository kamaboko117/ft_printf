/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:42:49 by asaboure          #+#    #+#             */
/*   Updated: 2020/03/03 19:05:06 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

void	(**tabinit(void))(va_list *, const char *)
{
	void (**f)(va_list *, const char *);
	
	if (!(f = malloc(8 * sizeof *f)))
		return(NULL);
	f[0] = chr;
	f[1] = str;
	f[2] = ptr;
	f[3] = nbr;
	f[4] = nbr;
	f[5] = nbr;
	f[6] = nbrhex;
	f[7] = nbrhex;
	return (f);
}

int		find_index(char c)
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

void	nbrhex(va_list *list, const char *form)
{
	int	nbr;

	(void)form;
	nbr = va_arg(*list, int);
	ft_putnbrbase_fd(nbr, "0123456789abcdef", 1);
}

void	zeropad(va_list *list, const char *form)
{
	va_list cpy;
	int 	tmp;
	int		len;
	void	(**f)(va_list *, const char *);
	int		i;

	tmp = 0;
	f = tabinit();
	va_copy(*list, cpy);
	if (form[1] == '.')
		dotpad(&cpy, form + 1);
	while (form[tmp +1]  == '0')
		tmp++;
	len = ft_atoi(form + tmp);
	tmp += ft_numlen(len, 10);
	while (len--)
		write(1, "0", 1);
	i = find_index(form[tmp]);
	if (i != -1)
		(*f[i])(&cpy, form);
}

void	dotpad(va_list *list, const char *form)
{
	(void)list;
	(void)form;
}

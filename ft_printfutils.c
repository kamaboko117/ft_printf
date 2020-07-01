/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:39:24 by asaboure          #+#    #+#             */
/*   Updated: 2020/05/08 21:03:01 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	chr(va_list *list, const char *form)
{
	int chr;

	(void)form;
	chr = va_arg(*list, int);
	ft_putchar_fd(chr, 1);
	return (1);
}

int	str(va_list *list, const char *form)
{
	char	*str;

	(void)form;
	str = va_arg(*list, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ptr(va_list *list, const char *form)
{
	intptr_t	ptr;

	(void)form;
	ptr = va_arg(*list, intptr_t);
	write(1, "0x", 2);
	ft_putnbrbase_fd(ptr, "0123456789abcdef", 1);
	return (ft_numlen(ptr, 16) + 2);
}

int	nbr(va_list *list, const char *form)
{
	int	nbr;

	(void)form;
	nbr = va_arg(*list, int);
	ft_putnbr_fd(nbr, 1);
	if (nbr < 0)
		return (ft_numlen(nbr, 10) + 1);
	return (ft_numlen(nbr, 10));
}

int	(**tabinit(void))(va_list *, const char *)
{
	int (**f)(va_list *, const char *);

	if (!(f = malloc(11 * sizeof(*f))))
		return (NULL);
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
	f[11] = pad;
	f[12] = pad;
	f[13] = pad;
	f[14] = pad;
	f[15] = pad;
	f[16] = pad;
	f[17] = pad;
	f[18] = pad;
	f[19] = pad;
	return (f);
}

int	pad(va_list *list, const char *form)
{
	int i;
	int tmp;
	int len;

	len = ft_atoi(form);
	i = ft_numlen(len, 10);
	if (form[i] == '.')
		dotpad(list, form + 1);
	tmp = find_index(form[i]);
	if (tmp >= 3 && tmp <= 5)
		return (paddec(list, len));
	if (tmp == 6)
		return (padhex(list, len));
	if (tmp == 7)
		return (padhexc(list, len));
	return (0);
}

int	paddec(va_list *list, int len)
{
	int	nb;
	int	ret;
	int	i;

	nb = va_arg(*list, int);
	ret = len - ft_numlen(len, 10) - 1;
	i = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		len--;
		i = 0;
	}
	while (len-- > ft_numlen(nb, 10))
		write(1, " ", 1);
	ft_putnbr_fd(nb, 1);
	if (ret >= ft_numlen(nb, 10) - i)
		return (ret);
	else
		return (ft_numlen(nb, 10) - i);
}

int	padhex(va_list *list, int len)
{
	int	nb;
	int	ret;
	int	i;

	nb = va_arg(*list, int);
	ret = len - ft_numlen(len, 16) - 1;
	i = 1;
	while (len-- > ft_numlen(nb, 16))
		write(1, " ", 1);
	ft_putnbrbase_fd(nb, "0123456789abcdef", 1);
	if (ret >= ft_numlen(nb, 16) - i)
		return (ret);
	else
		return (ft_numlen(nb, 16) - i);
}

int	padhexc(va_list *list, int len)
{
	int	nb;
	int	ret;
	int	i;

	nb = va_arg(*list, int);
	ret = len - ft_numlen(len, 16) - 1;
	i = 1;
	while (len-- > ft_numlen(nb, 16))
		write(1, " ", 1);
	ft_putnbrbase_fd(nb, "0123456789ABCDEF", 1);
	if (ret >= ft_numlen(nb, 16) - i)
		return (ret);
	else
		return (ft_numlen(nb, 16) - i);
}


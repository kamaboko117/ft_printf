/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 21:03:44 by asaboure          #+#    #+#             */
/*   Updated: 2020/05/08 21:14:08 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_index(char c)
{
	int		i;
	char	*tab;

	tab = "cspdiuxX-0.*123456789%";
	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	zeropaddec(int mode, va_list *list, const char *form)
{
	int	nb;
	int	len;
	int	ret;
	int	i;

	if (mode == 1)
		len = va_arg(*list, int);
	else
		len = ft_atoi(form + 1);
	nb = va_arg(*list, int);
	ret = len - 1;
	i = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		len--;
		i = 0;
	}
	while (len-- > ft_numlen(nb, 10))
		write(1, "0", 1);
	return (zeropaddecend(nb, ret, i) - strnumlen(form + 1));
}

int	zeropadhex(int mode, va_list *list, const char *form)
{
	int	nb;
	int	len;
	int	ret;
	int	i;

	if (mode == 1)
		len = va_arg(*list, int);
	else
		len = ft_atoi(form + 1);
	nb = va_arg(*list, int);
	ret = len - ft_numlen(len, 16) - 1;
	i = 1;
	while (len-- > ft_numlen(nb, 16))
		write(1, "0", 1);
	ft_putnbrbase_fd(nb, "0123456789abcdef", 1);
	if (ret >= ft_numlen(nb, 16) - i - 1)
		return (ret);
	else
		return (ft_numlen(nb, 16) - i - 1);
}

int	zeropadhexc(int mode, va_list *list, const char *form)
{
	int	nb;
	int	len;
	int	ret;
	int	i;

	if (mode == 1)
		len = va_arg(*list, int);
	else
		len = ft_atoi(form + 1);
	nb = va_arg(*list, int);
	ret = len - ft_numlen(len, 16) - 1;
	i = 1;
	while (len-- > ft_numlen(nb, 16))
		write(1, "0", 1);
	ft_putnbrbase_fd(nb, "0123456789ABCDEF", 1);
	if (ret >= ft_numlen(nb, 16) - i - 1)
		return (ret);
	else
		return (ft_numlen(nb, 16) - i - 1);
}

int	leftpadend(int ret, int i, int len, const char *form)
{
	int tmp;

	tmp = find_index(form[i]);
	while (tmp == 10 && (form[i] == '.' || form[i] == '*' ||
			(form[i] >= '0' && form[i] <= '9')))
	{
		len--;
		i++;
	}
	while (len-- > 0)
		write(1, " ", 1);
	if (len < 0)
		return (ret - len - i - 1);
	return (ret);
}

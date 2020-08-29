/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeropad2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:59:56 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/29 19:29:56 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	zeropaddec(int mode, va_list *list, const char *form)
{
	int	nb;
	int	len;
	int	ret;
	int	i;

	len = ft_atoi(form + 1);
	if (mode >= 1)
		len = va_arg(*list, int);
	if (mode == 2 || mode == -1)
		va_arg(*list, int);
	if (len < 0)
		return (starleftpad(list, form, -len, 3) - 1);
	nb = va_arg(*list, int);
	ret = len;
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
	return (zeropaddecend(nb, ret, i));
}

int	zeropaddecend(int nb, int ret, int i)
{
	ft_putnbr_fd(nb, 1);
	if (ret >= ft_numlen(nb, 10) - i + 1)
		return (ret);
	else
		return (ft_numlen(nb, 10) - i + 1);
}

int	zeropadpercent(int mode, va_list *list, const char *form)
{
	int i;
	int len;

	(void)mode;
	(void)list;
	len = ft_atoi(form + 1);
	i = 1;
	while (i < len)
	{
		write(1, "0", 1);
		i++;
	}
	write(1, "%", 1);
	i = 0;
	while (form[i])
	{
		if (form[i] == '%')
			break ;
		i++;
	}
	if (form[i + 1])
		write(1, &form[i + 1], 1);
	return (len - (strnumlen(form)));
}

int	checkzeropad(va_list *list, const char *form, int j, int mode)
{
	int		size;
	int		i;
	int		tmp;
	va_list copy;

	i = 1;
	va_copy(copy, *list);
	if (form[1] == '*')
		va_arg(copy, int);
	size = form[j + 1] == '*' ? va_arg(copy, int) : ft_atoi(form);
	va_end(copy);
	if (size >= 0)
		return (pad(list, form + 1) - 1);
	mode = -1;
	if (form[1] == '*')
		mode = 2;
	while (form[i + j + 1] >= '0' && form[i + j + 1] <= '9')
		i++;
	tmp = find_index(form[i + j + 1]);
	return (zeropadend(list, form, tmp, mode) - (i + 1 + j));
}

int	checkneg(va_list *list)
{
	va_list copy;
	int		n;

	va_copy(copy, *list);
	n = va_arg(copy, int);
	va_end(copy);
	if (n < 0)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftpad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:55:10 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/11 19:59:15 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	leftpad(va_list *list, const char *form)
{
	int	tmp;
	int	i;
	int	(**f)(va_list *, const char *);
	int	len;
	int ret;

	f = tabinit();
	len = form[1] == '*' ? va_arg(*list, int) : ft_atoi(form + 1);
	len = len < 0 ? -len : len;
	i = form[1] == '*' ? 2 : 1;
	ret = len;
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	if ((tmp = find_index(form[i])) == -1)
		return (0);
	if (tmp == 21)
		return (leftpadpercent(len, i, form));
	len -= (*f[tmp])(list, form + i);
	return (leftpadend(ret, i, len, form));
}

int	leftpadpercent(int len, int j, const char *form)
{
	int	i;

	write(1, "%", 1);
	i = 1;
	while (i++ < len)
		write(1, " ", 1);
	if (form[j + 1])
		write(1, &form[j + 1], 1);
	return (len - j);
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

int	starleftpad(va_list *list, const char *form, int len, int tmp)
{
	int	i;
	int	(**f)(va_list *, const char *);
	int ret;

	f = tabinit();
	i = 1;
	ret = len;
	if (tmp == -1)
		return (0);
	len -= (*f[tmp])(list, form + i);
	return (leftpadend(ret, i, len, form));
}

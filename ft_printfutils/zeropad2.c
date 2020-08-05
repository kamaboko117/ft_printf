/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeropad2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:59:56 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/05 18:30:58 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	zeropaddecend(int nb, int ret, int i)
{
	ft_putnbr_fd(nb, 1);
	if (ret >= ft_numlen(nb, 10) - i)
		return (ret);
	else
		return (ft_numlen(nb, 10) - i);
}

int	zeropadpercent(int mode, va_list *list, const char *form)
{
	int i;
	int len;

	(void)mode;
	(void)list;
	(void)form;
	len = ft_atoi(form + 1);
	i = 1;
	while (i < len)
	{
		write(1, "0", 1);
		i++;
	}
	write(1, "%", 1);
	return (len - 2);
}

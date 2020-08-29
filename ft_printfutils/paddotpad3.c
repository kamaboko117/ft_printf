/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paddotpad3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 20:09:25 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/29 19:26:33 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	pdpshexc(unsigned int nb, int len, int zl)
{
	int		oldzl;
	int		i;
	int		j;

	oldzl = zl;
	zl = zl < ft_numlen(nb, 16) ? ft_numlen(nb, 16) : zl;
	i = 0;
	while (i++ < len - zl)
		write(1, " ", 1);
	j = 0;
	while (j++ < zl - ft_numlen(nb, 16))
		write(1, "0", 1);
	if (oldzl != 0 || nb != 0)
		ft_putnbrbase_fd(nb, "0123456789ABCDEF", 1);
	else if (len != 0)
		write(1, " ", 1);
	if (len == 0 && nb == 0 && oldzl == 0)
		return (-1);
	return (i + zl - 2);
}

int	pdpsu(unsigned int nb, int len, int zl)
{
	int i;
	int j;
	int	oldzl;

	oldzl = zl;
	zl = zl < ft_numlen(nb, 10) ? ft_numlen(nb, 10) : zl;
	i = 0;
	while (i++ < len - zl)
		write(1, " ", 1);
	j = 0;
	while (j++ < zl - ft_numlen(nb, 10))
		write(1, "0", 1);
	if (oldzl != 0 || nb != 0)
		ft_putnbru_fd(nb, 1);
	else if (len != 0)
		write(1, " ", 1);
	if (len == 0 && nb == 0 && oldzl == 0)
		return (-1);
	return (i + zl - 2);
}

int	paddotpadu(unsigned int nb, const char *form, int len)
{
	int zerolen;
	int i;
	int j;

	zerolen = ft_atoi(form + 1);
	zerolen = zerolen < ft_numlen(nb, 10) ? ft_numlen(nb, 10) : zerolen;
	i = 0;
	while (i++ < len - zerolen)
		write(1, " ", 1);
	j = 0;
	while (j++ < zerolen - ft_numlen(nb, 10))
		write(1, "0", 1);
	if (ft_atoi(form + 1) != 0 || nb != 0)
		ft_putnbru_fd(nb, 1);
	else if (len != 0)
		write(1, " ", 1);
	if (len == 0 && nb == 0 && ft_atoi(form + 1) == 0)
		return (-1);
	return (i + zerolen - strnumlen(form) - 2);
}

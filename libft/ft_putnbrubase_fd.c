/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrubase_fd.c                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:23:37 by asaboure          #+#    #+#             */
/*   Updated: 2020/03/03 19:19:52 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int		check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

static void		ft_recurr(unsigned int n, int fd, unsigned int baselen, char *base)
{
	char a;

	if (n >= baselen)
	{
		ft_recurr(n / baselen, fd, baselen, base);
		ft_recurr(n % baselen, fd, baselen, base);
	}
	else
	{
		a = base[n];
		write(fd, &a, 1);
	}
}

void			ft_putnbrubase_fd(unsigned n, char *base, int fd)
{
	if (check_base(base))
	{
		ft_recurr(n, fd, ft_strlen(base), base);
	}
}

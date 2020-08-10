/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:32:52 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/10 16:14:36 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	(**tabinit(void))(va_list *, const char *)
{
	int (**f)(va_list *, const char *);
	int	i;

	if (!(f = malloc(22 * sizeof(*f))))
		return (NULL);
	f[0] = chr;
	f[1] = str;
	f[2] = ptr;
	f[3] = nbr;
	f[4] = nbr;
	f[5] = nbru;
	f[6] = nbrhex;
	f[7] = nbrhexcaps;
	f[8] = leftpad;
	f[9] = zeropad;
	f[10] = dotpad;
	i = 11;
	while (i <= 20)
	{
		f[i] = pad;
		i++;
	}
	f[21] = percent;
	return (f);
}

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

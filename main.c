/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 18:48:45 by asaboure          #+#    #+#             */
/*   Updated: 2020/05/07 19:44:19 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	void	*cursed = malloc(42);
	char	*s = "nique ta race jo";
	int		x = 713752;

	printf("[%d]\n", ft_printf("test %p %X %s\n", cursed, x, s));
	printf("[%d]\n", printf("test %p %X %s\n", cursed, x, s));

	ft_printf("kamaboko117 %-10s kamaboko117\n", s);
	printf("kamaboko117 %-10s kamaboko117\n", s);
}

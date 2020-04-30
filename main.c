/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 18:48:45 by asaboure          #+#    #+#             */
/*   Updated: 2020/04/30 15:17:36 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	void	*cursed = malloc(42);
	char	*s = "nique ta race jo";
	int		x = 713;

	printf("[%d]\n", ft_printf("test %p %X %s\n", cursed, x, s));
	printf("[%d]\n", printf("test %p %X %s\n", cursed, x, s));
}

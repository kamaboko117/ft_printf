/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 18:48:45 by asaboure          #+#    #+#             */
/*   Updated: 2020/05/08 18:51:41 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	//void	*cursed = malloc(42);
	//char	*s = "nique ta race jo";
	int		x = 713752;

	printf("[%d]\n", ft_printf("kamaboko117 %.*d kamaboko117\n", 7, x));
	printf("[%d]\n", printf("kamaboko117 %.*d kamaboko117\n", 7, x));

//	ft_printf("kamaboko117 %.10X kamaboko117\n", x);
//	printf("kamaboko117 %.10X kamaboko117\n", x);
}

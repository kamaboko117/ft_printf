/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 18:48:45 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/25 19:05:16 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	//void	*cursed = malloc(42);
	//void	*cursed2 = malloc(7);
	//char	*s = "nique ta race jo";
	//int		x = 713752;
	//char	*s_hidden = "hi low";
	printf("[%d]\n", printf("cOld%-10xAI5G%12.0uCeL1Txm%u", -2147483647, -2147483647, 0));
	printf("[%d]\n", ft_printf("cOld%-10xAI5G%12.0uCeL1Txm%u", -2147483647, -2147483647, 0));
//	while (1);
	
//	ft_printf("kamaboko117 %.10X kamaboko117\n", x);
//	printf("kamaboko117 %.10X kamaboko117\n", x);
}
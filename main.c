/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 18:48:45 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/29 18:24:38 by asaboure         ###   ########.fr       */
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
	printf("[%d]\n", printf("Cn1vUfc%*.0x", 0, 0));
	printf("[%d]\n", ft_printf("Cn1vUfc%*.0x", 0, 0));
//	while (1);
	
//	ft_printf("kamaboko117 %.10X kamaboko117\n", x);
//	printf("kamaboko117 %.10X kamaboko117\n", x);
}
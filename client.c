/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:59:27 by luisfern          #+#    #+#             */
/*   Updated: 2022/10/06 19:12:28 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf/includes/ft_printf.h"

int	main(int ac, char **av)
{
	// if (ac != 3 || !ft_isdigit(ft_atoi(av[1])))
	// {
	// 	ft_printf("Invalid CLI Arguments\n");
	// 	ft_printf("Expected ./client [PDI] [Message]\n");
	// 	return (0);
		
	// }
	char c = 'o';
	char bin[16];
	int i = 0;
	while (i <= 8)
	{
		bin[i] = c % 2;
		c /= 2;
		i++;
	}
	printf("%s", bin);
}

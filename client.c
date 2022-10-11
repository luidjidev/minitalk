/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:59:27 by luisfern          #+#    #+#             */
/*   Updated: 2022/10/11 15:47:24 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/includes/ft_printf.h"

void	send_msg(int pid, char *msg)
{
	int	index;
	int temp;
	char c;
	
	index = 0;
	temp = 0;
	while (msg[index])
	{
		c = msg[index];
		while(c != 0)
		{
			temp = c % 2;
			if (temp == 0)
				kill(pid, SIGUSR1);
			else if (temp == 1)
				kill(pid, SIGUSR2);
			c /= 2;
		}
		index++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Invalid CLI Arguments\n", ac);
		ft_printf("Expected ./client [PDI] [Message]\n");
		return (0);
	}
	send_msg(ft_atoi(av[1]), av[2]);
}

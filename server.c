/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:45:09 by luisfern          #+#    #+#             */
/*   Updated: 2022/10/11 15:49:05 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/includes/ft_printf.h"

void	receive_msg(int signal)
{
	static int		index;
	static char		byte[8];

	if (signal == SIGUSR1)
	{
		byte[index] = 0;
	}
	else if (signal == SIGUSR2)
	{
		byte[index] = 1;
	}
	index++;
	if (index == 7)
	{
		// conversion_to_decimal(byte);
		ft_printf("%s", byte);
		index = 0;
	}
}

int	main(void)
{
	ft_printf("PID - %i\n", getpid());
	while (1 == 1)
	{
		signal(SIGUSR1, receive_msg);
		signal(SIGUSR2, receive_msg);
		pause();
	}
	return (0);
}

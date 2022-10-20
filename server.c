/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:27:54 by luisfern          #+#    #+#             */
/*   Updated: 2022/10/14 12:34:35 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/includes/ft_printf.h"

int	g_bit = 128;

void	handler_sig(int signal)
{
	static int	i;
	static int	carater;

	if (signal == SIGUSR2)
	{
		carater += g_bit;
		g_bit /= 2;
	}
	else
		g_bit /= 2;
	i++;
	if (i == 8)
	{
		ft_printf("%c", carater);
		i = 0;
		carater = 0;
		g_bit = 128;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, handler_sig);
	signal(SIGUSR2, handler_sig);
	while (1)
		pause();
}

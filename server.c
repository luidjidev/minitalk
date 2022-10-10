/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:45:09 by luisfern          #+#    #+#             */
/*   Updated: 2022/10/10 16:59:13 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "ft_printf/includes/ft_printf.h"

void	receive_msg(int signal)
{
	static int		index;
	char	byte[8];

	index = 7;
	if (signal == SIGUSR1)
		byte[index] == 0;
	else if (signal == SIGUSR2)
		byte[index] == 1;
	index--;
	if (index == 0)
	{
		// conversion_to_decimal(byte);
		ft_printf("%s\n", byte);
		index = 7;
	}
		
}

int	main(void)
{
	struct sigaction sa;
	sigset_t	block_signal;
	
	
	ft_printf("PID - %i\n", getpid());
	sigemptyset(&block_signal);
	sigaddset(&block_signal, SIGUSR1);
	sigaddset(&block_signal, SIGUSR2);
	sa.sa_mask = block_signal;
	sa.sa_handler = &receive_msg;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
	
}

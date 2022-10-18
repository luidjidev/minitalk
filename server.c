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

static void handler(int signal, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;
	
	(void)context;
	if (info->si_errno != 0)
		return ;
	c |= (signal == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		ft_printf("%c", c);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction sa;

	ft_printf("PID: %i\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:20:44 by fbiberog          #+#    #+#             */
/*   Updated: 2024/05/15 16:08:13 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signalhandler(int signal)
{
	static int	i;
	static int	bit;
	static int	reset;

	if (signal == SIGUSR1)
	{
		reset++;
		i |= (1 << bit);
	}
	else if (signal == SIGUSR2)
		reset = 0;
	bit++;
	if (reset == 8)
	{
		bit = 0;
		i = 0;
		reset = 0;
	}
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sa.sa_handler = signalhandler;
	sa.sa_flags = 1;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

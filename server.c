/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:20:44 by fbiberog          #+#    #+#             */
/*   Updated: 2024/05/20 14:26:41 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signalhandler(int signal, siginfo_t *info, void *unused)
{
	static int	i;
	static int	bit;

	unused = NULL;
	if (signal == SIGUSR1)
	{
		i |= (1 << bit);
		bit++;
	}
	if (signal == SIGUSR2)
	{
		i &= ~(1 << bit);
		bit++;
	}
	if (bit == 8)
	{
		if (i == 0)
			kill(info->si_pid, SIGUSR2);
		else
			write(1, &i, 1);
		bit = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sa.sa_sigaction = signalhandler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

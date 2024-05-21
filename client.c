/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:48:03 by fbiberog          #+#    #+#             */
/*   Updated: 2024/05/20 14:42:15 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_signal_received = 0;

void	signalhandler(int signum)
{
	if (signum == SIGUSR1)
		g_signal_received = 1;
	if (signum == SIGUSR2)
		ft_printf("Message received\n");
}

void	send_message(int pid, char *message)
{
	int	i;
	int	bit;
	int	ret_kill;

	i = 0;
	bit = 0;
	while (bit < 8)
	{
		if ((message[i] & (0x01 << bit)) != 0)
			ret_kill = kill(pid, SIGUSR1);
		else
			ret_kill = kill(pid, SIGUSR2);
		if (ret_kill == -1)
		{
			ft_printf("Error\nWRONG PID!\n");
			exit(0);
		}
		while (!g_signal_received)
			pause();
		g_signal_received = 0;
		usleep(100);
		bit++;
	}
	i++;
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Error\nWRONG FORMAT!\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	sa.sa_handler = signalhandler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (argv[2][i])
	{
		send_message(pid, &argv[2][i]);
		i++;
	}
	send_message(pid, "\n");
	send_message(pid, "\0");
	return (0);
}

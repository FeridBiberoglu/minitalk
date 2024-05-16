/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:48:03 by fbiberog          #+#    #+#             */
/*   Updated: 2024/05/16 18:36:17 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_signal_received = 0;

void	signalhandler(int signum)
{
	if (signum == SIGUSR1)
		g_signal_received = 1;
}

void	send_message(int pid, char *message)
{
	int	i;
	int	bit;

	i = 0;
	bit = 0;
	while (message[i] != '\0')
	{
		while (bit < 8)
		{
			if ((message[i] & (0x01 << bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (!g_signal_received)
				pause();
			g_signal_received = 0;
			usleep(100);
			bit++;
		}
		i++;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	printf("%i\n", argc);
	if (argc != 3)
	{
		printf("Error\nWRONG FORMAT!\n");
		return (0);
	}
	pid = atoi(argv[1]);
	sa.sa_handler = signalhandler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	send_message(pid, argv[2]);
	send_message(pid, "\n");
	return (0);
}

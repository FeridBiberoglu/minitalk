/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:20:44 by fbiberog          #+#    #+#             */
/*   Updated: 2024/05/14 15:24:01 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signalhandler(int signal)
{
	static int	i;
	static int	bit;

	if (signal == SIGUSR1)
		i |= (1 << bit);
	else if (signal == SIGUSR2)
		i &= ~(1 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR1, signalhandler);
	signal(SIGUSR2, signalhandler);
	while (1)
		pause();
	return (0);
}

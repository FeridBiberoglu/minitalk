/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:48:03 by fbiberog          #+#    #+#             */
/*   Updated: 2024/05/14 15:23:52 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(int pid, char argv)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((argv & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
	{
		printf("WRONG FORMAT!");
		return (0);
	}
	pid = atoi(argv[1]);
	while (argv[2][i])
	{
		send_message(pid, argv[2][i]);
		i++;
	}
	send_message(pid, '\n');
}

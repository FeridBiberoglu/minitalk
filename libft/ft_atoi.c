/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:02:26 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/18 16:16:29 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *ntpr)
{
	const char	*s;
	int			i;
	long long	j;
	long long	c;

	c = 0;
	j = 1;
	i = 0;
	s = ntpr;
	while (ntpr[i] == 32 || (ntpr[i] >= 9 && ntpr[i] <= 13))
		i++;
	if (ntpr[i] == '-')
	{
		j = -1;
		i++;
	}
	else if (ntpr[i] == '+')
		i++;
	while (ntpr[i] && ntpr[i] >= '0' && ntpr[i] <= '9')
	{
		c = c * 10 + ntpr[i] - 48;
		i++;
	}
	return (c * j);
}

// int main(void)
// {

// 	const char *n = " -123 ";
// 	int s = ft_atoi(n);
// 	printf("%i", s);
// }
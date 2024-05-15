/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:17:27 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/24 21:14:29 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_write(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_write('-', fd);
		nb = nb * -1;
	}
	if (nb >= 0 && nb < 10)
		ft_write((nb + 48), fd);
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_write((nb % 10 + 48), fd);
	}
}

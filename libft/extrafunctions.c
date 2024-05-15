/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrafunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:59:25 by fbiberog          #+#    #+#             */
/*   Updated: 2023/11/10 16:03:16 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr(long nb, char *database, long base)
{
	int	count;
	int	i;

	count = 0;
	if (nb >= base)
		count = putnbr(nb / base, database, base);
	nb = nb % base;
	i = database[nb];
	return (count + write(1, &i, 1));
}

int	baseconverter(long nb, char *database)
{
	long	base;
	int		count;

	if (nb < 0)
	{
		count = write(1, "-", 1);
		nb = -nb;
	}
	count = 0;
	base = 0;
	while (database[base])
		base++;
	count = count + putnbr(nb, database, base);
	return (count);
}

int	putnbr1(unsigned long long nb, char *database, unsigned long long base)
{
	int	count;
	int	i;

	count = 0;
	if (nb >= base)
		count = putnbr(nb / base, database, base);
	nb = nb % base;
	i = database[nb];
	return (count + write(1, &i, 1));
}

int	baseconverter1(unsigned long long nb, char *database)
{
	unsigned long long	base;
	int					count;

	if (nb < 0)
	{
		count = write(1, "-", 1);
		nb = -nb;
	}
	count = 0;
	base = 0;
	while (database[base])
		base++;
	count = count + putnbr1(nb, database, base);
	return (count);
}

int	print_integer(long long nb)
{
	static int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		count = count + print_character('-');
		nb = nb * -1;
	}
	if (nb >= 0 && nb < 10)
		count = count + print_character(nb + 48);
	if (nb >= 10)
	{
		count = count + print_integer(nb / 10);
		count = count + print_character(nb % 10 + 48);
	}
	return (count);
}

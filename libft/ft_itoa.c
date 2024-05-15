/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:11:17 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/24 17:20:32 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ispositive(int n, int len)
{
	char	*last;

	last = (char *)malloc(sizeof(char) * (len + 1));
	if (last == 0)
		return (0);
	last[len] = '\0';
	while (len > 0)
	{
		len--;
		last[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (last);
}

static char	*ft_isnegative(int n, int len)
{
	char	*last;

	n = n * -1;
	last = (char *)malloc(sizeof(char) * (len + 2));
	if (last == 0)
		return (0);
	last[0] = '-';
	last[len + 1] = '\0';
	while (len >= 1)
	{
		last[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (last);
}

char	*ft_itoa(int n)
{
	int		temp;
	int		len;
	char	*last;

	temp = n;
	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (temp)
	{
		len++;
		temp = temp / 10;
	}
	if (n < 0)
		last = ft_isnegative(n, len);
	else
		last = ft_ispositive(n, len);
	return (last);
}

// int main(void)
// {
// 	char *result;
// 	result = ft_itoa(-2147483648);
// 	printf("%s", result);
// }
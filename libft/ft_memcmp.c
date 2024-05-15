/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:12:48 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/23 17:13:06 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned int	i;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return ((a[i] - b[i]));
}

// int main(void)
// {
// 	char s[] = "";
// 	char d[] = "lala";
// 	size_t n = 4;
// 	// int i = ft_memcmp(s,d ,n);
// 	// int k = memcmp(s, d, n);

// 	printf("%i\n", ft_memcmp(s,d ,n));
// 	printf("%i\n", memcmp(s, d, n));
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:14:28 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/23 17:14:34 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int s, size_t n)
{
	size_t			i;
	unsigned char	x;
	unsigned char	*b;

	b = (unsigned char *)a;
	x = (unsigned char)s;
	i = 0;
	while (i < n)
	{
		b[i] = x;
		i++;
	}
	return (a);
}

// int main(void)
// {

// 	char a[] = "aaadsasd";
// 	char b[] = "aaadsasd";
// 	char *result = ft_memset(a, 48 , 8);
// 	char *result2 = memset(b, 48, 8);
// 	printf("%s\n", result);
// 	printf("%s\n", result2);
// }
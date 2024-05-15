/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:24:53 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/23 17:25:02 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *a, const char *b, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (a[i] && b[i] && i < n - 1)
	{
		if (a[i] == b[i])
			i++;
		else
			return ((unsigned char)a[i] - (unsigned char)b[i]);
	}
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}

// int main(void)
// {
// 	char *a = "test\200";
// 	char *b = "test\0";
// 	size_t n = 6;
// 	int result = ft_strncmp(a, b, n);
// 	printf("%i\n", result);

// 	int result2 = strncmp(a, b , n);
// 	printf("%i\n", result2);
// }
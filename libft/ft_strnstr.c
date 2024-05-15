/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:25:19 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/23 17:25:21 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[j + i] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	const char *big = "123456789";
// 	const char *little = "234";
// 	size_t n = 7;
// 	// ft_strnstr(big, little, 30);
// 	// strnstr(big, little, 6);

// 	printf("%s\n",ft_strnstr(big, little, n));
// 	printf("%s\n", strnstr(big, little, n));
// }
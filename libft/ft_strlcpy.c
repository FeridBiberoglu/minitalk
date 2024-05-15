/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:21:00 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/24 21:14:46 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t u)
{
	unsigned int	i;
	size_t			length;

	i = 0;
	length = ft_strlen(src);
	if (dest == NULL || u < 0)
		return (0);
	if (u == 0)
		return (length);
	while (src[i] && i < u - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

// int main(void)
// {
// 	char src[] = "lala";
// 	char dest[20];
// 	int result;
// 	result = ft_strlcpy(dest, src, 0);
// 	printf("%i\n", result);
// 	printf("%s\n", dest);

// 	char src2[] = "lala";
// 	char dest2[20];
// 	int result2;
// 	result2 = strlcpy(dest2, src2, 0);
// 	printf("%i\n", result2);
// 	printf("%s\n", dest2);
// }

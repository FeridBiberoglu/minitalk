/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:20:29 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/23 17:20:50 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	int		k;

	j = 0;
	i = 0;
	k = ft_strlen(src);
	while (dst[j])
		j++;
	while (j + i + 1 < size && src[i] != '\0')
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	if (j > size)
	{
		dst[j + i] = '\0';
		return (size + k);
	}
	return (k + j);
}

// int main(void)
// {
// 	size_t size = 10;
// 	char dst[] = "1234";
// 	const char *src = "56789";
// 	printf("%d\n",ft_strlcat(dst, src, size));
// 	printf("%s\n",dst);

// 	size_t size2 = 10;
// 	char dst2[] = "1234";
// 	const char *src2 = "56789";
// 	printf("%zu\n",strlcat(dst2, src2, size2));
// 	printf("%s\n",dst2);
// }
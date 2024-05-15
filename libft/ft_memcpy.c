/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:13:31 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/23 17:13:44 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// int main(void)
// {
// 	// char dest[10];
// 	// const char src[] = "";
// 	// ft_memcpy(((void*)0), ((void*)0), 3);
// 	// printf("%s\n", dest);

// 	char dest2[0];
// 	const char src2[] = "";
// 	memcpy((, 3);
// 	printf("%s\n", dest2);
// }

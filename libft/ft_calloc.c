/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:07:44 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/24 22:13:35 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	if (size && nmemb > SIZE_MAX / size)
		return (0);
	array = (char *)malloc(sizeof(char) * nmemb * size);
	if (array == 0)
		return (0);
	ft_memset(array, 0, (nmemb * size));
	return ((void *)array);
}

// while(i <= nmemb)
// {
// 	array[i] = 0;
// 	i++;
// 	// }
// if(size && (SIZE_MAX < nmemb * size))
// 	return (0);

// int main(void)
// {
// 	size_t size = sizeof(int);
// 	ft_calloc(7, size);
// }

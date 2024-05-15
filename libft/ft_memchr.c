/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:12:18 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/23 17:12:38 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*su;
	unsigned char	cu;

	i = 0;
	su = (unsigned char *)s;
	cu = (unsigned char)c;
	while (i < n)
	{
		if (su[i] == cu)
			return ((void *)(su + i));
		i++;
	}
	return (0);
}

// int main(void)
// {
// 		char s[] = "hh";
// 	int c = 0;
// 	ft_memchr(s, c, 3);
// }
// // temp gets returned
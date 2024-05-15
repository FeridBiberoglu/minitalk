/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:26:25 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/24 22:03:02 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *x, int search)
{
	int	i;

	search = search % 256;
	i = 0;
	while (x[i])
		i++;
	while (x[i] != search && i > 0)
		i--;
	if (x[i] == search)
		return ((char *)&x[i]);
	return (0);
}

// int main (void)
// {
// 	const char *x = "";
// 	const char *y = "sassddfgd";

// 	char search = 'x';
// 	char *result2 = ft_strrchr(x, search);
// 	char *result1 = strrchr(x, search);
// 	printf("%p\n", result1);
// 	printf("%p", result2);
// }
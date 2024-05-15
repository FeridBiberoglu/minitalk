/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:19:53 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/23 17:20:09 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		a;
	int		b;
	char	*array;

	j = 0;
	i = 0;
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	array = (char *)malloc(a + b + 1);
	if (array == 0)
		return (0);
	while (i < a)
	{
		array[i] = s1[i];
		i++;
	}
	while (i <= (a + b))
	{
		array[i] = s2[j];
		i++;
		j++;
	}
	return (array);
}

// int main(void)
// {
// 	char const s[] = "123";
// 	char const b[] = "456";
// 	char *k;
// 	k  = ft_strjoin(s, b);
// 	printf("%s", k);
// }
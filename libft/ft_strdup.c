/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:19:18 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/24 19:02:22 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	array = (char *)malloc(sizeof(char) * (i + 1));
	if (array == 0)
		return (0);
	while (j <= i)
	{
		array[j] = s[j];
		j++;
	}
	return (array);
}

// int main(void)
// {

// 	const char s[] ="rara";
// 	ft_strdup(s);
// }
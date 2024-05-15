/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:27:20 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/23 17:27:38 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*array;
	size_t	i;
	size_t	k;

	i = 0;
	k = ft_strlen(s);
	if (start > k)
		return (ft_strdup(""));
	if (len > k - start)
		len = k - start;
	array = (char *)malloc(len + 1);
	if (array == 0)
		return (0);
	while (i < len)
	{
		array[i] = s[start + i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

// int main(void)
// {
// 	char s[] = "sasdfsfsfaasss" ;
// 	ft_substr(s, 3 , 9);
// }
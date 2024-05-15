/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:18:41 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/23 17:18:46 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	c = c % 256;
	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}

// int main(void)
// {
// 	const char *s = "sas";
// 	int c = 'm';
// 	char result = *ft_strchr(s, c);
// 	char result2 = *strchr(s, c);
// 	printf("%c\n", result);
// 	printf("%c", result2);
// }
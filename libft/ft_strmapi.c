/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:13:10 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/24 21:13:22 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*string;
	int		length;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	length = ft_strlen(s);
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (string == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	i = 0;
	while (i < length)
	{
		string[i] = f(i, s[i]);
		i++;
	}
	return (string);
}

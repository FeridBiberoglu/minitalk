/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nextline2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:14:53 by fbiberog          #+#    #+#             */
/*   Updated: 2024/02/16 19:06:01 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char *s1, char *s2, int yes)
{
	int			i;
	const int	len1 = ft_strlen(s1);
	const int	len2 = ft_strlen(s2);
	char		*remain;

	i = 0;
	remain = (char *)malloc(len1 + len2 + 1);
	if (remain == 0)
		return (0);
	while (i < len1)
	{
		remain[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		remain[i + len1] = s2[i];
		i++;
	}
	if (yes == 0)
		free(s1);
	remain[i + len1] = '\0';
	return (remain);
}

int	ft_strchr2(const char *s, int c)
{
	int	i;

	c = c % 256;
	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*lastline(char *remain)
{
	char	*lastline;

	lastline = ft_strjoin2(remain, "", 1);
	if (!lastline)
		return (ft_free(&remain, 0));
	*remain = '\0';
	return (lastline);
}

char	*ft_free(char **remain, int yes)
{
	if (yes == 0 && remain != NULL)
	{
		free(*remain);
		*remain = NULL;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:57:30 by fbiberog          #+#    #+#             */
/*   Updated: 2024/02/15 16:46:48 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcounter(char const *s, char c)
{
	int	i;
	int	j;
	int	wordcount;

	wordcount = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && j == 0)
		{
			wordcount++;
			j = 1;
		}
		if (s[i] == c)
			j = 0;
		i++;
	}
	return (wordcount);
}

static int	cfinder(char const *s, int x, char c, int bool)
{
	int	i;

	i = 0;
	if (bool == 0)
	{
		while (s[x] && s[x] != c)
		{
			i++;
			x++;
		}
	}
	else if (bool == 1)
	{
		while (s[x] == c)
		{
			i++;
			x++;
		}
	}
	if (bool == 0)
		return (i);
	else
		return (x);
}

void	ft_free2(char **str, int j)
{
	if (j > 0)
	{
		j = j - 1;
		while (j >= 0)
		{
			free(str[j]);
			j--;
		}
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**str;

	j = 0;
	i = 0;
	str = (char **)malloc(sizeof(char *) * (wordcounter(s, c) + 1));
	if (str == 0)
		return (0);
	while (s[i] && j < wordcounter(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		str[j] = ft_substr(s, i, cfinder(s, i, c, 0));
		i = cfinder(s, i, c, 0) + cfinder(s, i, c, 1);
		if (str[j] == 0)
		{
			ft_free2(str, j);
			return (0);
		}
		j++;
	}
	str[j] = 0;
	return (str);
}

// int main(void)
// {
//     char const s[] = "345 567  ";
//     char c = '9';
//     char **result;
//     // reult = ft_split(s, c);
//     char * splitme = strdup("Tripouille");
// 	result = ft_split(splitme, ' ');
//     printf("%s\n", result[0]);
//     int i = 0;
//     while(result[i])
//     {
//         // printf("%s\n", result[i]);
//         free(result[i]);
//         i++;
//     }
//     free(splitme);
//     free(result);
// }
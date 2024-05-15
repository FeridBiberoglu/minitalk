/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:26:48 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/23 17:26:54 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		st;
	int		end;
	int		tot;
	char	*array;

	if (set == NULL)
		return ((char *)s1);
	st = 0;
	tot = 0;
	end = ft_strlen(s1) - 1;
	while (s1[st] && ft_check(s1[st], set))
		st++;
	while (end != 0 && ft_check(s1[end], set))
		end--;
	if (end - st + 1 <= 0)
		return (ft_strdup(""));
	array = (char *)malloc(sizeof(char) * (end - st + 2));
	if (array == 0)
		return (0);
	while (st <= end)
		array[tot++] = s1[st++];
	array[tot] = '\0';
	return (array);
}

// // int main(void)
// // {
// // 	char const s1[] = "lorem ipsum dolor sit amet";
// // 	char const s2[] = "te";
// // 	char *res = ft_strtrim(s1, s2);
// // 	printf("%s\n", res);

// // char const s4[] = "lorem ipsum dolor sit amet";
// // 	char const s5[] = "te";
// // 	char *res2 = ft_strtrim(s4, s5);
// // 	printf("%s", res2);
// // 	if(res)
// // 		free(res);
// // }
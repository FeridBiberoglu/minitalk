/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:07:26 by fbiberog          #+#    #+#             */
/*   Updated: 2023/10/23 17:07:34 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i != n)
	{
		p[i] = '\0';
		i++;
	}
	return ;
}

// int main(void)
// {
// 	char s[]= "sdsddfsdf";
// 	ft_bzero(s, 5);
// 	printf("%s", s);
// }
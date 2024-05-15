/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nextline1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:08:33 by fbiberog          #+#    #+#             */
/*   Updated: 2024/02/16 19:06:35 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_printedline(char *remain)
{
	int		i;
	int		newline;
	char	*printedline;

	i = 0;
	newline = ft_strchr2(remain, '\n');
	printedline = (char *)malloc(sizeof(char) * (newline + 2));
	if (printedline == 0)
		return (ft_free(&remain, 0));
	while (i <= newline)
	{
		printedline[i] = remain[i];
		i++;
	}
	printedline[i] = '\0';
	return (printedline);
}

char	*storedchar(char *remain)
{
	int		i;
	char	*stashed;
	int		size;
	int		start;

	start = ft_strchr2(remain, '\n');
	size = ft_strlen(remain) - start + 1;
	stashed = (char *)malloc(sizeof(char) * (size + 1));
	if (stashed == 0)
		return (ft_free(&remain, 0));
	i = 0;
	while (remain[++start])
		stashed[i++] = remain[start];
	stashed[i] = '\0';
	free(remain);
	return (stashed);
}

char	*ft_read(int fd, char *buffer)
{
	char		*ret_line;
	static char	*remain;
	int			bytes_read;

	bytes_read = BUFFER_SIZE;
	while (BUFFER_SIZE == bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(&remain, 0), ft_free(&buffer, 0));
		buffer[bytes_read] = '\0';
		remain = ft_strjoin2(remain, buffer, 0);
		if (!remain)
			return (NULL);
		if (ft_strchr2(remain, '\n') != -1)
		{
			ret_line = make_printedline(remain);
			remain = storedchar(remain);
			return (ft_free(&buffer, 0), ret_line);
		}
	}
	ft_free(&buffer, 0);
	if (remain != NULL && ft_strlen(remain) > 0)
		return (lastline(remain));
	return (ft_free(&remain, 0), NULL);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(&buffer, 0));
	return (ft_read(fd, buffer));
}

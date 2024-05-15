/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:01:12 by fbiberog          #+#    #+#             */
/*   Updated: 2023/11/23 21:24:05 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	print_adress(void *adress);
int	print_character(char x);
int	print_string(char *string);
int	print_integer(long long nb);
int	printformat(char type, va_list ap);
int	ft_printf(const char *string, ...);
int	baseconverter(long nb, char *database);
int	putnbr(long nb, char *database, long base);
int	putnbr1(unsigned long long nb, char *database, unsigned long long base);
int	baseconverter1(unsigned long long nb, char *database);

#endif
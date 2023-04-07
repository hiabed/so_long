/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:17:50 by mhassani          #+#    #+#             */
/*   Updated: 2022/11/15 21:17:55 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char format, va_list ar)
{
	int	i;

	if (format == 'c')
		i = ft_putchar(va_arg(ar, int));
	else if (format == '%')
		i = ft_putchar('%');
	else if (format == 's')
		i = ft_putstr(va_arg(ar, char *));
	else if (format == 'p')
		i = print_pointer(va_arg(ar, unsigned long));
	else if (format == 'd' || format == 'i')
		i = ft_putnbr(va_arg(ar, int));
	else if (format == 'u')
		i = print_uns_num(va_arg(ar, unsigned int));
	else if (format == 'x')
		i = ntohex(va_arg(ar, unsigned int));
	else if (format == 'X')
		i = ntohex_up(va_arg(ar, unsigned int));
	else
		i = ft_putchar(format);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, s);
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			len = len + ft_check(s[i + 1], args);
			i++;
		}
		else if (s[i] != '%')
		{
			len = len + ft_putchar(s[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}

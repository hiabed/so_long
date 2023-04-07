/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:21:10 by mhassani          #+#    #+#             */
/*   Updated: 2022/11/15 21:21:13 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexlen(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static int	ptr(unsigned long n)
{
	if (n >= 16)
	{
		ptr(n / 16);
		ptr(n % 16);
	}
	if (n < 10)
		ft_putchar(n + '0');
	else if (n > 9 && n <= 15)
		ft_putchar(n + 87);
	return (n);
}

int	print_pointer(unsigned long n)
{
	int	len;

	len = ft_putstr("0x");
	ptr(n);
	return (len + hexlen(n));
}

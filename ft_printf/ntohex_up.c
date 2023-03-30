/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numtohex_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:20:53 by mhassani          #+#    #+#             */
/*   Updated: 2022/11/15 21:20:56 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexlen(unsigned int n)
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

int	ntohex_up(unsigned int n)
{
	if (n >= 16)
	{
		ntohex_up(n / 16);
		ntohex_up(n % 16);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else if (n > 9 && n <= 15)
		ft_putchar(n + 55);
	return (hexlen(n));
}

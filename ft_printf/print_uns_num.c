/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:21:45 by mhassani          #+#    #+#             */
/*   Updated: 2022/11/15 21:21:48 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_num(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	print_uns_num(unsigned int n)
{
	if (n >= 10)
	{
		print_uns_num(n / 10);
		print_uns_num(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (len_num(n));
}

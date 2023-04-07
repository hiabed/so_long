/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:26:03 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/07 22:34:04 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	coins_count(t_position *p)
{
	int	i;

	i = 0;
	p->row = 0;
	p->col = 0;
	while (p->split[p->row])
	{
		while (p->split[p->row][p->col])
		{
			if (p->split[p->row][p->col] == 'C')
				p->coin_count = ++i;
			p->col++;
		}
		p->col = 0;
		p->row++;
	}
	if (i == 0)
	{
		write(2, "Error\n", 6);
		write(2, "There is no coins in the map\n", 29);
		exit(EXIT_FAILURE);
	}
}

void	first_frame(t_position *p, int col, int row)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, col * 70, row
		* 70);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->coin_ptr1, col * 70, row
		* 70);
}

void	second_frame(t_position *p, int col, int row)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, col * 70, row
		* 70);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->coin_ptr2, col * 70, row
		* 70);
}

void	third_frame(t_position *p, int col, int row)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, col * 70, row
		* 70);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->coin_ptr3, col * 70, row
		* 70);
}

void	forth_frame(t_position *p, int col, int row)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, col * 70, row
		* 70);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->coin_ptr4, col * 70, row
		* 70);
}

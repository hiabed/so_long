/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:00:28 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/04 01:16:40 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_new_window(t_position *p)
{
	p->mlx_ptr = mlx_init();
	if (!p->mlx_ptr)
	{
		write(2, "problem with mlx initialization\n", 32);
		exit(EXIT_FAILURE);
	}
	p->row = 0;
	p->col = 0;
	while (p->split[p->row])
	{
		while (p->split[p->row][p->col])
			p->col++;
		p->row++;
	}
	p->win_ptr = mlx_new_window(p->mlx_ptr, (p->col) * 70, (p->row) * 70,
			"My Game");
	if (!p->win_ptr)
	{
		write(2, "could not open the window\n", 26);
		exit(1);
	}
	p->row = 0;
	p->col = 0;
}

void	fill_row(t_position *p)
{
	while (p->split[p->row][p->col])
	{
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->col
			* 70, p->row * 70);
		if (p->split[p->row][p->col] == '1')
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->wall_img_ptr,
				p->col * 70, p->row * 70);
		else if (p->split[p->row][p->col] == 'P')
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->p_down, p->col
				* 70, p->row * 70);
		else if (p->split[p->row][p->col] == '0')
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->col
				* 70, p->row * 70);
		else if (p->split[p->row][p->col] == 'E')
		{
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->closed, p->col
				* 70, p->row * 70);
			p->door_col = p->col;
			p->door_row = p->row;
		}
		else if (p->split[p->row][p->col] == 'C')
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->coin_ptr1, p->col
				* 70, p->row * 70);
		p->col++;
	}
}

void	frames(t_position *p, int col, int row)
{
	if (p->frame == 0)
		first_frame(p, col, row);
	else if (p->frame == 800)
		second_frame(p, col, row);
	else if (p->frame == 1600)
		third_frame(p, col, row);
	else if (p->frame == 2400)
		forth_frame(p, col, row);
	else if (p->frame == 3200)
	{
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, col * 70,
			row * 70);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->coin_ptr5, col * 70,
			row * 70);
	}
	else if (p->frame == 4000)
	{
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, col * 70,
			row * 70);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->coin_ptr6, col * 70,
			row * 70);
	}
}

int	animate_coins(t_position *p)
{
	int	row;
	int	col;

	row = 0;
	while (p->split[row])
	{
		col = 0;
		while (p->split[row][col])
		{
			if (p->split[row][col] == 'C')
				frames(p, col, row);
			col++;
		}
		row++;
	}
	if (p->frame > 4000)
		p->frame = 0;
	p->frame++;
	return (0);
}

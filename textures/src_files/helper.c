/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:26:03 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/05 01:45:03 by mhassani         ###   ########.fr       */
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

void	door_position(t_position *p)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->closed, p->col
		* 70, p->row * 70);
	p->door_col = p->col;
	p->door_row = p->row;
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
		else if (p->split[p->row][p->col] == 'C')
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->coin_ptr, p->col
				* 70, p->row * 70);
		else if (p->split[p->row][p->col] == 'E')
			door_position(p);
		else
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		p->col++;
	}
}

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

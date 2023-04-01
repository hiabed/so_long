/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_coin_when_touch.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:41:21 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/01 20:08:50 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	eat_coin_up(t_position *p)
{
	if (p->split[p->p_row - 1][p->p_col] == 'C')
	{
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->p_col
			* 70, (p->p_row - 1) * 70);
		p->coin_count--;
	}
	if (p->coin_count == 0)
	{
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr,
			p->door_col * 70, p->door_row * 70);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->opened, p->door_col
			* 70, p->door_row * 70);
	}
}

void	eat_coin_down(t_position *p)
{
	if (p->split[p->p_row + 1][p->p_col] == 'C')
	{
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->p_col
			* 70, (p->p_row + 1) * 70);
		p->coin_count--;
	}
	if (p->coin_count == 0)
	{
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr,
			p->door_col * 70, p->door_row * 70);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->opened, p->door_col
			* 70, p->door_row * 70);
	}
}

void	eat_coin_left(t_position *p)
{
	if (p->split[p->p_row][p->p_col - 1] == 'C')
	{
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, (p->p_col
				- 1) * 70, p->p_row * 70);
		p->coin_count--;
	}
	if (p->coin_count == 0)
	{
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr,
			p->door_col * 70, p->door_row * 70);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->opened, p->door_col
			* 70, p->door_row * 70);
	}
}

void	eat_coin_right(t_position *p)
{
	if (p->split[p->p_row][p->p_col + 1] == 'C')
	{
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, (p->p_col
				+ 1) * 70, p->p_row * 70);
		p->coin_count--;
	}
	if (p->coin_count == 0)
	{
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr,
			p->door_col * 70, p->door_row * 70);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->opened, p->door_col
			* 70, p->door_row * 70);
	}
}

int	ft_close(void)
{
	exit(EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:18:01 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/07 22:36:03 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_position *p)
{
	if (p->split[p->p_row - 1][p->p_col] == 'E' && p->coin_count == 0)
	{
		ft_printf("you win");
		exit(EXIT_SUCCESS);
	}
	if (p->split[p->p_row - 1][p->p_col] == 'N')
		you_lost();
	if (p->split[p->p_row - 1][p->p_col] != '1' && p->split[p->p_row
		- 1][p->p_col] != 'E')
	{
		p->split[p->p_row - 1][p->p_col] = 'P';
		p->split[p->p_row][p->p_col] = '0';
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->p_col
			* 70, p->p_row * 70);
		p->p_row--;
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->p_up, p->p_col * 70,
			p->p_row * 70);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->wall_img_ptr, 0, 0);
		mlx_string_put(p->mlx_ptr, p->win_ptr, p->col + 25, p->row, 0xFF0000,
			p->move = ft_itoa(++p->count));
		free(p->move);
	}
	if (p->split[p->p_row - 1][p->p_col] == '1' || p->split[p->p_row
		- 1][p->p_col] == 'E')
		switch_img_up(p);
}

void	move_down(t_position *p)
{
	if (p->split[p->p_row + 1][p->p_col] == 'E' && p->coin_count == 0)
	{
		ft_printf("you win");
		exit(EXIT_SUCCESS);
	}
	if (p->split[p->p_row + 1][p->p_col] == 'N')
		you_lost();
	if (p->split[p->p_row + 1][p->p_col] != '1' && p->split[p->p_row
		+ 1][p->p_col] != 'E')
	{
		p->split[p->p_row + 1][p->p_col] = 'P';
		p->split[p->p_row][p->p_col] = '0';
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->p_col
			* 70, p->p_row * 70);
		p->p_row++;
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->p_down, p->p_col
			* 70, p->p_row * 70);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->wall_img_ptr, 0, 0);
		mlx_string_put(p->mlx_ptr, p->win_ptr, p->col + 25, p->row, 0xFF0000,
			p->move = ft_itoa(++p->count));
		free(p->move);
	}
	if (p->split[p->p_row + 1][p->p_col] == '1' || p->split[p->p_row
		+ 1][p->p_col] == 'E')
		switch_img_down(p);
}

void	move_left(t_position *p)
{
	if (p->split[p->p_row][p->p_col - 1] == 'E' && p->coin_count == 0)
	{
		ft_printf("you win");
		exit(EXIT_SUCCESS);
	}
	if (p->split[p->p_row][p->p_col - 1] == 'N')
		you_lost();
	if (p->split[p->p_row][p->p_col - 1] != '1' && p->split[p->p_row][p->p_col
		- 1] != 'E')
	{
		p->split[p->p_row][p->p_col - 1] = 'P';
		p->split[p->p_row][p->p_col] = '0';
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->p_col
			* 70, p->p_row * 70);
		p->p_col--;
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->p_left, p->p_col
			* 70, p->p_row * 70);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->wall_img_ptr, 0, 0);
		mlx_string_put(p->mlx_ptr, p->win_ptr, p->col + 25, p->row, 0xFF0000,
			p->move = ft_itoa(++p->count));
		free(p->move);
	}
	if (p->split[p->p_row][p->p_col - 1] == '1' || p->split[p->p_row][p->p_col
		- 1] == 'E')
		switch_img_left(p);
}

void	move_right(t_position *p)
{
	if (p->split[p->p_row][p->p_col + 1] == 'E' && p->coin_count == 0)
	{
		ft_printf("you win");
		exit(EXIT_SUCCESS);
	}
	if (p->split[p->p_row][p->p_col + 1] == 'N')
		you_lost();
	if (p->split[p->p_row][p->p_col + 1] != '1' && p->split[p->p_row][p->p_col
		+ 1] != 'E')
	{
		p->split[p->p_row][p->p_col + 1] = 'P';
		p->split[p->p_row][p->p_col] = '0';
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->p_col
			* 70, p->p_row * 70);
		p->p_col++;
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->p_right, p->p_col
			* 70, p->p_row * 70);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->wall_img_ptr, 0, 0);
		mlx_string_put(p->mlx_ptr, p->win_ptr, p->col + 25, p->row, 0xFF0000,
			p->move = ft_itoa(++p->count));
		free(p->move);
	}
	if (p->split[p->p_row][p->p_col + 1] == '1' || p->split[p->p_row][p->p_col
		+ 1] == 'E')
		switch_img_right(p);
}

int	handle_key_press(int keycode, t_position *p)
{
	if (keycode == 13 || keycode == 126)
	{
		eat_coin_up(p);
		move_up(p);
	}
	else if (keycode == 0 || keycode == 123)
	{
		eat_coin_left(p);
		move_left(p);
	}
	else if (keycode == 1 || keycode == 125)
	{
		eat_coin_down(p);
		move_down(p);
	}
	else if (keycode == 2 || keycode == 124)
	{
		eat_coin_right(p);
		move_right(p);
	}
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

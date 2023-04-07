/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:20:03 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/07 22:34:57 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	you_lost(void)
{
	printf("you lost");
	exit(1);
}

void	enemy(t_position *p, int col, int row)
{
	p->n_col = col;
	p->n_row = row;
	n_frames(p);
}

void	door_position(t_position *p)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->closed, p->col * 70,
		p->row * 70);
	p->door_col = p->col;
	p->door_row = p->row;
}

void	frame_1000(t_position *p)
{
	if (p->split[p->n_new_pos + 1][(p->n_col)] == 'P')
		you_lost();
	if (p->split[p->n_new_pos][(p->n_col)] != '1'
		&& p->split[p->n_new_pos][(p->n_col)] != 'E'
		&& p->split[p->n_new_pos][(p->n_col)] != 'C')
	{
		p->split[p->n_new_pos][p->n_col] = '0';
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->n_col
			* 70, (p->n_new_pos) * 70);
		p->split[p->n_new_pos + 1][p->n_col] = 'N';
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->enemy_down, p->n_col
			* 70, (p->n_new_pos + 1) * 70);
	}
}

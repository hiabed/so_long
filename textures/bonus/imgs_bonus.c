/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:06:51 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/07 22:35:23 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	xpm_to_img2(t_position *p)
{
	p->coin_ptr1 = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/coin1.xpm",
			&p->width, &p->height);
	p->coin_ptr2 = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/coin2.xpm",
			&p->width, &p->height);
	p->coin_ptr3 = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/coin3.xpm",
			&p->width, &p->height);
	p->coin_ptr4 = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/coin4.xpm",
			&p->width, &p->height);
	p->coin_ptr5 = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/coin5.xpm",
			&p->width, &p->height);
	p->coin_ptr6 = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/coin6.xpm",
			&p->width, &p->height);
	p->enemy_up = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/enemy_up.xpm",
			&p->width, &p->height);
	p->enemy_down = mlx_xpm_file_to_image(p->mlx_ptr,
			"./textures/enemy_down.xpm", &p->width, &p->height);
}

void	xpm_to_img(t_position *p)
{
	p->space_ptr = mlx_xpm_file_to_image(p->mlx_ptr,
			"./textures/green_background.xpm", &p->width, &p->height);
	p->wall_img_ptr = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/wall.xpm",
			&p->width, &p->height);
	p->p_left = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/left.xpm",
			&p->width, &p->height);
	p->p_right = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/right.xpm",
			&p->width, &p->height);
	p->p_up = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/up.xpm", &p->width,
			&p->height);
	p->p_down = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/down.xpm",
			&p->width, &p->height);
	p->closed = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/closed_door.xpm",
			&p->width, &p->height);
	p->opened = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/opened_door.xpm",
			&p->width, &p->height);
	xpm_to_img2(p);
	if (!p->space_ptr || !p->wall_img_ptr || !p->p_left || !p->p_right
		|| !p->p_up || !p->p_down || !p->coin_ptr1 || !p->coin_ptr2
		|| !p->coin_ptr3 || !p->coin_ptr4 || !p->coin_ptr5 || !p->coin_ptr6
		|| !p->closed || !p->opened)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

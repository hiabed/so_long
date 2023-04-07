/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_p_imgs_to_w_and_e.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:42:02 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/04 21:29:42 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	switch_img_left(t_position *p)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->p_col * 70,
		p->p_row * 70);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->p_left, p->p_col * 70,
		p->p_row * 70);
}

void	switch_img_right(t_position *p)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->p_col * 70,
		p->p_row * 70);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->p_right, p->p_col * 70,
		p->p_row * 70);
}

void	switch_img_up(t_position *p)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->p_col * 70,
		p->p_row * 70);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->p_up, p->p_col * 70,
		p->p_row * 70);
}

void	switch_img_down(t_position *p)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->p_col * 70,
		p->p_row * 70);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->p_down, p->p_col * 70,
		p->p_row * 70);
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
	p->coin_ptr = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/coin.xpm",
			&p->width, &p->height);
	p->closed = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/closed_door.xpm",
			&p->width, &p->height);
	p->opened = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/opened_door.xpm",
			&p->width, &p->height);
	if (!p->space_ptr || !p->wall_img_ptr || !p->p_left || !p->p_right
		|| !p->p_up || !p->p_down || !p->coin_ptr || !p->closed || !p->opened)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

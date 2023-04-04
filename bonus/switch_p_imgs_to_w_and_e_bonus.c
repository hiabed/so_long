/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_p_imgs_to_w_and_e.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:42:02 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/03 23:07:20 by mhassani         ###   ########.fr       */
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

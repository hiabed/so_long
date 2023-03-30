/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:45:12 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/30 01:34:53 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "mlx.h"
# include "read_file.h"

typedef struct s_position
{
	int		count;
	int		coin_count;
	int		p_row;
	int		p_col;
	int		row;
	int		col;
	int		width;
	int		height;
	int		door_col;
	int		door_row;
	void	*space_ptr;
	void	*wall_img_ptr;
	void	*p_left;
	void	*p_right;
	void	*p_up;
	void	*p_down;
	void	*coin_ptr;
	void	*closed;
	void	*opened;
	void	*win_ptr;
	void	*mlx_ptr;
	char	**split;
	char	**map;
}			t_position;

void		move_up(t_position *p);
void		move_down(t_position *p);
void		move_left(t_position *p);
void		move_right(t_position *p);
void		switch_img_left(t_position *p);
void		switch_img_right(t_position *p);
void		switch_img_up(t_position *p);
void		switch_img_down(t_position *p);
void		eat_coin_up(t_position *p);
void		eat_coin_down(t_position *p);
void		eat_coin_left(t_position *p);
void		eat_coin_right(t_position *p);
int			handle_key_press(int keycode, t_position *p);
void		xpm_to_img(t_position *p);
int			ft_close(void);
void		map_clone(int fd, char *s, t_position *map);
void		flood_fill(char **map, int p_row, int p_col);
void		map_clone_check(t_position *p);

#endif
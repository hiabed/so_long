/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:45:12 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/07 22:34:00 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_position
{
	int		n_new_pos;
	int		n_row;
	int		n_col;
	int		enemy_frame;
	int		frame;
	int		color;
	int		fd;
	int		i;
	int		j;
	int		len_string;
	int		count;
	int		coin_count;
	int		c_row;
	int		c_col;
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
	void	*coin_ptr1;
	void	*coin_ptr2;
	void	*coin_ptr3;
	void	*coin_ptr4;
	void	*coin_ptr5;
	void	*coin_ptr6;
	void	*enemy_up;
	void	*enemy_down;
	void	*closed;
	void	*opened;
	void	*win_ptr;
	void	*mlx_ptr;
	char	str;
	char	*move;
	char	**split;
	char	**clone_map;
	char	*buffer;
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
void		check_nl(t_position *map);
void		surrounded(t_position *map);
void		create_new_window(t_position *p);
void		coins_count(t_position *p);
void		fill_row(t_position *p);
void		*ft_calloc(size_t count, size_t size);
char		*read_file(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*read_line(int fd, char *s);
void		ft_free(char *s1, char *s2);
int			animate_coins(t_position *p);
void		first_frame(t_position *p, int col, int row);
void		second_frame(t_position *p, int col, int row);
void		third_frame(t_position *p, int col, int row);
void		forth_frame(t_position *p, int col, int row);
void		you_lost(void);
void		ft_error(void);
void		enemy(t_position *p, int col, int row);
void		door_position(t_position *p);
void		frame_1000(t_position *p);
void		n_frames(t_position *p);

// int			enemy_patrol(t_position *p);

#endif
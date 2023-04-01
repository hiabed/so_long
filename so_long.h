/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:45:12 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/01 21:09:21 by mhassani         ###   ########.fr       */
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
	int		fd;
	int		i;
	int		j;
	int		len_string;
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
char		*line(char *s);
char		*left_str(char *s);
size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_newline(char *s);
char		*read_line(int fd, char *s);
void		ft_free(char *s1, char *s2);

#endif
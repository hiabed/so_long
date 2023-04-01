/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:42:29 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/01 20:20:15 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_to_split(int fd, char *s, t_position *map)
{
	map->j = 0;
	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: could not open file\n");
		exit(1);
	}
	map->buffer = read_file(fd);
	check_nl(map);
	map->split = ft_split(map->buffer, '\n');
	map->i = 0;
	map->len_string = ft_strlen(map->split[map->i]);
	surrounded(map);
	close(fd);
}

void	get_player_position(t_position *p)
{
	int	player_count;

	p->row = 0;
	p->col = 0;
	player_count = 0;
	while (p->split[p->row])
	{
		while (p->split[p->row][p->col])
		{
			if (p->split[p->row][p->col] == 'P')
			{
				p->p_row = p->row;
				p->p_col = p->col;
				player_count++;
			}
			p->col++;
		}
		p->col = 0;
		p->row++;
	}
	if (player_count != 1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	exit_door(t_position *p)
{
	int	door_count;

	p->row = 0;
	p->col = 0;
	door_count = 0;
	while (p->split[p->row])
	{
		while (p->split[p->row][p->col])
		{
			if (p->split[p->row][p->col] == 'E')
				door_count++;
			p->col++;
		}
		p->col = 0;
		p->row++;
	}
	if (door_count != 1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	so_long(t_position *p)
{
	get_player_position(p);
	create_new_window(p);
	xpm_to_img(p);
	while (p->split[p->row])
	{
		fill_row(p);
		p->col = 0;
		p->row++;
	}
	exit_door(p);
	flood_fill(p->map, p->p_row, p->p_col);
	map_clone_check(p);
	coins_count(p);
}

int	main(int ac, char *av[])
{
	int			fd;
	t_position	*p;

	p = malloc(sizeof(t_position));
	fd = 0;
	if (ac != 2)
	{
		write(2, "you should enter 2 arguments\n", 29);
		exit(EXIT_FAILURE);
	}
	read_to_split(fd, av[1], p);
	map_clone(fd, av[1], p);
	so_long(p);
	mlx_key_hook(p->win_ptr, handle_key_press, p);
	mlx_hook(p->win_ptr, 17, 0, ft_close, NULL);
	mlx_loop(p->mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:42:29 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/30 03:21:32 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_to_split(int fd, char *s, t_position *map)
{
	int		i;
	char	*buffer;
	int		len_string;

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: could not open file\n");
		exit(1);
	}
	buffer = read_file(fd);
	map->split = ft_split(buffer, '\n');
	len_string = ft_strlen(map->split[i]);
	while (map->split[i])
	{
		if (map->split[0][0] == '\n')
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		if (ft_strlen(map->split[i]) != (size_t)len_string)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
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

void	coins_count(t_position *p)
{
	int	i;

	i = 0;
	p->row = 0;
	p->col = 0;
	while (p->split[p->row])
	{
		while (p->split[p->row][p->col])
		{
			if (p->split[p->row][p->col] == 'C')
				p->coin_count = ++i;
			p->col++;
		}
		p->col = 0;
		p->row++;
	}
	if (i == 0)
	{
		write(2, "Error\n", 6);
		write(2, "There is no coins in the map\n", 29);
		exit(EXIT_FAILURE);
	}
}

void	fill_row(t_position *p)
{
	while (p->split[p->row][p->col])
	{
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->col
				* 70, p->row * 70);
		if (p->split[p->row][p->col] == '1')
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->wall_img_ptr,
					p->col * 70, p->row * 70);
		else if (p->split[p->row][p->col] == 'P')
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->p_down, p->col
					* 70, p->row * 70);
		else if (p->split[p->row][p->col] == '0')
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->space_ptr, p->col
					* 70, p->row * 70);
		else if (p->split[p->row][p->col] == 'C')
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->coin_ptr, p->col
					* 70, p->row * 70);
		else if (p->split[p->row][p->col] == 'E')
		{
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->closed, p->col
					* 70, p->row * 70);
			p->door_col = p->col;
			p->door_row = p->row;
		}
		p->col++;
	}
}

void	create_new_window(t_position *p)
{
	p->mlx_ptr = mlx_init();
	if (!p->mlx_ptr)
	{
		ft_printf("problem with mlx initialization");
		exit(EXIT_FAILURE);
	}
	p->row = 0;
	p->col = 0;
	while (p->split[p->row])
	{
		while (p->split[p->row][p->col])
			p->col++;
		p->row++;
	}
	p->win_ptr = mlx_new_window(p->mlx_ptr, (p->col) * 70, (p->row) * 70,
			"My Game");
	if (!p->win_ptr)
	{
		ft_printf("could not open the window");
		exit(1);
	}
	p->row = 0;
	p->col = 0;
}

int	main(int ac, char *av[])
{
	int			fd;
	t_position	*p;

	p = malloc(sizeof(t_position));
	fd = 0;
	if (ac != 2)
	{
		printf("you should enter 2 arguments");
		exit(EXIT_FAILURE);
	}
	read_to_split(fd, av[1], p);
	map_clone(fd, av[1], p);
	get_player_position(p);
	flood_fill(p->map, p->p_row, p->p_col);
	create_new_window(p);
	xpm_to_img(p);
	while (p->split[p->row])
	{
		fill_row(p);
		p->col = 0;
		p->row++;
	}
	exit_door(p);
	map_clone_check(p);
	coins_count(p);
	mlx_key_hook(p->win_ptr, handle_key_press, p);
	mlx_hook(p->win_ptr, 17, 0, ft_close, NULL);
	mlx_loop(p->mlx_ptr);
}

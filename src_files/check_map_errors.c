/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:32:12 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/05 01:54:54 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_clone(int fd, char *s, t_position *map)
{
	char	*buffer;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\n", 6);
		write(2, "could not open file\n", 20);
		exit(1);
	}
	buffer = read_file(fd);
	map->clone_map = ft_split(buffer, '\n');
	free(buffer);
	close(fd);
}

void	flood_fill(char **map, int p_row, int p_col)
{
	if ((map[p_row][p_col] == '*' || map[p_row][p_col] == 'E'
			|| map[p_row][p_col] == '1'))
		return ;
	map[p_row][p_col] = '*';
	flood_fill(map, p_row + 1, p_col);
	flood_fill(map, p_row - 1, p_col);
	flood_fill(map, p_row, p_col + 1);
	flood_fill(map, p_row, p_col - 1);
}

void	map_clone_check(t_position *p)
{
	p->row = 0;
	p->col = 0;
	while (p->clone_map[p->row])
	{
		while (p->clone_map[p->row][p->col])
		{
			if (p->clone_map[p->row][p->col] == 'C')
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			p->col++;
		}
		p->col = 0;
		p->row++;
	}
	if (p->clone_map[p->door_row + 1][p->door_col] != '*'
		&& p->clone_map[p->door_row - 1][p->door_col] != '*'
		&& p->clone_map[p->door_row][p->door_col + 1] != '*'
		&& p->clone_map[p->door_row][p->door_col - 1] != '*')
	{
		write(2, "Error\n", 6);
		write(2, "The player can't reach the door\n", 32);
		exit(EXIT_FAILURE);
	}
}

void	check_nl(t_position *map)
{
	if (!map->buffer)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (map->buffer[0] == '\n')
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	map->i = 0;
	while (map->buffer[map->i])
	{
		if (map->buffer[map->i] == '\n' && map->buffer[map->i + 1] == '\n')
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		map->i++;
	}
	if (map->buffer[map->i - 1] == '\n')
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	surrounded(t_position *map)
{
	while (map->split[map->i])
	{
		if (map->split[map->i][0] != '1' || map->split[map->i][map->len_string
			- 1] != '1')
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		if (ft_strlen(map->split[map->i]) != (size_t)map->len_string)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		map->i++;
	}
	while (map->split[0][map->j] && map->split[map->i - 1][map->j])
	{
		if (map->split[map->i - 1][map->j] != '1'
			|| map->split[0][map->j] != '1')
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		map->j++;
	}
}

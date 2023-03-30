/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:32:12 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/30 01:49:46 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_clone(int fd, char *s, t_position *map)
{
	char	*buffer;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: could not open file\n");
		exit(1);
	}
	buffer = read_file(fd);
	map->map = ft_split(buffer, '\n');
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
	while (p->map[p->row])
	{
		while (p->map[p->row][p->col])
		{
			if (p->map[p->row][p->col] == 'C')
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			p->col++;
		}
		p->col = 0;
		p->row++;
	}
	if (p->map[p->door_row + 1][p->door_col] == '1' && p->map[p->door_row
		- 1][p->door_col] == '1' && p->map[p->door_row][p->door_col + 1] == '1'
		&& p->map[p->door_row][p->door_col - 1] == '1')
	{
		write(2, "Error\n", 10);
		write(2, "The player can't reach the door\n", 32);
		exit(EXIT_FAILURE);
	}
}
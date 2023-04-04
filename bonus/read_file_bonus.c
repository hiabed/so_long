/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:36:49 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/01 20:09:05 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

char	*read_line(int fd, char *stat)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = malloc((size_t)(BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			ft_free(stat, buffer);
			return (NULL);
		}
		if (read_bytes == 0 && (stat == 0 || stat[0] == 0))
		{
			ft_free(stat, buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stat = ft_strjoin(stat, buffer);
	}
	free(buffer);
	return (stat);
}

char	*read_file(int fd)
{
	char		*str;
	static char	*stat;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_line(fd, stat);
	if (!str)
		return (NULL);
	return (str);
}

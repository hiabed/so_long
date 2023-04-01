/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:36:32 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/01 20:09:01 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*p;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	i = 0;
	p = malloc(count * size);
	if (!p)
		return (NULL);
	while (i < count * size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s2)
		return (NULL);
	newstr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

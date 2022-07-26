/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:06:19 by jwee              #+#    #+#             */
/*   Updated: 2022/07/26 15:26:19 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t len)
{
	size_t			i;
	unsigned char	*ps;

	i = 0;
	ps = s;
	while (i < len)
	{
		ps[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*temp;
	const size_t	size_max = 0 - 1;

	if (size && count > size_max / size)
		return (NULL);
	if (!size || !count)
	{
		size = 1;
		count = 1;
	}
	temp = (char *)malloc(count * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, (count * size));
	return ((void *)temp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*save;
	char		*result;
	int			slen;
	ssize_t		i;

	i = 0;
	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (!ft_strchr(buff, '\n'))
	{
		if (read(fd, buff, BUFFER_SIZE) <= 0)
			break;
		save = ft_strjoin(save, buff);
	}
	i = 0;
	if (!save[i])
		return (0);
	while (save[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 1));
	slen = ft_strlen(save);
	ft_strlcpy(result, save, i + 1);
	if (strchr(save, '\n'))
		save = ft_substr(save, i + 1, slen);
	result[i] = '\n';
	return (result);
}

#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = malloc(sizeof(char) * 4);
	line[0] = '1';
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	free (line);
	close (fd);
	return (0);
}

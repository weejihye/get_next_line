/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:18:06 by jwee              #+#    #+#             */
/*   Updated: 2022/08/02 17:22:18 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*pb;

	i = 0;
	pb = b;
	while (i < len)
	{
		pb[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*save;
	char		*result;
	int			rsize;
	size_t		i;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	rsize = read(fd, buff, BUFFER_SIZE);
	while (rsize)
	{
		save = ft_strjoin(save, buff);
		if (ft_strchr(buff, '\n') || rsize == 0)
			break ;
		rsize = read(fd, buff, BUFFER_SIZE);
	}
	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	result = malloc(sizeof(char) * (i + 2));
	if (ft_strchr(save, '\n'))
	{
		ft_strlcpy(result, save, i + 1);
		result[i] = '\n';
		result[i + 1] = '\0';
		save = save + (i + 1);
	}
	else if (!ft_strchr(save, '\n') && save[0])
	{
		ft_strlcpy(result, save, i + 1);
		save = NULL;
	}
	return (result);
}

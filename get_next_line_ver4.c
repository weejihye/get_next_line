/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ver4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:18:06 by jwee              #+#    #+#             */
/*   Updated: 2022/08/02 18:20:29 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*ft_strdup(const char *s1)
{
	int				i;
	const int		slen = ft_strlen(s1);
	char			*ps1;

	ps1 = (char *)malloc(sizeof(char) * (slen + 1));
	if (!ps1)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		ps1[i] = s1[i];
		i++;
	}
	ps1[i] = '\0';
	return (ps1);
}

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
	char		*temp;
	int			rsize;
	size_t		i;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	rsize = 1;
	while (rsize)
	{
		rsize = read(fd, buff, BUFFER_SIZE);
		if (rsize == -1)
			break ;
		else if (rsize == 0)
			break ;
		buff[rsize] = '\0';
		if (!result)
			result = ft_strdup("");
		temp = result;
		result = ft_strjoin(temp, buff);
		if (!result)
			return (NULL);
		free(temp);
		temp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	buff = NULL;
	if (!result)
		return (NULL);
	i = 0;
	while (result[i] != '\n' && result[i] != '\0')
		i++;
	save = ft_substr(result, i + 1, ft_strlen(result) - i);
	if (!save)
		return (NULL);
	if (save[0] == '\0')
	{
		free(save);
		save = NULL;
	}
	result[i + 1] = '\0';
	return (result);
}

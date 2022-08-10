/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:36:23 by jwee              #+#    #+#             */
/*   Updated: 2022/08/10 19:09:52 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <string.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	const size_t	slen = ft_strlen(src);

	i = 0;
	if (!src)
		return (0);
	if (!dstsize)
		return (slen);
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	char			*ps;
	unsigned char	uc;

	if (!s)
		return (0);
	ps = (char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (ps[i])
	{
		if (ps[i] == uc)
			return (ps + i);
		i++;
	}
	if (ps[i] == uc)
		return (ps + i);
	return (0);
}

char	*ft_strjoin(char *save, char *buff)
{
	char	*temp;

	if (!save)
	{
		save = malloc (1);
		save[0] = '\0';
	}
	temp = (char *)malloc((ft_strlen(save) + ft_strlen(buff) + 1)
			* sizeof(char));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, save, ft_strlen(save) + 1);
	ft_strlcpy(temp + ft_strlen(save), buff, ft_strlen(buff) + 1);
	free(save);
	return (temp);
}

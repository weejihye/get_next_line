/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:36:23 by jwee              #+#    #+#             */
/*   Updated: 2022/08/04 21:21:26 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_bonus.h"
#include <string.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	const size_t	slen = ft_strlen(src);

	i = 0;
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

char	*ft_strjoin(char *save, char *s2)
{
	int		len1;
	int		len2;
	char	*temp;
	int		i;

	len1 = ft_strlen(save);
	len2 = ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!temp)
		return (NULL);
	i = 0;
	ft_strlcpy(temp, save, len1 + 1);
	ft_strlcpy(temp + len1, s2, len2 + 1);
	free(save);
	return (temp);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:34:35 by jwee              #+#    #+#             */
/*   Updated: 2022/08/10 19:06:03 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line_bonus.h"

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

	if (!src)
		return (0);
	if (!dstsize)
		return (slen);
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
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

void	ft_clear_node(t_list **head, int fd)
{
	t_list	*save_temp;
	t_list	*save_prev;

	save_prev = *head;
	if (save_prev->fd == fd)
	{
		save_prev = save_prev->next;
		free(*head);
		(*head) = save_prev;
		return ;
	}
	while (save_prev->next && save_prev->next->fd != fd)
		save_prev = save_prev->next;
	save_temp = save_prev->next;
	if (save_temp->fd == fd)
	{
		save_prev->next = save_temp->next;
		free(save_temp);
		return ;
	}
}

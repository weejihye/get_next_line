/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:08:22 by jwee              #+#    #+#             */
/*   Updated: 2022/08/10 19:07:33 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include <stdio.h> 
#include "get_next_line_bonus.h"

static t_list	*ft_lstnew_addback(t_list **head, int fd)
{
	t_list	*temp;
	t_list	*temp2;

	temp = malloc(sizeof(t_list));
	if (!temp)
		return (0);
	temp->fd = fd;
	temp->next = NULL;
	if (!*head)
	{
		*head = temp;
		return (temp);
	}
	else
	{
		temp2 = *head;
		while (temp2->next)
			temp2 = temp2->next;
		temp2->next = temp;
		return (temp);
	}
}

static char	*ft_get_buff(int fd, char *save)
{
	char	*buff;
	int		rsize;

	rsize = 1;
	while (!ft_strchr(save, '\n') && rsize > 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (0);
		rsize = read(fd, buff, BUFFER_SIZE);
		if (rsize == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rsize] = '\0';
		save = ft_strjoin(save, buff);
		free(buff);
	}
	return (save);
}

static char	*ft_get_result(char *save)
{
	int		i;
	char	*temp;

	if (!save)
		return (NULL);
	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, save, i + 1);
	return (temp);
}

static char	*ft_get_save(char *save, t_list **head, int fd)
{
	char	*temp;
	int		i;
	int		j;

	if (!ft_strchr(save, '\n'))
	{
		free(save);
		ft_clear_node(head, fd);
		return (NULL);
	}
	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	temp = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		temp[j++] = save[i++];
	temp[j] = '\0';
	free(save);
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*result;
	static t_list	*head;
	t_list			*save;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = head;
	while (save && save->fd != fd)
		save = save->next;
	if (!save)
	{
		save = ft_lstnew_addback(&head, fd);
		save->content = NULL;
	}
	save->content = ft_get_buff(fd, save->content);
	result = ft_get_result(save->content);
	if (ft_strlen(result))
		save->content = ft_get_save(save->content, &head, fd);
	else
	{
		free(save->content);
		ft_clear_node(&head, fd);
	}
	return (result);
}

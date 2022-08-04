/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:36:04 by jwee              #+#    #+#             */
/*   Updated: 2022/08/04 22:18:00 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(int fd, t_list *save)
{
	char	*buff;
	int		rsize;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	rsize = 1;
	while (!ft_strchr(buff, '\n') && rsize)
	{
		rsize = read(fd, buff, BUFFER_SIZE);
		if (rsize < 0)
		{
			free(buff);
			free(save);
			return (NULL);
		}
		buff[rsize] = '\0';
		save->content = ft_strjoin(save->content, buff);
		if(!save->content)
		{
			free(save);
			return (NULL);
		}
	}
	free(buff);
	return (save->content);
}

char	*ft_get_result(char *save)
{
	int		i;
	char	*temp;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		temp[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		temp[i] = save[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_get_save(t_list *save)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (save->content[i] != '\n' && save->content[i])
		i++;
	if (!save->content[i])
	{
		free(save->content);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(save->content) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (save->content[i])
		temp[j++] = save->content[i++];
	temp[j] = '\0';
	free(save->content);
	return (temp);
}

t_list	*ft_lstadd_back(t_list **head, int fd)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	temp->fd = fd;
	temp->next = NULL;
	if (!*head)
	{
		*head = temp;
		return (temp);
	}
	while ((*head)->next)
		*head = (*head)->next;
	(*head)->next = temp;
	return (temp);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*save;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = head;
	while (save && save->fd != fd)
		save = save->next;
	if (!save)
		save = ft_lstadd_back(&head, fd);
	save->content = ft_get_line(fd, save);
	if (!save->content)
		return (NULL);
	result = ft_get_result(save->content);
	save->content = ft_get_save(save);
	return (result);
}

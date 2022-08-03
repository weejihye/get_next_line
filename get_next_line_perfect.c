/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:55:21 by jwee              #+#    #+#             */
/*   Updated: 2022/08/02 17:56:44 by jwee             ###   ########.fr       */
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

static char *ft_read_line(int fd, char *buf, char *backup)
{
  int   count;
  char  *temp_pointer;

  count = 1;
  while (count)
  {
    count = read(fd, buf, BUFFER_SIZE);
    if (count == -1)
      return (0);
    else if (count == 0)
      break ;
    buf[count] = '\0';
    if (!backup)
      backup = ft_strdup("");
    temp_pointer = backup;
    backup = ft_strjoin(temp_pointer, buf);
    if (!backup)
      return (NULL);
    free(temp_pointer);
    temp_pointer = NULL;
    if (ft_strchr(buf, '\n'))
      break ;
  }
  return (backup);
}

static char *ft_extract(char *line)
{
  int   i;
  char  *result;

  i = 0;
  while (line[i] != '\n' && line[i] != '\0')
    i++;
  if (line[i] == '\0')
    return (0);
  result = ft_substr(line, i + 1, ft_strlen(line) - i);
  if (!result)
    return (NULL);
  if (result[0] == '\0')
  {
    free(result);
    result = NULL;
    return (NULL);
  }
  line[i + 1] = '\0';
  return (result);
}

char  *get_next_line(int fd)
{
  char    *line;
  char    *buf;
  static char *backup;

  if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
  buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
  if (!buf)
    return (NULL);
  line = ft_read_line(fd, buf, backup);
  free(buf);
  buf = NULL;
  if (!line)
    return (NULL);
  backup = ft_extract(line);
  return (line);
}

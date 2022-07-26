/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:58:43 by jwee              #+#    #+#             */
/*   Updated: 2022/07/20 19:12:42 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(const char *s, char c)
{
	int	i;
	int	wcount;

	i = 0;
	wcount = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				wcount++;
			i++;
		}
	}
	return (wcount);
}

static int	ft_lcount(const char *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

static char	**ft_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static char	*ft_strndup(const char *s, char c, int i)
{
	char	*temp;
	int		lcount;
	int		j;

	lcount = ft_lcount(s, c, i);
	if (lcount == 0)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (lcount + 1));
	if (temp == 0)
		return (NULL);
	j = 0;
	while (j < lcount)
	{
		temp[j] = s[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	return (temp);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		wcount;
	int		count;
	int		i;

	i = 0;
	count = 0;
	wcount = ft_wcount(s, c);
	result = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!result)
		return (NULL);
	while (s[i] && count < wcount)
	{
		while (s[i] == c)
			i++;
		result[count] = ft_strndup(s, c, i);
		if (result[count++] == 0)
			return (ft_free(result));
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	result[count] = NULL;
	return (result);
}

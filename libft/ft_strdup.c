/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:31:54 by jwee              #+#    #+#             */
/*   Updated: 2022/07/14 19:29:46 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		slen;
	char	*ps1;

	slen = ft_strlen(s1);
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

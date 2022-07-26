/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:09:46 by jwee              #+#    #+#             */
/*   Updated: 2022/07/14 20:22:25 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

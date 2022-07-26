/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:38:23 by jwee              #+#    #+#             */
/*   Updated: 2022/07/14 21:03:47 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*ps;
	unsigned char	uc;

	uc = (unsigned char) c;
	ps = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (ps[i] == uc)
			return (ps + i);
		if (i == 0)
			break ;
		i--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:05:02 by jwee              #+#    #+#             */
/*   Updated: 2022/07/20 19:12:15 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*temp;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!temp)
		return (NULL);
	i = 0;
	ft_strlcpy(temp, s1, len1 + 1);
	ft_strlcat(temp + len1, s2, len2 + 1);
	return (temp);
}

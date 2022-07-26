#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
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
	size_t				i;
	char				*ps;
	const unsigned char	uc = c;

	ps = (char *)s;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	const int		len1 = ft_strlen(s1);
	const int		len2 = ft_strlen(s2);
	char			*temp;
	int				i;

	temp = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!temp)
		return (NULL);
	i = 0;
	ft_strlcpy(temp, s1, len1 + 1);
	ft_strlcpy(temp + len1, s2, len2 + 1);
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	while (i < len && s[start + i])
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
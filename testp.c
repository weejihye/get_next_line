#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	ft_strlen(char *buff)
{
	int	i;
	i = 0;
	while(buff[i] != '\0')
		i++;
	return (i);
}

int	main(void)
{
	int		fd;
	char	*buff;
	int		len;

	fd = open("test.txt", O_RDONLY);
	buff = malloc(sizeof(char) * 4);
	read(fd, buff, 4);
	len = ft_strlen(buff);
	printf("%s", buff);
	printf("%d", len);
}

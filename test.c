#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*buff;
	int		fd;
	int		rsize;
	int		count;

	fd = open("test.txt", O_RDONLY);
	count = 10;
	rsize = 1;
	while(rsize)
	{
		buff = malloc(1);
		rsize = read(fd, buff, 4);
		if (rsize ==0)
			return (0);
		printf("===buff===\n%s", buff);
		memset(buff, 0, 4);
	}
}

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		index;
	char	*gnl;

	fd = open("file.txt", O_RDONLY);
	index = 15;
	while (index--)
	{
		gnl = get_next_line(fd);
		if (gnl)
			printf("%s", gnl);
		free(gnl);
	}
	close(fd);
}

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		index;
	char	*gnl;

	fd = open("test.txt", O_RDONLY);
	index = 9;
	while (index--)
	{
		gnl = get_next_line(fd);
		if (gnl)
			printf("%s\n", gnl);
		else
			printf("%s", "NULL");
		free(gnl);
	}
	close(fd);
}

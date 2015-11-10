#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	setbuf(stdout, NULL);
	char	**line = (char **)malloc(sizeof(**line));
	int	fd;


	fd = open("test.txt", O_RDONLY);

		get_next_line(0, line);
		printf("\nLINE: %s", *line);

		get_next_line(fd, line);
		printf("\nLINE1: %s", *line);
	
		get_next_line(0, line);
		printf("\nLINE: %s", *line);

		get_next_line(fd, line);
		printf("\nLINE1: %s", *line);
	
	close(fd);

	return (0);
}

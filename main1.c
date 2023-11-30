#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	fd = open("hassan.txt", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
		printf("%s", line);
	free(line);
	close(fd);
	return 0;
}
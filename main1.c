#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd1, fd2;
	char *line1, *line2;

	// Open the first file
	fd1 = open("hassan.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("Error opening file1.txt");
		return 1;
	}

	// Open the second file
	fd2 = open("bakrim.txt", O_RDONLY);
	if (fd2 < 0)
	{
		perror("Error opening file2.txt");
		close(fd1);
		return 1;
	}

	// Read lines from the first file
	line1 = get_next_line(fd1);
	while (line1 != NULL)
	{
		printf("Line from hassan.txt: %s\n", line1);
		free(line1);
		line1 = get_next_line(fd1);
	}

	// Read lines from the second file
	line2 = get_next_line(fd2);
	while (line2 != NULL)
	{
		printf("Line from bakrim.txt: %s\n", line2);
		free(line2);
		line2 = get_next_line(fd2);
	}

	// Close the file descriptors
	close(fd1);
	close(fd2);

	return 0;
}
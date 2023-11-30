#include <stdio.h>

//#include "get_next_line.h"
#include "get_next_line_bonus.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void) {
    char *line;
    int i;
    int f[1024];
    // Open the file for reading
    int fd1 = open("hassan.txt", O_RDONLY);
    int fd2 = open("bakrim.txt", O_RDONLY);
    int fd3  = open("hassan.txt", O_RDONLY);
    int fd4 = open("bakrim.txt", O_RDONLY);
    
    f[0] = fd1;
    f[1] = fd2;
    f[2] = fd3;
    f[3] = fd4;
    i = 0;
    while (i < 4)
    {
        while (1) {
            line = get_next_line(f[i]);
            printf("%s", line);
            if (line == NULL)
                 break;
        }
        i++;
    }
    free(line);
    close(f[i]);
    return 0;
}

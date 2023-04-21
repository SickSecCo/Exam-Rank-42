#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
	unsigned int i = 0;
	int check_read;
	char c;
	char *buffer = NULL;
	if (fd < 0)
		return NULL;
	buffer = malloc(sizeof(char) * 2000000000);
	while ((check_read = read(fd, &c, 1)) > 0)
	{
		buffer[i] = c;
		i++;
		if (c == '\n')
			break;
	}
	if ((!buffer[0] && check_read != -1) || check_read == -1)
	{
		free(buffer);
		return NULL;
	}
	i++;
	buffer[i] = '\0';
	return (buffer);
}

int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}

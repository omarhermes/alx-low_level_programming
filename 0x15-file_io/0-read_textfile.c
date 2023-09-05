#include "main.h"

/**
 * read_textfile - reads text from a file and print it
 * @filename: name of file to read
 * @letters: number of bytes to read
 *
 * Return: number bytes read/printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char buf[READ_BUF_SIZE * 8];
	ssize_t fd;
	ssize_t bytes;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!filename || !letters)
		return (0);
	bytes = read(fd, &buf[0], letters);
	bytes = write(STDOUT_FILENO, &buf[0], bytes);
	close(fd);
	return (bytes);
}

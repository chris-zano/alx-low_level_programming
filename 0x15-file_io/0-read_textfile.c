#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - reads a file and prints it to POSIX standard output
 * @filename: name if the file to be read
 * @letters: number of letters it should read and print
 * Return: returns the actual number of letters it could read and print
 *	if the file can not be opened or read, return 0
 *	if filename is NULL return 0
 *	if write fails or does not write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd;
	ssize_t read_f;
	ssize_t byte_w;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(buffer) * letters);

	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY) ;
	read_f = read(fd, buffer, letters);
	byte_w = write(STDOUT_FILENO, buffer, read_f);

	if (fd == -1 || read_f == -1 || byte_w == -1)
	{
		free(buffer);
		return (0);
	}
	if (byte_w != read_f)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(fd);

	return (byte_w);
}

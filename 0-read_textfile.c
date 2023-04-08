#include "main.h"

#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

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
	return (0);
}

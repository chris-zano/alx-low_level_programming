#include "main.h"

#define BUFFER_SIZE 1024
void _close(int read, int write);
void _exit_handler(char *argv[], int code);

/**
 * main - copies the content of a file to another file
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int fd_file_from, fd_file_to;
	int bytes_r, bytes_w;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		_exit_handler(argv, 97);

	fd_file_from = open(argv[1], O_RDONLY);

	if (fd_file_from == -1)
		_exit_handler(argv, 98);

	fd_file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd_file_to == -1)
		_exit_handler(argv, 99);

	while ((bytes_r = read(fd_file_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_w = write(fd_file_to, buffer, bytes_r);

		if (bytes_w != bytes_r)
			_exit_handler(argv, 99);
	}

	if (bytes_r == -1)
		_exit_handler(argv, 98);

	_close(fd_file_from, fd_file_to);

	return (0);
}

/**
 * _close - closes a file opened by open()
 * @read: file from which data is read
 * @write: file to which data is written
 * Return: void
 */

void _close(int read, int write)
{
	int val;

	val = close(read);

	if (val == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", read);
		exit(100);
	}

	val = close(write);

	if (val == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", write);
		exit(100);
	}
}

/**
 * _exit_handler - exits a process with an exit code
 * @argv: argument vector
 * @code: error code
 * Return: void
 */

void _exit_handler(char *argv[], int code)
{
	if (code == 97)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	if (code == 98)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (code == 99)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

#include "main.h"

#define BUFFER_SIZE 1024

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

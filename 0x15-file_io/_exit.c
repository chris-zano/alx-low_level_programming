#include "main.h"

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
		dprintf(STDERR_FILENO, "Error: Can't read from "
				"file %s\n", argv[1]);
		exit(98);
	}

	if (code == 99)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

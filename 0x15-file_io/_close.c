#include "main.h"

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
		dprintf(STDERR_FILENO, "Error: Can't close fd"
				" %d\n", read);
		exit(100);
	}

	val = close(write);

	if (val == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd"
				" %d\n", write);
		exit(100);
	}
}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * create_file - a function that creates a file
 * @filename: name of the file
 * @text_content: null terminated string to write to the file
 * Return: 1 on success
 * -1 on failure (file can not be created,
 *  file can not be written,
 *  write “fails”, etc…)
 * The created file must have those permissions: rw-------.
 * If the file already exists, do not change the permissions.
 * if the file already exists, truncate it
 * if filename is NULL return -1
 * if text_content is NULL create an empty file
 */

int create_file(const char *filename, char *text_content)
{
	int len = 0, i = 0;
	int fd;
	char *buffer;

	if (text_content != NULL)
		while (text_content[i] != '\0')
		{
			len++;
			i++;
		}

	buffer = malloc(sizeof(buffer) * len);

	if (buffer == NULL)
		return (-1);

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);
	fd = write(fd, text_content, len);

	if (fd == -1)
		return (-1);

	close(fd);
	return (1);
}

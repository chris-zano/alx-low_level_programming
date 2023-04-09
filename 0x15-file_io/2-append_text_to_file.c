#include "main.h"
#include <unistd.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: Null terminated string to add to the end of the file
 * Return: 1 on success and -1 on failure
 * Do not create the file if it does not exist
 * If filename is NULL return -1
 * If text_content is NULL, do not add anything to the file.
 * Return 1 if the file exists and -1 if the file does not exist
 *	:or if you do not have the required permissions to write the file
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int length = 0;
	int index = 0;
	int fd;
	int byte_s;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
	{
		while (text_content[index] != '\0')
		{
			length++;
			index++;
		}
	}

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	byte_s = write(fd, text_content, length);

	if (byte_s == -1)
		return (-1);

	close(fd);
	return (1);
}

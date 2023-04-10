#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>


/**
 * display - display function for displaying Magic, Class, Data,
 *  Version, OS/ABI, ABI Version, Type, Entry point address
 * @label: label for what to display
 * @value: corresponding display value
 * Return: void
*/
void display(const char *label, const char *value)
{
printf("  %s: %-32s\n", label, value);
}

/**
 * display_hex - displays a hexadecimal string and a null terminator
 * @label: a label that is displayed before the hexadecimal number
 * @hex: a pointer to an array of bytes for the hexadecimal number
 * @len: length of the hexadecimal number.
 * Return: void
 */
void display_hex(const char *label, unsigned char *hex, int len)
{
char *hex_string;
char buffer[3];
int i;

buffer[2] = '\0';
len = len * 3 + 1;
hex_string = malloc(sizeof(char *) * len);

for (i = 0; i < len; i++)
{
sprintf(buffer, "%02x ", hex[i]);
strncpy(&hex_string[i * 3], buffer, 3);
}
hex_string[len * 3] = '\0';
printf("  %s: %s\n", label, hex_string);
}

/**
 * display_header - displays the header
 * @header: reference to the header section
 * Return: void
 */
void display_header(Elf64_Ehdr *header)
{
printf("ELF Header:\n");
display_hex("Magic", header->e_ident, EI_NIDENT);
display("Class", (header->e_ident[EI_CLASS] == ELFCLASS32) ?
"ELF32" : "ELF64");
display("Data", (header->e_ident[EI_DATA] == ELFDATA2LSB) ?
"2's complement, little endian" :
(header->e_ident[EI_DATA] == ELFDATA2MSB) ? "2's complement, "
"big endian" : "Invalid");
display("Version", (header->e_ident[EI_VERSION] == EV_CURRENT) ?
"Current" : "Invalid");
display("OS/ABI", (header->e_ident[EI_OSABI] <= 16) ?
elf_osabi[header->e_ident[EI_OSABI]] : "Unknown");
display("ABI Version", header->e_ident[EI_ABIVERSION] >= 0 ?
elf_abiversion[header->e_ident[EI_ABIVERSION]] : "Unknown");
display("Type", (header->e_type >= ET_NONE &&
header->e_type <= ET_LOPROC) ? elf_type[header->e_type] : "Unknown");
display("Entry point address", header->e_entry >= 0 ?
elf_addr[header->e_entry] : "Unknown");
}


/**
 * main - displays the information contained in the ELF header
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 Always
*/
int main(int argc, char **argv)
{
int fd, ret;
Elf64_Ehdr header;
unsigned char magic[] = {0x7f, 'E', 'L', 'F'};

if (argc != 2)
{
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
fprintf(stderr, "Error: could not open file '%s'\n", argv[1]);
exit(98);
}

ret = read(fd, &header, sizeof(header));
if (ret != sizeof(header) ||
memcmp(header.e_ident, magic, sizeof(magic)) != 0)
{
fprintf(stderr, "Error: not an ELF file\n");
exit(98);
}

display_header(&header);

close(fd);

return (0);
}


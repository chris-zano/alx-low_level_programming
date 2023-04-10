#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * display_value - displays the osabi, class, version and type of ELF files
 * @name: name of the value
 * @values: possible values for name
 * @value: value for name
 * Return: void
*/
void display_value(const char *name, const char **values, int value)
{
printf("  %s: %s\n", name, values[value]);
}

/**
 * display_magic - displays the magic number bytes of an elf
 * @magic: ponter to the number of bytes
*/
void display_magic(unsigned char *magic)
{
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
printf("%02x ", magic[i]);
printf("\n");
}


/**
 * display_header - displays the header
 * @header: reference to the header section
 * Return: void
*/
void display_header(Elf64_Ehdr *header)
{
char *class_str[] = {"None", "ELF32", "ELF64"};
char *data_str[] = {"None", "2's complement, little endian",
"2's complement, big endian"};
char *version_str[] = {"Invalid", "Current", "Invalid", "Invalid", "Invalid",
"Invalid", "Invalid", "Invalid", "Invalid", "Invalid", "Invalid", "Invalid",
"Invalid", "Invalid", "Invalid", "Invalid"};
char *osabi_str[] = {"UNIX - System V", "HP-UX", "NetBSD", "Linux", "GNU Hurd",
"Solaris", "AIX", "IRIX", "FreeBSD", "Tru64", "Novell Modesto",
"OpenBSD", "OpenVMS", "NonStop Kernel", "AROS", "Fenix OS", "CloudABI"};
char *type_str[] = {"None", "Relocatable", "Executable", "Shared object",
"Core", "Processor-specific"};

printf("ELF Header:\n");
display_magic(header->e_ident);
display_value("Class", class_str, header->e_ident[EI_CLASS]);
display_value("Data", data_str, header->e_ident[EI_DATA]);
display_value("Version", version_str, header->e_ident[EI_VERSION]);
display_value("OS/ABI", osabi_str, header->e_ident[EI_OSABI]);
printf("  ABI Version:                       %d\n",
header->e_ident[EI_ABIVERSION]);
display_value("Type", type_str, header->e_type);
printf("  Entry point address:               %lx\n", header->e_entry);
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
char *magic = "\177ELF";

const char *usage = "Usage: %s elf_filename\n";
const char *file_error = "Error: could not open file '%s'\n";
const char *not_elf_error = "Error: not an ELF file\n";

if (argc != 2)
{
fprintf(stderr, usage, argv[0]);
exit(98);
}


fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
fprintf(stderr, file_error, argv[1]);
exit(98);
}

ret = read(fd, &header, sizeof(header));
if (ret != sizeof(header) || memcmp(header.e_ident, magic, strlen(magic)) != 0)
{
fprintf(stderr, not_elf_error);
exit(98);
}
lseek(fd, 0, SEEK_SET);
close(fd);
return (0);
}

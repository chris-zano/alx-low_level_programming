#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * display_magic - displays the magic number bytes of the ELF header
 * @magic: pointer to memory where magic number is stored
 * Return: void
 */
void display_magic(unsigned char *magic)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", magic[i]);
	}
	printf("\n");
}

/**
 * display_class - displays the class of the ELF file
 * @class: indicates whether it is a 32-bit or 64-bit executable
 * Return: void
 */
void display_class(unsigned char class)
{
	char *class_str[] = {"None", "ELF32", "ELF64"};
	printf("  Class:                             %s\n", class_str[class]);
}

/**
 * display_data - displays the data encoding of the ELF file
 * @data:  indicates whether it uses little-endian or big-endian byte
 * Return: void
 */
void display_data(unsigned char data)
{
	char *data_str[] = {"None", "2's complement, little endian", "2's complement, big endian"};
	printf("  Data:                              %s\n", data_str[data]);
}

/**
 * display_version - displays the version number of the ELF file format
 * @version: an array that stores the EI_VERSION field of the ELF header
 * Return: void
 */
void display_version(unsigned char version)
{
	char *version_str[] = {"Invalid", "Current", "Invalid", "Invalid", "Invalid", "Invalid", "Invalid", "Invalid", "Invalid", "Invalid", "Invalid", "Invalid", "Invalid", "Invalid", "Invalid", "Invalid"};
	printf("  Version:                           %s\n", version_str[version]);
}

/**
 * display_osabi - displays the operating system/ABI of the ELF file
 * @osabi: indicates the target operating system
 * Return: void
 */
void display_osabi(unsigned char osabi) 
{
	char *osabi_str[] = {"UNIX - System V", "HP-UX", "NetBSD", "Linux", "GNU Hurd", "Solaris", "AIX", "IRIX", "FreeBSD", "Tru64", "Novell Modesto", "OpenBSD", "OpenVMS", "NonStop Kernel", "AROS", "Fenix OS", "CloudABI"};
	printf("  OS/ABI:                            %s\n", osabi_str[osabi]);
}

/**
 * display_abiversion -  displays the "ABI version" of the ELF file
 * @abiversion: indicates the version of the ABI
 * Return: void
 */
void display_abiversion(unsigned char abiversion)
{
	printf("  ABI Version:                       %d\n", abiversion);
}


/**
 * display_type - displays the "type" of the ELF file, 
 * @type: which indicates whether it is an executable or object file
 * Return: void
 */
void display_type(Elf64_Half type)
{
	char *type_str[] = {"None", "Relocatable", "Executable", "Shared object", "Core", "Processor-specific"};
	printf("  Type:                              %s\n", type_str[type]);
}

/**
 * display_enrty - entry point address of the ELF file
 * @entry: memory address where the program should begin execution
 */
void display_entry(Elf64_Addr entry)
{
	printf("  Entry point address:               %lx\n", entry);
}


/**
 * display_header - displays the header, by calling all other functions
 * @header: pointer to a header
 * Return: void
 */
void display_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	display_magic(header->e_ident);
	display_class(header->e_ident[EI_CLASS]);
	display_data(header->e_ident[EI_DATA]);
	display_version(header->e_ident[EI_VERSION]);
	display_osabi(header->e_ident[EI_OSABI]);
	display_abiversion(header->e_ident[EI_ABIVERSION]);
	display_type(header->e_type);
	display_entry(header->e_entry);
}


/**
 * main - displays the information contained in the ELF header at the start
 * @argc: argument count
 * @argv: argument vector
 * Return: (0)
 */

int main(int argc, char **argv)
{
	int fd, ret;
	Elf64_Ehdr header;
	char *magic = "\177ELF";

	/* Check command-line arguments */
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	/* Open the file */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: could not open file '%s'\n", argv[1]);
		exit(98);
	}

	/* Read the ELF header */
	ret = read(fd, &header, sizeof(header));
	if (ret != sizeof(header) || memcmp(header.e_ident, magic, strlen(magic)) != 0)
	{
		fprintf(stderr, "Error: not an ELF file\n");
		exit(98);
	}
	lseek(fd, 0, SEEK_SET);

	/* Close file */
	close(fd);

	return (0);
}


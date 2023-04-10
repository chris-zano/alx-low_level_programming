#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void _check_ELF(unsigned char *magic_num);
void display_magic(unsigned char *magic_num);
void display_class(unsigned char *magic_num);
void display_data(unsigned char *magic_num);
void display_version(unsigned char *magic_num);
void display_abi(unsigned char *magic_num);
void display_osabi(unsigned char *magic_num);
void display_type(unsigned int type_ELF, unsigned char *magic_num);
void display_header(unsigned long int entry_ELF, unsigned char *magic_num);
void close_elf(int elf);


/**
 * _check_ELF - Checks if a file is an ELF file.
 * @magic_num: A pointer to an array containing the ELF magic numbers.
 *
 */
void _check_ELF(unsigned char *magic_num)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (magic_num[index] != 127 &&
		    magic_num[index] != 'E' &&
		    magic_num[index] != 'L' &&
		    magic_num[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * display_magic - Prints the magic numbers of an ELF header.
 * @magic_num: A pointer to an array containing the ELF magic numbers.
 *
 */
void display_magic(unsigned char *magic_num)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", magic_num[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * display_class - Prints the class of an ELF header.
 * @magic_num: A pointer to an array containing the ELF class.
 */
void display_class(unsigned char *magic_num)
{
    printf("  Class:                             ");

    if (magic_num[EI_CLASS] == ELFCLASSNONE) {
        printf("none\n");
    } else if (magic_num[EI_CLASS] == ELFCLASS32) {
        printf("ELF32\n");
    } else if (magic_num[EI_CLASS] == ELFCLASS64) {
        printf("ELF64\n");
    } else {
        printf("<unknown: %x>\n", magic_num[EI_CLASS]);
    }
}


/**
 * display_data - Prints the data of an ELF header.
 * @magic_num: A pointer to an array containing the ELF class.
 */
void display_data(unsigned char *magic_num)
{
	printf("  Data:                              ");

	if (magic_num[EI_DATA] == ELFDATANONE) {
		printf("none\n");
	} else if (magic_num[EI_DATA] == ELFDATA2LSB) {
		printf("2's complement, little endian\n");
	} else if (magic_num[EI_DATA] == ELFDATA2MSB) {
		printf("2's complement, big endian\n");
	} else {
		printf("<unknown: %x>\n", magic_num[EI_DATA]);
	}
}


/**
 * display_version - Prints the version of an ELF header.
 * @magic_num: A pointer to an array containing the ELF version.
 */
void display_version(unsigned char *magic_num)
{
	printf("  Version:                           %d", magic_num[EI_VERSION]);

	if (magic_num[EI_VERSION] == EV_CURRENT) {
		printf(" (current)");
	}

	printf("\n");
}


/**
 * display_osabi - Prints the OS/ABI of an ELF header.
 * @magic_num: A pointer to an array containing the ELF version.
 */
void display_osabi(unsigned char *magic_num)
{
	const char *osabi_strings[] = {
		[ELFOSABI_NONE] = "UNIX - System V",
		[ELFOSABI_HPUX] = "UNIX - HP-UX",
		[ELFOSABI_NETBSD] = "UNIX - NetBSD",
		[ELFOSABI_LINUX] = "UNIX - Linux",
		[ELFOSABI_SOLARIS] = "UNIX - Solaris",
		[ELFOSABI_IRIX] = "UNIX - IRIX",
		[ELFOSABI_FREEBSD] = "UNIX - FreeBSD",
		[ELFOSABI_TRU64] = "UNIX - TRU64",
		[ELFOSABI_ARM] = "ARM",
		[ELFOSABI_STANDALONE] = "Standalone App",
	};

	const char *osabi_string = "<unknown>";
	if (magic_num[EI_OSABI] < sizeof(osabi_strings)/sizeof(osabi_strings[0])) {
		osabi_string = osabi_strings[magic_num[EI_OSABI]];
	}

	printf("  OS/ABI:                            %s\n", osabi_string);
}


/**
 * display_abi - Prints the ABI version of an ELF header.
 * @magic_num: A pointer to an array containing the ELF ABI version.
 */
void display_abi(unsigned char *magic_num)
{
	printf("  ABI Version:                       %d\n",
	       magic_num[EI_ABIVERSION]);
}

/**
 * display_type - Prints the type of an ELF header.
 * @type_ELF: The ELF type.
 * @magic_num: A pointer to an array containing the ELF class.
 */
void display_type(unsigned int type_ELF, unsigned char *magic_num)
{
    if (magic_num[EI_DATA] == ELFDATA2MSB)
        type_ELF >>= 8;

    printf("  Type:                              ");

    if (type_ELF == ET_NONE) {
        printf("NONE (None)\n");
    } else if (type_ELF == ET_REL) {
        printf("REL (Relocatable file)\n");
    } else if (type_ELF == ET_EXEC) {
        printf("EXEC (Executable file)\n");
    } else if (type_ELF == ET_DYN) {
        printf("DYN (Shared object file)\n");
    } else if (type_ELF == ET_CORE) {
        printf("CORE (Core file)\n");
    } else {
        printf("<unknown: %x>\n", type_ELF);
    }
}


/**
 * display_header - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @magic_num: A pointer to an array containing the ELF class.
 */
void display_header(unsigned long int e_entry, unsigned char *magic_num)
{
	printf("  Entry point address:               ");

	if (magic_num[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (magic_num[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success if the function fails - exit code 98
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	_check_ELF(header->magic_num);
	printf("ELF Header:\n");
	display_magic(header->magic_num);
	display_class(header->magic_num);
	display_data(header->magic_num);
	display_version(header->magic_num);
	display_osabi(header->magic_num);
	display_abi(header->magic_num);
	display_type(header->type_ELF, header->magic_num);
	display_header(header->e_entry, header->magic_num);

	free(header);
	close_elf(o);
	return (0);
}

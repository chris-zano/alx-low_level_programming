#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void is_ELF(unsigned char *magic_num);
void display_magic(unsigned char *magic_num);
void display_class(unsigned char *magic_num);
void display_data(unsigned char *magic_num);
void display_version(unsigned char *magic_num);
void display_abi(unsigned char *magic_num);
void display_osabi(unsigned char *magic_num);
void display_type(unsigned int elf_type, unsigned char *magic_num);
void dislay_entry(unsigned long int addr_ELF, unsigned char *magic_num);
void _close_ELF(int elf);

/**
 * is_ELF - Checks if a file is an ELF file.
 * @magic_num: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void is_ELF(unsigned char *magic_num)
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
 * Description: Magic numbers are separated by spaces.
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

	switch (magic_num[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
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

	switch (magic_num[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", magic_num[EI_CLASS]);
	}
}

/**
 * display_version - Prints the version of an ELF header.
 * @magic_num: A pointer to an array containing the ELF version.
 */
void display_version(unsigned char *magic_num)
{
	printf("  Version:                           %d",
	       magic_num[EI_VERSION]);

	switch (magic_num[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * display_osabi - Prints the OS/ABI of an ELF header.
 * @magic_num: A pointer to an array containing the ELF version.
 */
void display_osabi(unsigned char *magic_num)
{
	printf("  OS/ABI:                            ");

	switch (magic_num[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", magic_num[EI_OSABI]);
	}
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
 * @elf_type: The ELF type.
 * @magic_num: A pointer to an array containing the ELF class.
 */
void display_type(unsigned int elf_type, unsigned char *magic_num)
{
	if (magic_num[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf("  Type:                              ");

	switch (elf_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_type);
	}
}

/**
 * dislay_entry - Prints the entry point of an ELF header.
 * @addr_ELF: The address of the ELF entry point.
 * @magic_num: A pointer to an array containing the ELF class.
 */
void dislay_entry(unsigned long int addr_ELF, unsigned char *magic_num)
{
	printf("  Entry point address:               ");

	if (magic_num[EI_DATA] == ELFDATA2MSB)
	{
		addr_ELF = ((addr_ELF << 8) & 0xFF00FF00) |
			  ((addr_ELF >> 8) & 0xFF00FF);
		addr_ELF = (addr_ELF << 16) | (addr_ELF >> 16);
	}

	if (magic_num[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)addr_ELF);

	else
		printf("%#lx\n", addr_ELF);
}

/**
 * _close_ELF - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void _close_ELF(int elf)
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
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
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
		_close_ELF(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		_close_ELF(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	is_ELF(header->magic_num);
	printf("ELF Header:\n");
	display_magic(header->magic_num);
	display_class(header->magic_num);
	display_data(header->magic_num);
	display_version(header->magic_num);
	display_osabi(header->magic_num);
	display_abi(header->magic_num);
	display_type(header->elf_type, header->magic_num);
	dislay_entry(header->addr_ELF, header->magic_num);

	free(header);
	_close_ELF(o);
	return (0);
}

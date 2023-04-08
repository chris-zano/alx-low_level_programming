#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "rb");

    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // Read the ELF header
    Elf64_Ehdr header;
    fread(&header, sizeof(header), 1, fp);

    // Find the section header table
    fseek(fp, header.e_shoff, SEEK_SET);

    // Read the section header table
    Elf64_Shdr *section_headers = (Elf64_Shdr*)malloc(sizeof(Elf64_Shdr) * header.e_shnum);
    fread(section_headers, sizeof(Elf64_Shdr), header.e_shnum, fp);

    // Find the .rodata section
    Elf64_Shdr *rodata_section = NULL;
    char *section_names = NULL;

    if (header.e_shstrndx != SHN_UNDEF) {
        Elf64_Shdr *shstrtab = &section_headers[header.e_shstrndx];
        section_names = (char*)malloc(shstrtab->sh_size);
        fseek(fp, shstrtab->sh_offset, SEEK_SET);
        fread(section_names, shstrtab->sh_size, 1, fp);
    }

    for (int i = 0; i < header.e_shnum; i++) {
        Elf64_Shdr *section = &section_headers[i];

        if (section->sh_type == SHT_PROGBITS && (section->sh_flags & SHF_WRITE) == 0 &&
            strcmp(&section_names[section->sh_name], ".rodata") == 0) {
            rodata_section = section;
            break;
        }
    }

    if (!rodata_section) {
        printf("Error: could not find .rodata section\n");
        return 1;
    }

    // Read the string data from the .rodata section
    char *string_data = (char*)malloc(rodata_section->sh_size);
    fseek(fp, rodata_section->sh_offset, SEEK_SET);
    fread(string_data, rodata_section->sh_size, 1, fp);

    // Print out the strings in the .rodata section
    printf("Strings in .rodata section:\n");
    int offset = 0;

    while (offset < rodata_section->sh_size) {
        printf("%s\n", &string_data[offset]);
        offset += strlen(&string_data[offset]) + 1;
    }

    // Clean up
    free(string_data);
    free(section_headers);
    free(section_names);
    fclose(fp);

    return 0;
}


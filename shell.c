#include "filesys.c"
#include <stdio.h>
#include <string.h>

void FAT_Implementation() {
    printf("FAT block entry 0 starts here.\n");
    format();

    const char *filename = "Virtual_Disk";
    writeDisk(filename);
    printFAT();

    printf("Block 0 ends here.\n\n");
}

int main(int argc, char const *argv[]) {
    FAT_Implementation();
    return 0;
}

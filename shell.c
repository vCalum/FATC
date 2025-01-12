#include "filesys.h"
#include <stdio.h>
#include <string.h>

void FAT() {
    printf("FAT block entry 0 starts here.\n");
    format();

    const char *filename = "Virtual Disk";
    writedisk(filename);
    printFAT();

    printf("Block 0 ends here.\n");
}

int main(int argc, char const *argv[]) {

    /* insert function here */
    FAT();

    return 0;
}

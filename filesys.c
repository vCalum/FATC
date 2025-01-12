#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "filesys.h"

diskblock_t virtualDisk[MAXBLOCKS];
fatentry_t FAT[MAXBLOCKS];
fatentry_t rootDirIndex = FATBLOCKSNEEDED + 1;
dirblock_t * rootDirBlock_ptr = NULL;
fatentry_t currentDirIndex = 0;
dirblock_t * currentDirBlock_ptr = NULL;
const char parse[2] = "/";

void writeDisk(const char * filename) {
    FILE * dest = fopen(filename, "w");
    if (fwrite(virtualDisk, sizeof(virtualDisk), 1, dest) < 0) {
        fprintf(stderr, "Error while writing virtual disk.\n");
    }
    fclose(dest);
}

void readDisk(const char * filename) {
    FILE * dest = fopen(filename, "r");
    if (fread(virtualDisk, sizeof(virtualDisk), 1, dest) < 0) {
        fprintf(stderr, "Error while reading virtual disk.\n");
    }
    fclose(dest);
}

void writeBlock() {

}

void format() {

}

void copyFAT() {

}
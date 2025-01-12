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

// Initialise hex file on virtual disk
void writeDisk(const char * filename) {
    FILE * dest = fopen(filename, "w");
    if (fwrite(virtualDisk, sizeof(virtualDisk), 1, dest) != 1) {
        fprintf(stderr, "Error while writing virtual disk.\n");
    }
    fclose(dest);
}

// Read created hex file
void readDisk(const char * filename) {
    FILE * dest = fopen(filename, "r");
    if (fread(virtualDisk, sizeof(virtualDisk), 1, dest) != 1) {
        fprintf(stderr, "Error while reading virtual disk.\n");
    }
    fclose(dest);
}

// Write Block to Virtual Disk
void writeBlock(const diskblock_t * block, const int block_address) {
    memmove(virtualDisk[block_address].data, block->data, BLOCKSIZE);
}

void format() {

}

void copyFAT() {

}
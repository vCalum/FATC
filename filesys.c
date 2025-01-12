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
    // Prepare block at address by overwriting with data from following block (+1)
    //memmove(&virtualDisk[block_address], &virtualDisk[block_address + 1],sizeof(diskblock_t));

    // Copies data from input block data of virtual disk at block address
    memmove(virtualDisk[block_address].data, block->data, BLOCKSIZE);   // memcpy can be used in future implementation, for now memmove is more robust
}

// Creates structure for FAT, virtual disk and root directory
void format() {
    diskblock_t block;

    // Set the root and directory
    rootDirBlock_ptr = (dirblock_t *) &virtualDisk[rootDirIndex].dir;
    currentDirIndex = rootDirIndex;
    currentDirBlock_ptr = rootDirBlock_ptr;

    // Initialise block 0
    for (int i = 0; i < BLOCKSIZE; i++) {
        block.data[i] = "/0";
    }
    strcpy(block.data, "Portfolio File Allocation Table");
    writeBlock(&block, 0);

    // Initialise FAT
    FAT[0] = ENDOFCHAIN;

    int i = 1;
    while (i < FATBLOCKSNEEDED) {
        FAT[i] = i + 1;
        i++;
    }
    FAT[i] = ENDOFCHAIN;
    i++;

    while (i < MAXBLOCKS) {
        FAT[i] = UNUSED;
        i++;
    }

    copyFAT();

    // Initialise root directory
    rootDirBlock_ptr->parent = NULL;        // There is no parent of root
    rootDirBlock_ptr->entry_ptr = NULL;     // There is no entry for root
    rootDirBlock_ptr->entry_ptr = NULL;

    // All directories set to available
    for (int i1 = 0; i1 < DIRENTRYCOUNT; i1++) {
        rootDirBlock_ptr->entrylist[i1].unused = TRUE;
    }

    // Print block 0
    printBlock(0);
}

// Write FAT onto disk
void copyFAT() {
    for (int i = 0; i < FATBLOCKSNEEDED; i++) {
        for (int j = 0; j < FATENTRYCOUNT; j++) {
            virtualDisk[i + 1].fat[j] = FAT[j + i*FATENTRYCOUNT];
        }
    }
}
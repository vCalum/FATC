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

void writeDisk() {

}

void readDisk() {

}

void writeBlock() {

}

void format() {

}

void copyFAT() {

}
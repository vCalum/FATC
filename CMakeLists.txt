TARGET = prog
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)format-hex Virtual_Disk | more
$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

# Add a hexdump target
hexdump: $(TARGET)
# Run your program first (optional)
./$(TARGET)
# Generate a hexdump of Virtual_Disk
format-hex Virtual_Disk > virtual_disk.txt

clean:
-rm -f *.o $(TARGET) virtual_disk.txt

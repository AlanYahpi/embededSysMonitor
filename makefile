CC = gcc
CFLAGS = -Wall -Wextra -std=c11
INCLUDES = -Iheaders

SRC_MAIN = src/main.c
SRC_CONFIG = src/config.c

OBJ_MAIN = main.o
OBJ_CONFIG = config.o

# Check if headers/config.h exists
ifeq ($(wildcard headers/config.h),)

else
    CFLAGS += -DHAS_CONFIG_HEADER
endif

all: main

main: $(SRC_MAIN)
	$(CC) $(CFLAGS) $(INCLUDES) -o main $(SRC_MAIN)

config: $(SRC_CONFIG)
	$(CC) $(CFLAGS) $(INCLUDES) -o config $(SRC_CONFIG)

clean:
	rm -f main config *.o


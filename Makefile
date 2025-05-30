CC = gcc
CFLAGS = -O0 -Wall -Wextra -pedantic -std=c99 -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
LDFLAGS =
SRC = main.c editor.c
OBJ = $(SRC:.c=.o)
EXEC = pencil

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean

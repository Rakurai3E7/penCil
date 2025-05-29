CC = gcc
CFLAGS = -Wall -Wextra -Pedantic -std=c99 -g
LDFLAGS =
SRC = main.c
OBJ = $(SRC:.c=.o)
EXEC = pencil

all: $(EXEC)

$(EXEC): $(OBJ)
    $(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    ram -f $(OBJ) $(EXEC)

.PHONY: all clean

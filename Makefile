GAME_TEXT = game_text
CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wextra
SRC_GAME_TEXT = game_text.c
OBJ_GAME_TEXT = $(SRC_GAME_TEXT:.c=.o)
LDLIBS = -L. -lgame

.PHONY: all clean fclean re

all: $(GAME_TEXT)

$(GAME_TEXT): $(OBJ_GAME_TEXT)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c game.h game_aux.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: fclean
	rm -f $(OBJ_GAME_TEXT)

fclean:
	rm -f $(GAME_TEXT)

re: clean all
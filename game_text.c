#include "game.h"
#include "game_aux.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    game    g;

    g = game_default();
    game_set_square(g, 1, 0, 1);
    game_print(g);
    game_delete(g);
    return EXIT_SUCCESS; 
}
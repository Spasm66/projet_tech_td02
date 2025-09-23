#include "game.h"
#include "game_aux.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    game    g;

    g = game_default();
    game_set_square(g, 1, 0, 1);
    game_print(g);
    char user_sres = '\0';
    while(!game_won(g))
    {
        scanf(" %c", &user_sres);
        printf("input: %c\n", user_sres);
        switch(user_sres)
        {
            case 't':
                int posx = 0;
                int posy = 0;
                scanf(" %d", &posx);
                scanf(" %d", &posy);
                printf("posx: %d, posy: %d\n", posx, posy);
                game_play_move(g, posx, posy, TENT);
                break;

            case 'g':
                int posx = 0;
                int posy = 0;
                scanf(" %d", &posx);
                scanf(" %d", &posy);
                printf("posx: %d, posy: %d\n", posx, posy);
                game_play_move(g, posx, posy, GRASS);
                break;

            case 'e':
                int posx = 0;
                int posy = 0;
                scanf(" %d", &posx);
                scanf(" %d", &posy);
                printf("posx: %d, posy: %d\n", posx, posy);
                game_play_move(g, posx, posy, EMPTY);
                break;

            case 'h':
                printf("help\n");
                break;

            case 'r':
                // reset
                break;

            case 'f':
                // remplir d'herbe
                break;

            case 'q':
                game_delete(g);
                break;  
                
            default:
                break;
        }
    }
    return EXIT_SUCCESS; 
}
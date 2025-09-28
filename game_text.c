#include "game.h"
#include "game_aux.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    game    g;

    g = game_default();
    game_print(g);
    char user_sres = '\0';
    int posx = 0;
    int posy = 0;
    while(!game_won(g))
    {
        printf("> ? [h for help]\n");
        scanf(" %c", &user_sres);
        printf("input: %c\n", user_sres);
        if (user_sres == 'q')
            break;
        switch(user_sres)
        {
            case 't':
                scanf(" %d", &posx);
                scanf(" %d", &posy);
                printf("posx: %d, posy: %d\n", posx, posy);
                game_play_move(g, posx, posy, TENT);
                break;

            case 'g':
                scanf(" %d", &posx);
                scanf(" %d", &posy);
                printf("posx: %d, posy: %d\n", posx, posy);
                game_play_move(g, posx, posy, GRASS);
                break;

            case 'e':
                scanf(" %d", &posx);
                scanf(" %d", &posy);
                printf("posx: %d, posy: %d\n", posx, posy);
                game_play_move(g, posx, posy, EMPTY);
                break;

            case 'h':
                printf("-press 't <i> <j>' to put a tent square (i,j)\n");
                printf("-press 'g <i> <j>' to put a grass square (i,j)\n");
                printf("-press 'e <i> <j>' to put an empty square (i,j)\n");
                printf("-press 'f' to fill grass\n");
                printf("-press 'r' to restart\n");
                printf("-press 'q' to quit\n");
                break;

            case 'r':
                game_restart(g);
                break;

            case 'f':
                game_fill_grass(g);
                break;
                
            default:
                break;
        }
        game_print(g);
    }
    
    if (game_won(g))
        printf("congratulation\n");
    else
        printf("shame\n");
    game_delete(g);
    return EXIT_SUCCESS; 
}
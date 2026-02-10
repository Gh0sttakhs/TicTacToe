#include "tictactoe.h"

void bot(char table[3][3],char piece){
    int position_i = rand() % 3;
    int position_j = rand() % 3;
    while (legal_position(table,position_i,position_j) == 0) {
        position_i = rand() % 3;
        position_j = rand() % 3;
    }
    move(table,position_i,position_j,piece);
    printf("Bot played its move!\n");
}
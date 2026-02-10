#include "tictactoe.h"

void bot(char table[3][3],char piece){
    int i,j;
    //WIN
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (table[i][j] == '-') {
                table[i][j] = piece; 
                if (check_win(table, piece)) {
                    printf("Bot found a winning move at %c %d!\n", 'A'+j, i+1);
                    return; 
                }
                table[i][j] = '-'; 
            }
        }
    }

    char opponent = (piece == 'X') ? 'O' : 'X';
    //DEFENCE
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (table[i][j] == '-') {
                table[i][j] = opponent; 
                if (check_win(table, opponent)) {
                    table[i][j] = piece;
                    printf("Bot blocked you at %c %d!\n", 'A'+j, i+1);
                    return;
                }
                table[i][j] = '-'; 
            }
        }
    }

    //CENTRE STRATEGY
    if (table[1][1] == '-') {
        table[1][1] = piece;
        printf("Bot played its move!\n");
        return;
    }

    int position_i = rand() % 3;
    int position_j = rand() % 3;
    while (legal_position(table,position_i,position_j) == 0) {
        position_i = rand() % 3;
        position_j = rand() % 3;
    }
    move(table,position_i,position_j,piece);
    printf("Bot played its move!\n");
}
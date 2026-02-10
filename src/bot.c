#include "tictactoe.h"

int minimax(char table[3][3], int depth, int isMaximizing, char botPiece, char playerPiece) {
    if (check_win(table, botPiece)) return 10;
    if (check_win(table, playerPiece)) return -10;
    if (is_full(table)) return 0; 

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (table[i][j] == '-') {
                    table[i][j] = botPiece; 
                    int score = minimax(table, depth + 1, 0, botPiece, playerPiece); // Κάλεσε αναδρομικά
                    table[i][j] = '-';
                    if (score > bestScore) bestScore = score;
                }
            }
        }
        return bestScore;
    } 
    else {
        int bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (table[i][j] == '-') {
                    table[i][j] = playerPiece;
                    int score = minimax(table, depth + 1, 1, botPiece, playerPiece);
                    table[i][j] = '-';
                    if (score < bestScore) bestScore = score;
                }
            }
        }
        return bestScore;
    }
}

void pro_bot(char table[3][3], char piece) {
    printf("Pro Bot is calculating...\n");
    char opponent = (piece == 'X') ? 'O' : 'X';
    
    int bestScore = -1000;
    int bestMove_i = -1;
    int bestMove_j = -1;

    if (table[1][1] == '-') {
        move(table, 1, 1, piece);
        printf("Pro Bot played at Center!\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (table[i][j] == '-') {
                table[i][j] = piece; 
                int score = minimax(table, 0, 0, piece, opponent); 
                table[i][j] = '-'; 

                if (score > bestScore) {
                    bestScore = score;
                    bestMove_i = i;
                    bestMove_j = j;
                }
            }
        }
    }

    move(table, bestMove_i, bestMove_j, piece);
    printf("Pro Bot played at %c %d!\n", 'A' + bestMove_j, bestMove_i + 1);
}

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

    int corners[4][2] = {{0,0}, {0,2}, {2,0}, {2,2}};
    for (int k = 0; k < 4; k++) {
        int r = corners[k][0];
        int c = corners[k][1];
        if (table[r][c] == '-') {
            table[r][c] = piece;
            printf("Bot played its move!\n");
            return;
        }
    }

    int position_i = rand() % 3;
    int position_j = rand() % 3;
    while (legal_position(table, position_i, position_j) == 0) {
        position_i = rand() % 3;
        position_j = rand() % 3;
    }
    move(table, position_i, position_j, piece);
    printf("Bot played its move!\n");
}
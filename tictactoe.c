#include "tictactoe.h"

void clear_board(char table[3][3]) {
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ;j++) {
            table[i][j] = '-';
        }
    }
}

void print_board(char table[3][3]) {    
    printf(YELLOW "\n   A   B   C\n" RESET);
    for (int i = 0 ; i < 3 ; i++) {
        printf(YELLOW "%d " RESET, i+1);
        for (int j = 0 ; j < 3 ;j++) {
            if (table[i][j] == 'X') {
                printf(RED " %c  " RESET, table[i][j]);
            } else if (table[i][j] == 'O') {
                printf(CYAN " %c  " RESET, table[i][j]);
            } else {
                printf(" %c  ", table[i][j]);
            }
        }
        printf(YELLOW "%d " RESET, i+1);
        printf("\n");
    }
    printf(YELLOW "   A   B   C\n" RESET);
}

int legal_position(char table[3][3], int position_i, int position_j) {
    if (position_i > 2 || position_i < 0 || position_j > 2 || position_j < 0) {
        return 0;
    }
    if (table[position_i][position_j] != '-'){
        return 0;
    }
    return 1;
}

void move(char table[3][3], int position_i, int position_j, char piece) {
    table[position_i][position_j] = piece;
}

int check_win(char table[3][3], char p) {
    for (int i=0; i<3; i++) {
        if (table[i][0]==p && table[i][1]==p && table[i][2]==p) return 1;
        if (table[0][i]==p && table[1][i]==p && table[2][i]==p) return 1;
    }
    if (table[0][0]==p && table[1][1]==p && table[2][2]==p) return 1;
    if (table[0][2]==p && table[1][1]==p && table[2][0]==p) return 1;
    
    return 0;
}

int is_full(char table[3][3]) {
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(table[i][j] == '-') return 0;
    return 1; // Γέμισε
}

int main() {
    srand(time(NULL));
    char table[3][3];
    while(1) {
        clear_board(table);
        printf(CYAN "\n=== NEW GAME ===" RESET "\nSelect mode:\n1) VS bot\n2) VS your friend\n");
        int mode;
        while(scanf("%d", &mode) != 1 || (mode != 1 && mode != 2)) {
            printf(RED "Invalid input. Enter 1 or 2: " RESET);
            while(getchar() != '\n');
        }
        while(getchar() != '\n');

        char my_piece, bot_piece, friend_piece;
        printf("Select your piece (O or X): ");
        scanf(" %c", &my_piece);
        if (my_piece == 'o') my_piece = 'O';
        if (my_piece == 'x') my_piece = 'X';
        while(my_piece != 'O' && my_piece != 'X'){
            printf(RED "Please select O or X. Try again:\n" RESET);
            scanf(" %c",&my_piece);
        }

        if (my_piece == 'O') { bot_piece = 'X'; friend_piece = 'X'; }
        else                 { bot_piece = 'O'; friend_piece = 'O'; }

        char current_player = 'X';
        int game_running = 1;
        while (game_running) {
            print_board(table);
            if (mode == 1) {
                if (current_player == my_piece) {
                    printf("Your turn (%c) - Enter move (e.g. A 1): ", current_player);
                    char c_char;
                    int r_num;
                    scanf(" %c %d", &c_char, &r_num);
                    
                    int j = toupper(c_char) - 'A';
                    int i = r_num - 1;

                    if (legal_position(table, i, j)) {
                        move(table, i, j, current_player);
                    } else {
                        printf(RED "Invalid move! Try again.\n" RESET);
                        continue;
                    }
                } else {
                    bot(table, bot_piece);
                }
            }
            
            else {
                printf("Player %c turn - Enter move (e.g. A 1): ", current_player);
                char c_char;
                int r_num;
                scanf(" %c %d", &c_char, &r_num);
                
                int j = toupper(c_char) - 'A';
                int i = r_num - 1;

                if (legal_position(table, i, j)) {
                    move(table, i, j, current_player);
                } else {
                    printf(RED "Invalid move! Try again.\n" RESET);
                    continue;
                }
            }
            if (check_win(table, current_player)) {
                print_board(table);
                if (mode == 1 && current_player == bot_piece)
                    printf(RED "Bot WINS! Better luck next time.\n" RESET);
                else
                    printf(YELLOW "PLAYER %c WINS!\n" RESET, current_player);
                game_running = 0;
            } else if (is_full(table)) {
                print_board(table);
                printf("It's a DRAW!\n");
                game_running = 0;
            } else {
                current_player = (current_player == 'X') ? 'O' : 'X';
            }
        }
        printf("Play again? (1: Yes, 0: No): ");
        int choice;
        while(scanf("%d", &choice) != 1) {
            printf(RED "Invalid input. Please enter 1 or 0: " RESET);
            while(getchar() != '\n');
        }
        while(getchar() != '\n');
        if (choice == 0) break;
    }
    printf(CYAN"Goodbye! Thanks for playing :)\n"RESET);
    return 0;
}
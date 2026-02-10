#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

int legal_position(char table[3][3], int position_i, int position_j);
void bot(char table[3][3],char piece);
void move(char table[3][3], int position_i, int position_j, char piece);
int check_win(char table[3][3], char p);
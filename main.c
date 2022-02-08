#include <stdio.h>
#include <stdlib.h>


int make_move() {
    // print board
    // await input
    // return board
    return 0;
}

void print_board(int board) {
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%d ", *board[i][j]);
        }
        printf("\n");
    }
    //prints board
}

void run_game() {

    int board[3][3];
    int (*boardp)[][];
    for (int i=0; i<3; i++) {
        for (int j; j<3; j++) {
            board[i][j] = '_';
        }
    }
    
    print_board(boardp);

    int turnindex = 0;
    while (check_for_win(board) == "_") {
        check_for_input(board, turnindex);
        turnindex += 1;
    }

    // game ended
    char playerchar;
    if (turnindex % 2 == 0)  {
        playerchar = 'X';
    }
    else {
        playerchar = 'O';
    }
    printf("CONGRATULATIONS! Player ");
    printf(playerchar);
    printf(" won.\n");
}

void check_for_input(int board, int turnindex) {
    char playerchar;
    if (turnindex % 2 == 0)  {
        playerchar = 'X';
    }
    else {
        playerchar = 'O';
    }
    printf("Please enter index to place your ");
    printf(playerchar);
    printf("\n");
    int i = (int) getchar();
    int rowindex = i % 3;
    int columnindex = (i-(i%3)) / 3;
    if (board[rowindex][columnindex] == '_') {
        board[rowindex][columnindex] = playerchar;
    } 
    else {
        printf('Not possible!\n');
        check_for_input(board, turnindex);
    }
}

int main() {   

    printf("Starting Game...\n"); 
    run_game();

    return 0;
}

char check_for_win(int board) { //returns character of player who won or _
    if (board[0][0] = board[0][1]) and (board[0][0] = board[0][2]) {
        return board[0][0];
    }
    if (board[1][0] = board[1][1]) and (board[1][0] = board[1][2]) {
        return board[1][0];
    }
    if (board[2][0] = board[2][1]) and (board[2][0] = board[2][2]) {
        return board[2][0];
    }
    if (board[0][0] = board[1][1]) and (board[0][0] = board[2][2]) {
        return board[0][0];
    }
    if (board[2][0] = board[1][1]) and (board[2][0] = board[0][2]) {
        return board[2][0];
    }
    if (board[0][0] = board[1][0]) and (board[0][0] = board[2][0]) {
        return board[0][0];
    }
    if (board[0][1] = board[1][1]) and (board[0][1] = board[2][1]) {
        return board[0][1];
    }
    if (board[0][2] = board[1][2]) and (board[0][2] = board[2][2]) {
        return board[0][2];
    }
    return '_';
}
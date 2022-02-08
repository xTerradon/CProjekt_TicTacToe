#include <stdio.h>
#include <stdlib.h>


void print_board(char board[3][3]) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    //prints board
}

char check_for_win(char board[3][3]) { //returns character of player who won or _
    if (board[0][0] == board[0][1] && board[0][0] == board[0][2]) {
        return board[0][0];
    }
    if (board[1][0] == board[1][1] && board[1][0] == board[1][2]) {
        return board[1][0];
    }
    if (board[2][0] == board[2][1] && board[2][0] == board[2][2]) {
        return board[2][0];
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
        return board[2][0];
    }
    if (board[0][0] == board[1][0] && board[0][0] == board[2][0]) {
        return board[0][0];
    }
    if (board[0][1] == board[1][1] && board[0][1] == board[2][1]) {
        return board[0][1];
    }
    if (board[0][2] == board[1][2] && board[0][2] == board[2][2]) {
        return board[0][2];
    }
    return '_';
}

void check_for_input(char board[3][3], int turnindex) {
    char playerchar;
    if (turnindex % 2 == 0)  {
        playerchar = 'X';
    }
    else {
        playerchar = 'O';
    }
    printf("Please enter index to place your ");
    printf("%c ", playerchar);
    printf("\n");
    int i = (int) getchar();
    int rowindex = i % 3;
    int columnindex = (i-(i%3)) / 3;
    if (board[rowindex][columnindex] == '_') {
        board[rowindex][columnindex] = playerchar;
    } 
    else {
        printf("Not possible!\n");
        check_for_input(board, turnindex);
    }
}

void run_game() {
    char board[3][3]= {{'_','_','_'},{'_','_','_'},{'_','_','_'}};
    print_board(board);

    int turnindex = 0;

    while (check_for_win(board) == '_') {
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
    printf("%c ", playerchar);
    printf(" won.\n");
}







int main() {   

    printf("Starting Game...\n"); 
    run_game();

    return 0;
}
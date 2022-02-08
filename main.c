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

int check_for_input(char board[3][3], int turnindex) {
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
    int i;
    scanf("%d", &i);
    i = i - 1;
    int columnindex = i % 3;
    int rowindex = (i-(i%3)) / 3;
    if (board[rowindex][columnindex] == '_') {
        return i;
    } 
    else {
        printf("Not possible!\n");
        check_for_input(board, turnindex);
    }
}

void run_game() {
    char board[3][3]= {{'_','_','_'},{'_','_','_'},{'_','_','_'}};
    
    int turnindex = 0;

    int playerchoice;
    while (check_for_win(board) == '_' && turnindex < 9) {
        printf("\n");
        print_board(board);
        playerchoice = check_for_input(board, turnindex);
        char playerchar;
        if (turnindex % 2 == 0)  {
            playerchar = 'X';
        }
        else {
            playerchar = 'O';
        }
        board[(playerchoice-(playerchoice%3)) / 3][playerchoice%3] = playerchar;
        turnindex += 1;
    }

    // game ended
    printf("\n");
    print_board(board);
    
    if (turnindex == 9) {
        printf("You both suck. That's a draw!");
    }
    else {
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

    
}



int main() {   

    printf("Starting Game...\n"); 
    run_game();

    return 0;
}
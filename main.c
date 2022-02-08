#include <stdio.h>
#include <stdlib.h>


int make_move() {
    // print board
    // await input
    // return board 
    return 0;
}


void run_game() {
    int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {   

    printf("Starting Game\n"); 
    run_game();

    return 0;
}
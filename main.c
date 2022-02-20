#include <stdio.h>

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
    char winner = NULL;

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            winner = board[i][0];
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            winner = board[0][i];
        }
    }
    
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        winner = board[0][0];
    }
    if (board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
        winner = board[2][0];
    }
    
    int open = 0;
    for (int i=0; i < 3; i++){
        for (int j=0; j < 3; j++) { 
            if (board[i][j] == '_') {
                open++;
            }
        }
    }
    
    if (winner == NULL && open == 0) {
        return 't';
    } else {
        return winner;
    }
    
}

int minmax (char board[3][3], int isMax) {
    char winner = check_for_win(board);
    
    if (winner == 'O') {
        int score = 1;
        return score;
        
    } else if (winner == 'X') {
        int score = -1;
        return score;
        
    } else if (winner == 't') {
        int score = 0;
        return score;
        
    }
    
    if (isMax == 1) {
        int bestScore = -100;
        for (int i=0; i < 3; i++){
            for (int j=0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = 'O';
                    int score = minmax(board, 0);
                    //printf ("(w: %c, s:%d [%d][%d]), ", winner, score, i, j);
                    board[i][j] = '_';
                    if (score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 100;
        for (int i=0; i < 3; i++) {
            for (int j=0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = 'X';
                    int score = minmax(board, 1);
                    //printf ("(w: %c, s:%d [%d][%d]), ", winner, score, i, j);
                    board[i][j] = '_';
                    if (score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

void bestMove(char board[3][3], int *move) {
    int bestScore = -100;

    for (int i=0; i < 3; i++){
        for (int j=0; j < 3; j++) {
            if (board[i][j] == '_') {
                board[i][j] = 'O';
                int score = minmax(board, 0);
                board[i][j] = '_';
                if (score > bestScore) {
                    bestScore = score;
                    move[0] = i;
                    move[1] = j;
                }
            }
        }
    }
}

int check_for_input(char board[3][3], int turnindex) {
    char playerchar = 'X';

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

    while (turnindex < 9) {
        if (turnindex % 2 == 0)  {
            printf("\n");
            print_board(board);
            playerchoice = check_for_input(board, turnindex);
            char playerchar = 'X';

            board[(playerchoice-(playerchoice%3)) / 3][playerchoice%3] = playerchar;
            turnindex += 1;
        } else {
            
            
            int move[2];
            
            print_board(board);
            printf("\n Com: \n");
            
            bestMove(board, move);

            board[move[0]][move[1]] = 'O';
            turnindex += 1;
        }
        
        if (check_for_win(board) == 'X' || check_for_win(board) == 'O') {
            break;
        }
    }

    // game ended
    printf("\n");
    print_board(board);
    
    if (check_for_win(board) == 't') {
        printf("You both suck. That's a draw!");
    } else {
        char playerchar = check_for_win(board);
        
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

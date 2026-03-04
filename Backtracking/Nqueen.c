#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 20

char board[MAX][MAX];

int n;

// safety function
bool isSafe(int row, int col){
    
    // horizontal check
    for(int i=0; i<n; i++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }

    // vertical check
    for(int i=0; i<n; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    
    // left diagonal check
    for(int i=row - 1, j=col - 1; i>=0  && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // right diagonal check
    for(int i=row - 1, j=col + 1; i>=0  && j<n; i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

// print solution
void printBoard(){
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
        printf("\n");
}

// solution function 
void Nqueen(int row){
    if (row == n){
        printBoard();
        return;
    }

    for(int col = 0; col < n; col++){
        if(isSafe(row, col)){
            board[row][col] = 'Q';
            Nqueen(row + 1);
            board[row][col] = '.';
        }
    }
}

int main(){
    int size;
    printf("Enter size of board : ");
    scanf("%d", &size);

    n = size;
    if (n < 1 || n > MAX){
        printf("invalid size");
        return 0;
    }
    memset(board, '.', MAX*MAX*sizeof(char)); 

    Nqueen(0);
    return 0;
}
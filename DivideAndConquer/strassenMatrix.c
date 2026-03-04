#include <stdio.h>
#include <stdlib.h>

// strassen matrix multiplication

void strassenMultiplication(int matA[][2], int matB[][2], int matC[][2]){
    int a = matA[0][0];
    int b = matA[0][1];
    int c = matA[1][0];
    int d = matA[1][1];

    int e = matB[0][0];
    int f = matB[0][1];
    int g = matB[1][0];
    int h = matB[1][1];
    
    int c11, c12, c21, c22;

    int M1 = (a + d) * (e + h);
    int M2 = (c + d) * e;
    int M3 = a * (f - h);
    int M4 = d * (g - e);
    int M5 = (a + b) * h;
    int M6 = (c - a) * (e + f);
    int M7 = (b - d) * (g + h);

    c11 = M1 + M4 - M5 + M7;
    c12 = M3 + M5;
    c21 = M2 + M4;
    c22 = M1 - M2 + M3 + M6;

    matC[0][0] = c11;
    matC[0][1] = c12;
    matC[1][0] = c21;
    matC[1][1] = c22;
}

// take matrix
void takeMat(int mat[2][2]){
    for (int i = 0; i < 2; i++){
        for(int j=0; j<2; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

// print matrix
void printMat(int mat[2][2]){
    for (int i = 0; i < 2; i++){
        for(int j=0; j<2; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matA[2][2] = {{0, 0}, {0, 0}};
    printf("Enter matrix A\n");
    takeMat(matA);

    int matB[2][2] = {{0, 0}, {0, 0}};
    printf("Enter matrix B\n");
    takeMat(matB);

    int matC[2][2] = {{0, 0}, {0, 0}};
    strassenMultiplication(matA, matB, matC);

    printf("Answer \n");
    printMat(matC);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// compute lps array

void computeLPSArray(char* pattern, int M, int* LPS){
    int length = 0, i = 1;
    LPS[0] = 0;
    while (i < M){
        if(pattern[i] == pattern[length]){
            length++;
            LPS[i] = length;
            i++;
        }
        else {
            if(length != 0){
                length = LPS[length - 1];
            }
            else {
                LPS[i] = 0;
                i++;
            }
        }
    }
}

// kmp search algorithm
void KMPSearch(char* pattern, char* text){
    int M = strlen(pattern); // size of pattern
    int N = strlen(text); // size of text

    int *LPS = malloc(M * sizeof(int)); // LPS array of pattern

    computeLPSArray(pattern, M, LPS);

    int i = 0, j = 0;

    while (i < N){
        if(pattern[j] == text[i]){
            i++;
            j++;
        }
        if(j == M){
            printf("Pattern found at index %d", i - j);
            j = LPS[j-1];
        }
        else if(i < N && pattern[j] != text[i]){
            if(j!=0){
                j = LPS[j-1];
            }
            else {
                i++;
            }
        }
    }
    free(LPS);
}

// driver code
int main(){
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    KMPSearch(pattern, text);
    return 0;
}
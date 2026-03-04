#include <stdio.h>
#include <string.h>

void searchPattern(char* pattern, char* text){
    int M = strlen(pattern); // size of pattern
    int N = strlen(text); // size of text

    for(int i=0; i<=N - M; i++){
        int j;
        for(j=0; j<M; j++){
            if (text[i+j] != pattern[j]) break;
        }

        if(j == M){
            printf("Pattern found at index %d", i);
        }
    }
}
// driver code
int main(){
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    searchPattern(pattern, text);
    return 0;
}
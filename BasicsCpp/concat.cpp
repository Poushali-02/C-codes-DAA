#include <iostream>
#include <cstring>
using namespace std;

void concatStr(char *str1, char *str2, char *newStr){
    while(*str1 != '\0'){
        *newStr = *str1;
        newStr++;
        str1++;
    }
    while(*str2 != '\0'){
        *newStr = *str2;
        newStr++;
        str2++;
    }

    *newStr = '\0';
}
int main(){
    char str1[100], str2[100], str3[200];

    // input
    cout << "Give a string ";
    cin.getline(str1, 100);

    // input
    cout << "\nGive another string ";
    cin.getline(str2, 100);

    concatStr(str1, str2, str3);
    
    cout << "\nAfter concatenation " << str3;
    return 0;
}

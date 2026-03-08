#include <iostream>
#include <cstring>
using namespace std;

void copyStr(char* str1, char* str2){
    while(*str1 != '\0'){
        *str2 = *str1;
        str2++;
        str1++;
    }
    *str2 = '\0';
}

int main(){
    char str1[100], str2[100];

    // input
    cout << "Give a string ";

    cin.getline(str1, 100);

    cout << "\nstr1 is " << str1;
    copyStr(str1, str2);
    
    // output
    cout << "\nstr2 is " << str2;
    return 0;
}
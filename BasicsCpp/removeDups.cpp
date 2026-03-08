#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void removeDuplicates(string &str){
    int n = str.length();
    int idx = 0;
    for(int i = 0; i < n; i++){
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]){
                break;
            }
        }
        if (i == j){
            str[idx++] = str[i];
        }
    }
    str.resize(idx);
}
int main(){
    string query;
    cout << "Enter a string (with duplicates): ";
    getline(cin, query);

    removeDuplicates(query);
    cout << "Answer " << query;
    return 0;
}
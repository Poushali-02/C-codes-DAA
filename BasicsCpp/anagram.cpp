#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool anagram(string &s1, string &s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main(){
    string query1, query2;
    cout << "Enter a string ";
    getline(cin, query1);
    
    cout << "Enter another string ";
    getline(cin, query2);

    if(anagram(query1, query2)){
        cout << "the strings are anagram\n";
    }
    else {
        cout << "the strings are not anagram\n";    
    }
    return 0;

}
#include <iostream>
#include <string>

using namespace std;

string compress(string &s){
    int n = s.length(), count = 1;
    if (n == 0) return "";
    
    string result = "";

    for(int i=1; i<=n; i++){
        if(s[i]==s[i-1]){
            count++;
        }
        else {
            result += s[i - 1];
            result += to_string(count);
            count = 1;
        }
    }
    
    return result;
}

int main(){
    string query;
    cout << "Enter string ";
    getline(cin, query);

    string res = compress(query);

    cout << "Compressed string " << res;

    return 0;
}
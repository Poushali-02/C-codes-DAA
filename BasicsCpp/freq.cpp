#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<char, int> a, pair<char, int> b){
    return a.second > b.second;
}

void frequencyTracker(string query){
    int frequency[256] = {0};
    int n = query.length();
    for(int i=0; i < n; i++){
        frequency[query[i]]++;
    }
    
    vector <pair <char, int>> count;
    
    for(int i=0; i < 256; i++){
        if(frequency[i] > 0){
            count.push_back({(char) i, frequency[i]});
        }
    }

    sort(count.begin(), count.end(), compare);
    
    for(auto &entry: count){
        cout << entry.first << ": " << entry.second << endl;
    }
    
}
int main(){
    string query;
    cout << "Enter a string ";
    getline(cin, query);

    frequencyTracker(query);

    return 0;
}
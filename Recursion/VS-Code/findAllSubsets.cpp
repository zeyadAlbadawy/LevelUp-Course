#include<iostream>
#include <vector>
#include <string>
using namespace std;

void getSubsets(string s, string tempS,int i, int j) {
    if(j == s.size()) {
        cout << tempS  << endl;
        return;
    }

    // Forward Direction 
    tempS.push_back(s[i]);
    getSubsets(s, tempS,i+1,j+1);

    // BackWard Direction
    tempS.pop_back();
    getSubsets(s, tempS, i, j+1);
}
int main() {
    string s;
    cin >> s;
    string tempS;
    getSubsets(s,tempS,0, 0);
}
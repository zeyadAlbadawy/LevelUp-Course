#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

bool customComp(string x, string y) {
    return x + y < y + x;
}
int main() {
    vector<string> arr = {"a", "ab", "aba"};
    sort(arr.begin(), arr.end(), customComp);
    for(auto elm : arr) 
       cout << elm << endl;

}

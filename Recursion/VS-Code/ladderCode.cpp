#include <iostream>
using namespace std;


int getNoOfWays(int n) {
    if(n < 0) return 0;
    if(n == 0) return 1;
    return getNoOfWays(n-1) + getNoOfWays(n-2) + getNoOfWays(n-3);
}

int main() {
    int n;
    cin >> n;
    int noOfWays = getNoOfWays(n);
    cout << noOfWays;
}
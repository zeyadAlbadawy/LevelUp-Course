#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getIdx(vector<string> arr, string s, int start, int end) {
    int mid = (start + end) / 2;
    while(start >= end) {
        int leftMid = mid - 1;
        int rightMid = mid + 1;
        if(arr[mid] == ""){
            // Move The mid to the nearest non empty field
            while(true) {
                if(leftMid < start && rightMid > end)
                  return -1;
                else if(arr[rightMid] != "") {
                    mid = rightMid;
                    break;
                } else if(arr[leftMid] != "") {
                    mid = leftMid;
                    break;
                }
            }
        } else if(arr[mid] == s)
           return mid;
        else if (arr[mid] > s) 
          end = mid - 1;
        else if(arr[mid] < s)
          start = mid + 1;
          
    }
}

int main() {
    string s;
    cin >> s;
    vector<string> arr = {"ai", "", "", "bat", "","", "car", "","","dog", ""};
    cout <<  getIdx(arr, s, 0, arr.size() - 1) << endl;

}
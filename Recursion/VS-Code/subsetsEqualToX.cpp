#include <iostream>
#include<vector>
using namespace std;

int getSubSetsEqualToSum(vector<int> arr, int sum,int i, int reminder) {
    // Base Case

    if(i == arr.size()) {
        if(reminder == 0)
           return 1;
        else return 0;
    }
    // Recursice Case
    // 1- Include The Current Element and Subtract its Value from the reminder
    int include = getSubSetsEqualToSum(arr, sum, i+1, reminder - arr[i]);
    // 1- Execlude The Current Element And There Is No Subtraction From the Reminder
    int execlude = getSubSetsEqualToSum(arr, sum , i+1, reminder);
    return include + execlude;
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    int sum = 6;
    int noOfSubsets = getSubSetsEqualToSum(arr, sum, 0, sum);
    cout << noOfSubsets << endl;
}
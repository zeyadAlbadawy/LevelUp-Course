#include <iostream>
#include <string>
#include <vector>
using namespace std;

void getNoOfSubsets(vector<string> &finalRes, string res, int open, int closed, int n, int i)
{
    // Base Case
    if (i == n * 2)
    {
        finalRes.push_back(res);
        return;
    }

    // Recursive Case
    // 1- Forward Direction
    if (open < n)
    {
        res.push_back('(');
        getNoOfSubsets(finalRes, res, open + 1, closed, n, i + 1);
        res.pop_back();
    }
    // 2- BackWard Direction
    if (closed < open)
    {
        res.push_back(')');
        getNoOfSubsets(finalRes, res, open, closed + 1, n, i + 1);
        res.pop_back();
    }
}
int main()
{
    int n;
    cin >> n;
    vector<string> finalRes;
    string s;
    getNoOfSubsets(finalRes, s, 0, 0, n, 0);
    for (auto elm : finalRes)
        cout << elm << endl;
}
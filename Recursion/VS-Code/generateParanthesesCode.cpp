#include <iostream>
#include <vector>
#include <string>
using namespace std;
void getPermute(vector<vector<int>> &finalRes, vector<int> &res, int i)
{
    if (i == res.size())
    {
        finalRes.push_back(res);
        return;
    }

    for (int k = i; k < res.size(); k++)
    {
        swap(res[k], res[i]);
        getPermute(finalRes, res, i + 1);
        swap(res[k], res[i]);
    }
}

int main()
{
        vector<vector<int>> finalRes;
        vector<int> nums = {1,2,3};
        getPermute(finalRes, nums, 0);

}
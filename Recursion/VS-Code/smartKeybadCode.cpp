#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> keybad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void getAllKeybad(string input, string output, int i, vector<string> &res)
{
    if (input[i] == '\0')
    {
        res.push_back(output);
        return;
    }

    int currDigit = input[i] - '0';
    if (currDigit == 0 || currDigit == 1)
        getAllKeybad(input, output, i + 1, res);

    for (int k = 0; k < keybad[currDigit].size(); k++)
    {
        getAllKeybad(input, output + keybad[currDigit][k], i + 1, res);
    }
    return;
}

int main()
{
    string input, output;
    cin >> input;
    vector<string> res;
    getAllKeybad(input, output, 0, res);
    for (auto elm : res)
        cout << elm << endl;
}
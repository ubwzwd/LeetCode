#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<vector<int>> dp;
    for(int i = 0; i < 10; i++)
    {
        vector<int> temp {1};
        dp.push_back(temp);
    }
    for(auto i : dp)
    {
        cout<<i[0];
    }
    return 0;
}
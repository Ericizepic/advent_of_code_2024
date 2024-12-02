#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    vector<int> v;

    ifstream file("input.txt");
    int left, right;
    unordered_map<int, int> map;

    for (int t =0; t<1000; t++)
    {
        file >> left >> right;
        v.push_back(left);
        if (map.find(right) == map.end())
            map[right] = 0;
        map[right] = map[right] + 1;
    }
    file.close();


    int ans = 0;
    for (auto u : v)
        if (map.find(u) != map.end())
            ans += map[u]*u;

    cout << ans << endl;

}
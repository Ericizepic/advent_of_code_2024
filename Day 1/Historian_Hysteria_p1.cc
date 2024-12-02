#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> left_v;
    vector<int> right_v;

    ifstream file("input.txt");
    int left, right;

    for (int t =0; t<1000; t++)
    {
        file >> left >> right;
        left_v.push_back(left);
        right_v.push_back(right);
    }
    file.close();

    sort(left_v.begin(), left_v.end());
    sort(right_v.begin(), right_v.end());

    int ans = 0;
    for (int t =0; t<1000; t++)
        ans += abs(left_v[t] - right_v[t]);

    cout << ans << endl;

}
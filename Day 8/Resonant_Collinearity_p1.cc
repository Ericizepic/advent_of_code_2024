#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <regex>
#include <unordered_set>

using namespace std;
using ll = long long;

// Overload operator<< to output a vector
ostream& operator<<(ostream& os, const vector<ll>& v) {
    for (const ll& value : v) {
        os << value << ' ';
    }
    return os;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string line;
    ll ans = 0;
    vector<ll> v;

    vector<string> map;
    ifstream file("input.txt");
    while (getline(file, line)) {
        map.push_back(line);
    }

    int n = map.size(), m = map[0].length();


    auto isantinode = [&](int row, int col)
    {
        for (int c = 48; c<= 122; c++)
        {
            unordered_set<int> set;
            for (int i = 0; i<n; ++i)
                for (int j = 0; j<m; ++j)
                {
                    int distkey = 1000*(row - i) + (col - j);
                    if ((int)map[i][j] == c)
                    {
                        if (set.contains(2*distkey))
                        {
                            // cout << (char)c <<" " << row << " " << col << " " << i << " " << j <<  " " << distkey << " "  << 2*distkey << " " << (bool)(set.find(2*distkey) != set.end()) << endl;
                            return true;
                        }
                        if (distkey % 2 == 0 && set.contains(distkey/2))
                        {
                            // cout << (char)c <<" " << row << " " << col << " " << i << " " << j <<  " " << distkey << " " << (bool)(set.find(distkey/2) != set.end()) << endl;
                            return true;
                        }
                        set.insert(distkey);
                    }
                }
        }
        return false;
    };

    for (int i = 0; i<n; ++i)
        for (int j = 0; j<m; ++j)
        {
            if (isantinode(i,j))
            {
                ans += 1;
            }
        }

    cout << ans << endl;
    return ans;
}

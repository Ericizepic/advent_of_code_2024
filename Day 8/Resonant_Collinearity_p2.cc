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

    vector<vector<bool>> isantinode(n, vector<bool>(m, false));
    for (int c = 48; c<= 122; c++)
    {
        for (int i = 0; i<n*m; ++i)
            for (int j = 0; j<n*m; ++j)
            {
                if (i != j)
                {
                    int row1 = i/m, row2 = j/m, col1 = i%m, col2=j%m;
                    if (map[row1][col1] == map[row2][col2] && map[row1][col1] != '.')
                    {
                        int currrow = row1, currcol = col1;
                        while (currrow >= 0 && currrow < n && currcol >= 0 && currcol < m)
                        {
                            isantinode[currrow][currcol] = true;
                            currrow += (row1 - row2);
                            currcol += (col1 - col2);
                        }
                        currrow = row2, currcol = col2;
                        while (currrow >= 0 && currrow < n && currcol >= 0 && currcol < m)
                        {
                            isantinode[currrow][currcol] = true;
                            currrow += (row2 - row1);
                            currcol += (col2 - col1);
                        }
                    }
                }    
            }
    }
    for (int i = 0; i<n; ++i)
        for (int j = 0; j<m; ++j)
        {
            if (isantinode[i][j])
            {
                ans += 1;
            }
        }

    cout << ans << endl;
    return ans;
}

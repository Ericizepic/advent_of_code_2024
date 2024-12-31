#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <regex>
#include <unordered_set>
#include <queue>
#include <numeric>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const vector<pll> dir = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
const string dirstring = ">v<^";


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
    vector<string>map;

    #ifndef NDEBUG
    ifstream file("input_test.txt");
    #endif
    #ifdef NDEBUG
    ifstream file("input.txt");
    #endif

    int sy,sx,ey,ex;
    while (getline(file, line)) {
        if (line.find('S') != string::npos)
        {
            sy = map.size();
            sx = line.find('S');
        }
        if (line.find('E') != string::npos)
        {
            ey = map.size();
            ex = line.find('E');
        }
        map.push_back(line);

    }
    int N = map.size(), M = map[0].size();
    auto in = [&](int x, int y)
    {
        return map[y][x] != '#';
    };

    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(M, vector<ll>(4, LONG_LONG_MIN)));
    priority_queue<tuple<ll, ll, pll>> q;
    q.push({0, 0, {sx, sy}});
    q.push({0, 1, {sx, sy}});
    q.push({0, 2, {sx, sy}});
    q.push({0, 3, {sx, sy}});

    while (!q.empty())
    {
        auto [val, d, p] = q.top();
        auto [x,y] = p;
        q.pop();

        if (x == ex && y == ey)
        {
            cout << -1*val + 1000 << endl;
            return val;
        }
        if (dp[y][x][d] < val)
        {
            // cout << "("<< x << "," << y << ") with direction: " << dirstring[d] << " " << -1*val << endl;

            dp[y][x][d] = val;
            for (int i = 0; i<4; i++)
            {
                if ((i-d+4)%4 != 2)
                {
                    auto [dx, dy] = dir[i];
                    ll newval = (i == d) ? val - 1 : val - 1001;
                    if (in(x + dx, y + dy))// && dp[y+dy][x+dx][i] < newval)
                    {
                        q.push({newval, i, {x + dx, y + dy}});
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return ans;
}

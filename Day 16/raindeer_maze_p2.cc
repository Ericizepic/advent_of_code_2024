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

// Overload operator<< to output a vector
ostream& operator<<(ostream& os, const vector<pll>& v) {
    for (const pll& value : v) {
        os << "(" << value.first << " " << value.second << ")";
    }
    return os;
}


auto render = [](vector<string>& map)
{
    for (auto row : map)
        cout << row << endl;
    cout << endl;
};

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
    priority_queue<tuple<ll, ll, pll, vector<pll>>> q;
    q.push({0, 0, {sx, sy}, {{sx, sy}}});
    q.push({0, 1, {sx, sy}, {{sx, sy}}});
    q.push({0, 2, {sx, sy}, {{sx, sy}}});
    q.push({0, 3, {sx, sy}, {{sx, sy}}});
    vector<vector<pll>> bestpaths;\
    ll best = LONG_LONG_MIN;
    while (!q.empty())
    {
        auto [val, d, p, vec] = q.top();
        auto [x,y] = p;
        q.pop();

        if (x == ex && y == ey)
        { 
            // cout << val << ": " << vec << endl;

            vec.push_back({x,y});
            if (val == best)
                bestpaths.push_back(vec);
            else if (val > best)
            {
                best = val;
                bestpaths.clear();
                bestpaths.push_back(vec);
            }
        }
        else if (dp[y][x][d] <= val)
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
                        vector<pll> newvec = vec;
                        newvec.push_back({x + dx, y + dy});
                        q.push({newval, i, {x + dx, y + dy}, newvec});
                    }
                }
            }
        }
    }
    for (auto path : bestpaths)
    {
        for (auto [x, y] : path)
        {

            if (map[y][x] != 'O')
                ans++;
            map[y][x] = 'O';
        }
    }
        
    
    render(map);

    cout << ans << endl;
    return ans;
}

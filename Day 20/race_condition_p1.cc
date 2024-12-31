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

vector<pll> dir = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};


auto render = [](vector<string>& map)
{
    for (auto row : map)
        cout << row << endl;
    cout << endl;
};

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const T& value : v) {
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

    int sx,sy,ex,ey;

    while (getline(file, line)) {
        if (line.find('S') != string::npos)
        {
            sx = line.find('S'); sy = map.size();
        }
        if (line.find('E') != string::npos)
        {
            ex = line.find('E'); ey = map.size();
        }
        map.push_back(line);
    }
    ll N = map.size(), M = map[0].size();
    auto valid = [&](int i, int j)
    {
        return 0 <= i && 0 <= j && i < N && j < M && map[i][j] != '#';
    };

    auto bfs = [&](auto valid_fct)
    {
        vector<vector<ll>> dp(N, vector<ll>(M, INT_MIN));
        using tlll = tuple<ll, ll ,ll>;
        priority_queue<tlll> pq;
        pq.push({0, sx, sy});
        dp[sy][sx] = 0;

        while (!pq.empty())
        {
            auto [val, x , y] = pq.top();
            pq.pop();

            for (auto [dx, dy] : dir)
            {
                if (valid_fct(y + dy, x + dx) && dp[y + dy][x + dx] < val - 1)
                {
                    dp[y + dy][x + dx] = val - 1;
                    pq.push({val - 1, x + dx, y + dy});
                }
            }
        }

        return dp[ey][ex];
    };

    ll base = bfs(valid);
    for (int r = 1; r<N-1; ++r)
    {
        for (int c = 1; c<M-1; ++c)
        {
            if (map[r][c] == '#')
            {
                auto mod_valid = [&](int i, int j)
                {
                    return (i == r && j == c) || valid(i, j);
                };

                if (bfs(mod_valid) - base >= 100)
                    ans++;

            }
        }
    }

    cout << ans << endl;
    return ans;
}

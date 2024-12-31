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

    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(N, vector<ll>(M, INT_MIN)));
    using tllll = tuple<ll, ll ,ll, ll>;
    priority_queue<tllll> pq;
    pq.push({0, 1, sx, sy});
    dp[1][sy][sx] = 0;
    while (!pq.empty())
    {
        auto [val, nc, x , y] = pq.top();
        pq.pop();

        for (auto [dx, dy] : dir)
        {
            if (valid(y + dy, x + dx))
            {
                if (dp[nc][y + dy][x + dx] < val - 1)
                {
                    dp[nc][y + dy][x + dx] = val - 1;
                    pq.push({val - 1, nc, x + dx, y + dy});
                }
            }
            else if (nc > 0)
            {
                if (dp[nc - 1][y + dy][x + dx] < val - 1)
                {
                    dp[nc - 1][y + dy][x + dx] = val - 1;
                    pq.push({val - 1, nc - 1, x + dx, y + dy});
                }
            }
        }
    }

    cout << dp[]

    cout << ans << endl;
    return ans;
}

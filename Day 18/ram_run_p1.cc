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

    #ifndef NDEBUG
    ifstream file("input_test.txt");
    #endif
    #ifdef NDEBUG
    ifstream file("input.txt");
    #endif

    ll N = 71, M= 71;
    vector<vector<bool>> map(N, vector<bool>(M, false));

    int bytes = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        int x,y; char c;
        iss >> x >>c >> y; 
        map[y][x] = true;
        bytes++;
        if (bytes == 1024)
            break;
    }
    
    auto valid = [&](int i, int j)
    {
        return 0 <= i && 0 <= j && i < N && j < M && !map[i][j];
    };

    vector<vector<ll>> dp(N, vector<ll>(M, INT_MAX));
    dp[0][0] = 0;
    queue<pll> q;
    q.push({0,0});
    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();
        for (auto d : dir)
        {
            auto [dx, dy] = d;
            if (valid(y + dy, x + dx) && dp[y + dy][x + dx] > dp[y][x] + 1)
            {
                dp[y + dy][x + dx] = dp[y][x] + 1;
                q.push({x + dx, y + dy});
            }
        }
    }



    cout << dp[N-1][M-1] << endl;
    return ans;
}
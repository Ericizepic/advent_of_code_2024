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
    vector<vector<ll>> map;
    #ifndef NDEBUG
    ifstream file("input_test.txt");
    #endif
    #ifdef NDEBUG
    ifstream file("input.txt");
    #endif
    while (getline(file, line)) {
        istringstream iss(line);
        map.push_back(vector<ll>());
        for (auto c : line)
            map.back().push_back(c - '0');
    }
    int N = map.size(), M = map[0].size();
    for (int row = 0; row < N; ++row)
        for (int col = 0; col < M; ++col)
        {
            if (map[row][col] == 0)
            {
                ll curr = 0;
                vector<vector<int>> dp(N, vector<int>(M, 0));
                vector<vector<bool>> visited(N, vector<bool>(M, false));

                typedef pair<int,int> pii;
                queue<pii> q;
                dp[row][col] = 1;
                q.push({row, col});

                while (!q.empty())
                {
                    auto [r,c] = q.front();
                    q.pop();
                    if (!visited[r][c])
                    {
                        visited[r][c] = true;
                        if (map[r][c] == 9)
                            curr+= dp[r][c];
                        if (r > 0 && map[r-1][c] == map[r][c] + 1)
                        {
                            q.push({r-1,c});
                            dp[r-1][c] += dp[r][c];
                        }
                        if (r < N-1 && map[r+1][c] == map[r][c] + 1)
                        {
                            q.push({r+1,c});
                            dp[r+1][c] += dp[r][c];
                        }
                        if (c > 0 && map[r][c-1] == map[r][c] + 1)
                        {
                            q.push({r,c-1});
                            dp[r][c-1] += dp[r][c];
                        }
                        if (c < M-1 && map[r][c+1] == map[r][c] + 1)
                        {
                            q.push({r,c+1});
                            dp[r][c+1] += dp[r][c];
                        }
                    }

                }
                #ifndef NDEBUG
                cout << curr << endl;
                #endif
                ans += curr;
            }
        }
    cout << ans << endl;
    return ans;
}

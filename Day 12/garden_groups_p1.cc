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
typedef pair<int,int> pii;

// Overload operator<< to output a vector
ostream& operator<<(ostream& os, const vector<ll>& v) {
    for (const ll& value : v) {
        os << value << ' ';
    }
    return os;
}

vector<pii> dir = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};



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

    vector<string> garden;
    while (getline(file, line)) garden.push_back(line);
    ll N = garden.size(), M = garden[0].length();

    auto in = [&](int i, int j)
    {
        return 0 <= i && 0 <= j && i < N && j < M;
    };

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i<N; ++i)
        for (int j = 0; j<M; ++j)
        {
            if (!visited[i][j])
            {
                int currA = 0;
                int currP = 0;
                queue<pii> q;
                q.push({i,j});
                visited[i][j] = true;
                while(!q.empty())
                {
                    auto [a , b] = q.front();
                    q.pop();
                    currA += 1;
                    for (auto [dx, dy] : dir)
                    {
                        if (!in(a+dx,b+dy) || garden[a+dx][b+dy] != garden[a][b])
                        {
                            currP += 1;
                        }
                        else if (!visited[a+dx][b+dy])
                        {
                            q.push({a + dx, b+dy});   
                            visited[a+dx][b+dy] = true;
                        }
                    }
                }
                #ifndef NDEBUG
                cout << currA << " " << currP << " " << garden[i][j] << endl;
                #endif
                ans += currA*currP;
            }
        }

    cout << ans << endl;

    return ans;
}

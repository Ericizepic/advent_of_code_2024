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
typedef tuple<int,int,int> tiii;


ostream& operator<<(ostream& os, const tiii& p) {
    os << "(" << get<0>(p) << ' ' << get<1>(p) << ' ' << get<2>(p) << ")";
    return os;
}

ostream& operator<<(ostream& os, const vector<ll>& v) {
    for (const ll& value : v) {
        os << value << ' ';
    }
    return os;
}

ostream& operator<<(ostream& os, const vector<tiii>& v) {
    for (const tiii& value : v) {
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
                vector<tiii> perim_v;
                vector<tiii> perim_h;

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
                            if (dx == 0)
                                perim_v.push_back({(dy == 1) ? b + 1 : b, a, dy});
                            else
                                perim_h.push_back({(dx == 1) ? a + 1 : a , b, dx});
                        }
                        else if (!visited[a+dx][b+dy])
                        {
                            q.push({a + dx, b+dy});   
                            visited[a+dx][b+dy] = true;
                        }
                    }
                }
                sort(perim_v.begin(), perim_v.end());
                sort(perim_h.begin(), perim_h.end());
                
                for (int iter = 0; iter < perim_h.size(); ++iter)
                {
                    if (iter == 0)
                    {
                        currP += 1;
                        continue;
                    }
                    auto [a1,b1,d1] = perim_h[iter];
                    auto [a2,b2,d2] = perim_h[iter-1];
                    if (a1 != a2 || b1 != b2 + 1 || d1 != d2)
                        currP += 1;
                }
                for (int iter = 0; iter < perim_v.size(); ++iter)
                {
                    if (iter == 0)
                    {
                        currP += 1;
                        continue;
                    }
                    auto [a1,b1,d1] = perim_v[iter];
                    auto [a2,b2,d2] = perim_v[iter-1];
                    if (a1 != a2 || b1 != b2 + 1 || d1 != d2)
                        currP += 1;
                }
                #ifndef NDEBUG
                cout << currA << " "<< currP << " " << perim_v << " | " << perim_h << " " << garden[i][j] << endl;
                #endif
                ans += currA*currP;
            }
        }

    cout << ans << endl;

    return ans;
}

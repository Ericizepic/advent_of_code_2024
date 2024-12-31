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
#include <set>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<pll> dir = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};


ostream& operator<<(ostream& os, const pll& p) {
    os << p.first << ", " << p.second;
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const T& value : v) {
        os << value << ' ';
    }
    return os;
}

long long encode(long long a, long long b) {
    return a * 1001 + b;
}

std::pair<long long, long long> decode(long long encoded) {
    return {encoded / 1001, encoded % 1001};
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    string line;
    ll ans = 0;
    vector<ll> v;
    vector<string> m;

    ifstream file("input.txt");

    int sx,sy,ex,ey;

    while (getline(file, line)) {
        if (line.find('S') != string::npos)
        {
            sx = line.find('S'); sy = m.size();
        }
        if (line.find('E') != string::npos)
        {
            ex = line.find('E'); ey = m.size();
        }
        m.push_back(line);
    }
    ll N = m.size(), M = m[0].size();
    auto valid = [&](int i, int j)->bool
    {
        return 0 <= i && 0 <= j && i < N && j < M && m[i][j] != '#';
    };



    vector<pll> path;
    map<pll, ll> distmap;
    set<pll> visited;
    pll curr = {ex, ey};
    ll currdist = 0;
    while (true)
    {
        path.push_back(curr);
        visited.insert(curr);
        distmap[curr] = currdist;
        if (curr == pll{sx, sy})
            break;
        auto [x,y] = curr;
        for (auto [dx, dy] : dir)
        {
            if (valid(y + dy, x + dx) && !visited.contains({x + dx, y + dy}))
            {
                curr = {x + dx, y + dy};
                currdist++;
                break;
            }
        }
    }


    // for (int i = 0; i<N; ++i)
    // {
    //     for (int j = 0; j<M;++j)
    //     {
    //         if (m[i][j] == '#')
    //             cout << "#  ";
    //         else   
    //             cout << distmap[{j,i}] << " ";
    //     }
    //     cout << endl;
    // }


    reverse(path.begin(), path.end());
    for (auto [x,y] : path)
    {     
        for (int i = 0; i<N; ++i)
            for (int j = 0; j<M; ++j)
            {   
                ll md = abs(i-y) + abs(j-x);
                if (valid(i,j) && md <= 20 && distmap[{j,i}] + md <= distmap[{x,y}] - 100)
                {
                    ans++;
                }
            }
    }

    

    cout << ans << endl;
    return ans;
}

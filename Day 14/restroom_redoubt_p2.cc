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
typedef pair<ll,ll> pll;

// Overload operator<< to output a vector
ostream& operator<<(ostream& os, const vector<ll>& v) {
    for (const ll& value : v) {
        os << value << ' ';
    }
    return os;
}

pll operator+(const pll& a, const pll& b) {
    return {a.first + b.first, a.second + b.second};
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
    vector<ll> q(4,0);
    int N = 103, M = 101, sim = 100;
    vector<vector<ll>> map(N, vector<ll>(M, 0));
    vector<pll> velocities, positions;
    while (getline(file, line)) {
        istringstream iss(line);
        ll xi,yi, vx, vy; char c; string s;
        iss >> c >> c >> xi >> c >> yi >> c >> c >> vx >> c >> vy;
        // cout << xi << " " << yi << " " << vx << " " << vy << endl;
        map[yi][xi] += 1;
        velocities.push_back({vx,vy});
        positions.push_back({xi,yi});       
    }
    
    ll best = 1e9;
    for (int i = 0; i<10000; i++)
    {
        auto render = [&]()
        {
            for (int row = 0; row < N; ++row)
            {
                for (int col = 0; col < M; ++col)
                {
                    cout << ((map[row][col] > 0) ? "*" : ".");
                }
                cout << endl;
            }
            cout << endl;
        };

        for (int j = 0; j<positions.size(); ++j)
        {
            auto [x,y] = positions[j];
            auto [vx,vy] = velocities[j];

            map[y][x]--;
            positions[j].first = ((x + vx)%M + M)%M;
            positions[j].second = ((y + vy)%N + N)%N;
            auto [xf,yf] = positions[j];
            map[yf][xf]++;
        }

        bool do_render = false;
        for (int row = 0; row < N; ++row)
        {
            int curr = 0;
            for (int col = 0; col < M; ++col)
            {
                if (map[row][col] > 0)
                    curr++;
                else
                {
                    if (curr > 8)
                        do_render = true;
                    curr = 0;
                }
            }
        }

        if (do_render)
        {
            render();
            cout << i << endl;
        }
    }
    return ans;
}

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
using pii = pair<ll, ll>;

// Overload operator<< to output a vector
ostream& operator<<(ostream& os, const vector<ll>& v) {
    for (const ll& value : v) {
        os << value << ' ';
    }
    return os;
}

vector<pii> dir = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};

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

    #ifndef NDEBUG
    ifstream file("input_test.txt");
    #endif
    #ifdef NDEBUG
    ifstream file("input.txt");
    #endif

    vector<string>map;
    string instructions;
    while (getline(file, line)) {
        if (line == "")
            break;
        string newline = "";
        map.push_back(line);
    }
    while (getline(file, line)) {
        instructions += line;
    }

    int N = map.size(), M = map[0].size(), x,y;
    for (int i = 0; i<N; ++i)
        for (int j = 0; j<M; ++j)
            if (map[i][j] == '@')
            {
                y = i; x = j;
            }


    auto move = [&](pii d)
    {
        auto [dx, dy] = d;
        int tx = x, ty = y;
        while (map[ty + dy][tx + dx] == 'O')
        {
            ty+=dy; tx += dx;
        }
        if (map[ty + dy][tx + dx] == '#')
            return;
        if (map[y + dy][x + dx] == 'O')
            map[ty + dy][tx + dx] = 'O';
        map[y][x] = '.';
        y += dy; x += dx;
        map[y][x] = '@';
    };

    for (char c : instructions)
    {
        if (c == '<')
        {
            move(dir[2]);
        }
        if (c == '^')
        {
            move(dir[3]);
        }
        if (c == '>')
        {
            move(dir[0]);
        }
        if (c == 'v')
        {
            move(dir[1]);
        }
    }
    for (int i = 0; i<N; ++i)
        for (int j = 0; j<M; ++j)
            if (map[i][j] == 'O')
            {
                ans += 100*i + j;
            }


    cout << ans << endl;
    return ans;
}

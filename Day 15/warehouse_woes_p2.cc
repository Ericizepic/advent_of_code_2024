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
        for (char c : line)
        {
            if (c == '#')
                newline += "##";
            if (c == 'O')
                newline += "[]";
            if (c == '.')
                newline += "..";
            if (c == '@')
                newline += "@.";
        }
        map.push_back(newline);
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


    function<bool(int, int, pii)> movable = [&](int xi, int yi, pii d)->bool
    {
        auto [dx, dy] = d;
        bool res = false;
        if (map[yi + dy][xi + dx] == '.')
            res = true;       
        if (map[yi + dy][xi + dx] == '#')
            res = false;
        if (map[yi + dy][xi + dx] == '[')
        {
            res = movable(xi + dx, yi + dy, d);
            if (dx == 0)
                 res &= movable(xi + dx + 1, yi + dy, d);
        }
        if (map[yi + dy][xi + dx] == ']')
        {
            res = movable(xi + dx, yi + dy, d);
            if (dx == 0)
                 res &= movable(xi + dx - 1, yi + dy, d);
        }
        return res;
    };


    function<void(int, int, pii)> move = [&](int xi, int yi, pii d)
    {
        auto [dx, dy] = d;
        if (map[yi + dy][xi + dx] == '[')
        {
           move(xi + dx, yi + dy, d);
           if (dx == 0)
                move(xi + dx + 1, yi + dy, d);
        }
        if (map[yi + dy][xi + dx] == ']')
        {
           move(xi + dx, yi + dy, d);
           if (dx == 0)
                move(xi + dx - 1, yi + dy, d);
        }
        if (map[yi + dy][xi + dx] == '.')
        {
            map[yi + dy][xi + dx] = map[yi][xi];
            map[yi][xi] = '.';
        }
        if (map[yi + dy][xi + dx] == '@')
        {
            x+=dx; y+= dy;
        }
    };

    // render(map);
    // cout << movable(x,y,dir[2]) << endl;
    // move(x,y,dir[2]);
    // render(map);
    for (char c : instructions)
    {
        if (c == '<' && movable(x , y, dir[2]))
        {
            move(x,y,dir[2]);
        }
        if (c == '^' && movable(x , y, dir[3]))
        {
            move(x,y,dir[3]);
        }
        if (c == '>' && movable(x , y, dir[0]))
        {
            move(x,y,dir[0]);
        }
        if (c == 'v' && movable(x , y, dir[1]))
        {
            move(x,y,dir[1]);
        }
        // render(map);
    }
    for (int i = 0; i<N; ++i)
        for (int j = 0; j<M; ++j)
            if (map[i][j] == '[')
            {
                ans += 100*i + j;
            }


    cout << ans << endl;
    return ans;
}

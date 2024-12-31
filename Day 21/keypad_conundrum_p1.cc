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
    vector<string>codes;
    ifstream file("input.txt");

    while (getline(file, line)) {
        codes.push_back(line);
    }

    unordered_map<char, pll> dkp_loc = {
        {'9', {0,2}},
        {'8', {0,1}},
        {'7', {0,0}},
        {'6', {1,2}},
        {'5', {1,1}},
        {'4', {1,0}},
        {'3', {2,2}},
        {'2', {2,1}},
        {'1', {2,0}},
        {'0', {3,1}},
        {'A', {3,2}},
    };

    unordered_map<char, pll> nkp_loc = {
        {'^', {0,1}},
        {'A', {0,2}},
        {'<', {1,0}},
        {'v', {1,1}},
        {'>', {1,2}},
    };

    auto sdkp_moves = [&](char a, char b) -> vector<string>
    {
        auto [ya, xa] = dkp_loc[a];
        auto [yb, xb] = dkp_loc[b];

        string xres(abs(xa - xb), ((xa < xb) ? '>' : '<'));
        string yres(abs(ya - yb), ((ya < yb) ? 'v' : '^'));
        if (ya == 3 && xb == 0)
            return {yres + xres};
        if (xa == 0 && yb == 3)
            return {xres + yres};
        return {xres + yres, yres + xres};
    };

    auto snkp_moves = [&](char a, char b) -> vector<string>
    {
        auto [ya, xa] = nkp_loc[a];
        auto [yb, xb] = nkp_loc[b];

        string xres(abs(xa - xb), ((xa <= xb) ? '>' : '<'));
        string yres(abs(ya - yb), ((ya <= yb) ? 'v' : '^'));
        if (ya == 0 && xb == 0)
            return {yres + xres};
        if (xa == 0 && yb == 0)
            return {xres + yres};
        return {xres + yres, yres + xres};
    };
    

    vector<unordered_map<string, ll>> dp(26);
    function<ll(string, int)> go = [&](string seg, int rem)->ll
    {
        if (dp[rem].contains(seg))
            return dp[rem][seg];
        if (rem == 0)
            return seg.size();
        seg = "A" + seg;
        ll res = 0;
        for (int i = 1; i<seg.size(); ++i)
        {
            auto options = snkp_moves(seg[i-1], seg[i]);
            if (options.size() == 1)
                res +=go(options[0] + "A", rem - 1);
            else
                res += min(go(options[0] + "A", rem - 1), go(options[1] + "A", rem - 1));
        }
        dp[rem][seg.substr(1)] = res;
        return res;
    };

    for (string code : codes)
    {
        string curr = "A" + code;
        ll len = 0;
        for (int i = 1; i<curr.size(); ++i)
        {
            auto options = sdkp_moves(curr[i-1], curr[i]);
            if (options.size() == 1)
                len +=go(options[0] + "A", 25);
            else
                len += min(go(options[0] + "A", 25), go(options[1] + "A", 25));
        }

        ll num = stoll(code);
        ans += num*len;
        cout << num << " " << len << endl;
    }


    cout << ans << endl;
    return ans;
}
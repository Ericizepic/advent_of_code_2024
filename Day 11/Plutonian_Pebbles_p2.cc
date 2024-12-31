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

    #ifndef NDEBUG
    ifstream file("input_test.txt");
    #endif
    #ifdef NDEBUG
    ifstream file("input.txt");
    #endif
    
    getline(file, line);
    istringstream iss(line);
    ll a;
    while (iss >> a) v.push_back(a);

    ll MAXL = 1000000LL;
    vector<vector<ll>> dp(76, vector<ll>(MAXL, -1));
    function<ll(ll,ll)> sim = [&](ll turns_left, ll n)->ll
    {
        if (turns_left == 0)
            return 1;
        if (n < MAXL && dp[turns_left][n] != -1)
            return dp[turns_left][n];

        ll res = -1;
        string ns = to_string(n);

        if (n == 0)
            res = sim(turns_left-1, 1);
        else if (ns.length() %2 == 0)
            res = sim(turns_left-1, stoll(ns.substr(0, ns.length()/2))) + sim(turns_left-1, stoll(ns.substr(ns.length()/2)));
        else
            res = sim(turns_left - 1, n*2024);

        if (n < MAXL)
            dp[turns_left][n] = res;
        return res;
    };

    for (auto a : v)
    {
        ans += sim(75, a);
        cout << ans << endl;
    }

    cout << ans << endl;
    return ans;
}

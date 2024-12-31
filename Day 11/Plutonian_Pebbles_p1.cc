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

    function<ll(ll,ll)> sim = [&](ll turns_left, ll n)->ll
    {
        if (turns_left == 0)
            return 1;
        
        if (n == 0)
            return sim(turns_left-1, 1);
        
        string ns = to_string(n);
        if (ns.length() %2 == 0)
            return sim(turns_left-1, stoll(ns.substr(0, ns.length()/2))) + sim(turns_left-1, stoll(ns.substr(ns.length()/2)));

        return sim(turns_left - 1, n*2024);
    };

    for (auto a : v)
        ans += sim(25, a);

    cout << ans << endl;
    return ans;
}

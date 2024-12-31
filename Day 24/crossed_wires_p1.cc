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
    vector<ll> v;
    vector<string>map;
    ifstream file("input.txt");
    string xstr, ystr;

    unordered_map<string, ll> seen;
    using tsss = tuple<string, string, string>;
    unordered_map<string, tsss> unused_instructions;
    while (getline(file, line)) {
        if (line == "")
            break;
        istringstream iss(line);
        string var; iss >> var; var.pop_back(); ll val; iss >> val;
        seen[var] = val;
        if (var[0] == 'x')
            xstr += to_string(val);
        if (var[0] == 'y')
            ystr += to_string(val);
    }
    while (getline(file, line)) {
        istringstream iss(line);
        string var1, var2, op, var, s; iss >> var1 >> op >> var2 >> s >> var;
        unused_instructions[var] = {var1, var2, op};
    }

    auto oper = [](ll a, ll b, string op)
    {
        if (op == "AND")
            return a&b;
        if (op == "OR")
            return a|b;
        if (op == "XOR")
            return a^b;
        return 1LL;
    };

    vector<pair<string, ll>> z;

    while (unused_instructions.size() > 0)
    {
        vector<string> used;
        for (auto [var, tup] : unused_instructions)
        {
            auto [var1, var2, op] = tup;
            if (seen.contains(var1) && seen.contains(var2))
            {
                seen[var] = oper(seen[var1], seen[var2], op);
                used.push_back(var);
                if (var[0] == 'z')
                    z.push_back({var, seen[var]});
            }
        }
        for (auto var : used)
            unused_instructions.erase(var);
    }

    sort(z.rbegin(), z.rend());
    string zstr = "";
    for (auto [var, val] : z)
    {
        zstr += to_string(val);
        ans = 2*ans + val;
    }

    cout << zstr<< endl;
    cout << ystr<< endl;
    cout << xstr<< endl;

    cout << ans << endl;
    return ans;
}

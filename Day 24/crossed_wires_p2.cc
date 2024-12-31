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
    ifstream file("input.txt");

    using tsss = tuple<string, string, string>;
    map<tsss, string> productions;
    while (getline(file, line)) {
        if (line == "")
            break;
        // istringstream iss(line);
        // string var; iss >> var; var.pop_back(); ll val; iss >> val;
        // // seen[var] = val;
    }
    while (getline(file, line)) {
        istringstream iss(line);
        string var1, var2, op, var, s; iss >> var1 >> op >> var2 >> s >> var;
        productions[{var1, var2, op}] = var;
        productions[{var2, var1, op}] = var;
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

    vector<string> cand;
    string c_i, u_i, v_i, w_i, x_i, y_i, z_i, x_ii, y_ii;

    for (int i = 0; i<=44; ++i)
    {
        if (i == 0)
        {
            // string res = productions[{"x00", "y00", "XOR"}];
            // if (res != "z00")
            //     cand.
            continue;
        }
        else if (i == 1)
        {
            c_i = "dhb";
            x_i = "x01";
            y_i = "y01";
            u_i = "qpp";
        }
        else
        {
            w_i = productions[{u_i, c_i, "AND"}];
            v_i = productions[{x_i, y_i, "AND"}];
            x_i = "x" + (i < 10 ? "0" + std::to_string(i) : std::to_string(i));
            y_i = "y" + (i < 10 ? "0" + std::to_string(i) : std::to_string(i));
            z_i = "z" + (i < 10 ? "0" + std::to_string(i) : std::to_string(i));


            u_i = productions[{x_i, y_i, "XOR"}];
            c_i = productions[{v_i, w_i, "OR"}];
            if (productions[{u_i, c_i, "XOR"}] != z_i)
            {
                cout << "ERROR " << i << " U:" << u_i << " V:" << v_i << " W:" << w_i << " C:" << c_i << endl;
                return 0;
            }
         }
    }

    // cout << unused_instructions.size() << endl;

    // while (unused_instructions.size() > 0)
    // {
    //     vector<string> used;
    //     for (auto [var, tup] : unused_instructions)
    //     {
    //         auto [var1, var2, op] = tup;
    //         if (seen.contains(var1) && seen.contains(var2))
    //         {
    //             seen[var] = oper(seen[var1], seen[var2], op);
    //             used.push_back(var);
    //             if (var[0] == 'z')
    //                 z.push_back({var, seen[var]});
    //         }
    //     }
    //     for (auto var : used)
    //         unused_instructions.erase(var);
    // }

    // sort(z.rbegin(), z.rend());
    // for (auto [var, val] : z)
    // {
    //     ans = 2*ans + val;
    //     cout << val << endl;
    // }
    // 57588078076750


    cout << ans << endl;
    return ans;
}

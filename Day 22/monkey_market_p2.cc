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

    while (getline(file, line)) {
        v.push_back(stoll(line));
    }

    auto evolve = [](ll secret)
    {
        secret = ((secret << 6)^secret)%16777216;
        secret = ((secret >> 5)^secret)%16777216;
        secret = ((secret << 11)^secret)%16777216;
        return secret;
    };

    vector<vector<ll>> seq(v.size(), vector<ll>(0));
    using tllll = tuple<ll, ll, ll, ll>;
    map<tllll, ll> m;

    for (int i = 0; i < v.size(); ++i)
    {
        set<tllll> seen;
        for (int t = 0; t <= 2000; ++t)
        {
            if (t == 0)
                seq[i].push_back(v[i]);
            else
            {
                seq[i].push_back(evolve(seq[i].back()));
            }
            if (t >= 4)
            {
                ll d0 = seq[i][t-3]%10 - seq[i][t-4]%10;
                ll d1 = seq[i][t-2]%10 - seq[i][t-3]%10;
                ll d2 = seq[i][t-1]%10 - seq[i][t-2]%10;
                ll d3 = seq[i][t]%10 - seq[i][t-1]%10;
                tllll key = {d0, d1, d2, d3};
                if (!seen.contains({key}))
                {
                    m[key] += seq[i][t]%10;
                    seen.insert(key);
                }
            }
        }
    }

    for (auto [k,val] : m)
    {
        ans = max(ans, val);
    }

    cout << ans << endl;
    return ans;
}

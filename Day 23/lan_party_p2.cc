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
    string ans;
    ll best = 0;
   
    ifstream file("input.txt");
    unordered_map<string, vector<string>> map;

    while (getline(file, line)) {
        string a = line.substr(0,2), b = line.substr(3,2);
        map[a].push_back(b);
        map[b].push_back(a);
    }


    auto validnetwork = [&](vector<string> network)
    {
        for (auto computer : network)
        {
            vector<string> cc = map[computer];
            for (auto computer1 : network)
            {
                if (computer1 != computer && find(cc.begin(), cc.end(), computer1) == cc.end())
                    return false;
            }
        };

        return true;
    };


    for (auto [k,v] : map)
    {
        int n = v.size();
        for (int i = 0; i<(1<<n); ++i)
        {
            vector<string> network;
            for (int j = 0; j<n; ++j)
            {
                if (i&(1<<j))
                    network.push_back(v[j]);
            }
            if (network.size() > best && validnetwork(network))
            {
                best = network.size();
                network.push_back(k);
                sort(network.begin(), network.end());
                ans = accumulate(network.begin(), network.end(), string(),
                    [](const std::string& a, const std::string& b) {
                        return a.empty() ? b : a +","+ b;
                    });
            }
            
        }
    }

    cout << ans << endl;
    return 1;
}

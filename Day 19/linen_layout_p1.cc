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
    string line,s;
    ll ans = 0;
    vector<ll> v;
    vector<string> units, targets;
    #ifndef NDEBUG
    ifstream file("input_test.txt");
    #endif
    #ifdef NDEBUG
    ifstream file("input.txt");
    #endif

    getline(file, line);
    istringstream iss(line);
    while (iss >> s)
    {
        if (s.back() == ',') s.pop_back();
        units.push_back(s);
    }
    getline(file, line);
    while (getline(file, line)) {
        istringstream iss(line);
        targets.push_back(line);
    }

    for(string target : targets)
    {
        vector<bool> dp(target.size(), false);
        for (int i = 0; i<target.size(); ++i)
            for (int j = 0; j<=i; ++j)
                if ((j == 0 || dp[j-1])&&any_of(units.begin(), units.end(), [&](string u){return u == target.substr(j, i-j+1);}))
                {
                    dp[i] = true;
                    break;
                }

        if (dp[target.size() - 1])
            ans += 1;
    }


    cout << ans << endl;
    return ans;
}

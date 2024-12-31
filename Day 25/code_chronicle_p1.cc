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
    string line, firstline;
    ll ans = 0;
    vector<vector<ll>> locks, keys;

    ifstream file("input.txt");
    while (getline(file, line)) {
        getline(file, firstline);
        bool islock = firstline[0] == '#';
        vector<ll> curr(5, (islock ? 0 : 5));

        for (int i = 0; i<6;++i)
        {
            getline(file, line);
            for (int j = 0; j<5; ++j)
                if (line[j] == firstline[j])
                    curr[j] += (islock ? 1 : -1);
        }
        if (firstline[0] == '#')
            locks.push_back(curr);
        else
            keys.push_back(curr);
    }
    
    auto fit = [](vector<ll> lock, vector<ll> key)
    {
        for (int i = 0; i<5; ++i)
            if (lock[i] + key[i]>5)
                return false;
        return true;
    };

    for (auto key : keys)
        for (auto lock : locks)
        {
            // cout << "lock: " << lock << " key: " << key << endl; 
            if (fit(lock, key))
                ans++;
        }


    cout << ans << endl;
    return ans;
}

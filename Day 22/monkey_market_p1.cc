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


   for (int i = 0; i<2000; ++i)
        for (auto &secret : v)
        {
            secret = evolve(secret);
        }
    
    cout << accumulate(v.begin(), v.end(), 0LL) << endl;
    return ans;
}

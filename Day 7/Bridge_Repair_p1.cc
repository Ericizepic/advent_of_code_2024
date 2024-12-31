#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <regex>
#include <unordered_set>

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

    ifstream file("input.txt");
    while (getline(file, line)) {
        vector<ll> v;
        istringstream iss(line);
        string obj_str; iss >> obj_str;
        obj_str.erase(obj_str.find(':'));
        ll obj = stoll(obj_str), a;

        while (iss >> a)
        {
            v.push_back(a);
        }

        int n = v.size() - 1;
        for (int i = 0; i<(1<<n); i++)
        {
            ll curr = v[0];
            for (int j = 0; j<n;j++)
            {
                curr = (i&(1<<j)) ? curr + v[j+1] : curr*v[j+1];
            }
            if (curr == obj)
            {
                // cout << obj << " " << i << " " << n << endl;
                // cout << v << endl;
                ans += obj;
                break;
            }
        }
    }
    cout << ans << endl;
    return ans;
}

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
    vector<ll> v;

    ifstream file("input.txt");
    getline(file, line);

    int n = line.length();
    for (int i = 0; i<n; i++)
    {
        int val = (i%2==0) ? i/2 : -1;
        for (int j = 0; j<line[i]-'0'; j++)
            v.push_back(val);
    }

    n = v.size();
    int l = 0, r = n - 1;
    while (0 <= l && l <n && 0 <= r && r < n && l < r) 
    {
        if (v[l] != -1)
            l++;
        else if (v[r] == -1)
            r--;
        else if (v[l] == -1 && v[r] != -1)
        {
            v[l++] = v[r];
            v[r--] = -1;
        }   
    }

    for (ll i = 0; i<v.size(); i++)
    {
        ans += i*max(v[i], 0LL);
    }
    cout << v << endl;
    cout << ans << endl;
    return ans;
}

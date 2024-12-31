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

auto concatll = [](ll a, ll b) -> ll{
    ll ans = b;
    while (b > 0)
    {
        a*=10;
        b/=10;
    }
    return ans + a;
};

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

        int n = v.size();

        function<bool(int, ll)> f = [&](int ind, ll curr) -> bool
        {
            if (ind == n)
            {
                return curr == obj;
            }

            
            return f(ind+1, curr + v[ind]) || f(ind+1, curr * v[ind]) || f(ind + 1, concatll(curr, v[ind]));
        };

        if (f(1, v[0]))
            ans += obj;
    }
    cout << ans << endl;
    return ans;
}

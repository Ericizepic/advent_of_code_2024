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
    vector<ll> files, space, v;
    vector<bool> files_used;

    ifstream file("input.txt");
    getline(file, line);

    int n = line.length();
    for (int i = 0; i<n; i++)
    {
        if (i%2==0)
        {
            files.push_back(line[i]-'0');
            files_used.push_back(false);
        }
        else
            space.push_back(line[i]-'0');
    }

    cout << files.size() << endl;


    for (int i = 0; i < files.size(); ++i)
    {
        for (int j = 0; j<files[i]; ++j) v.push_back(files_used[i] ? 0 : i);

        for (int j = files.size() - 1; j> i; --j)
        {
            if (!files_used[j] && files[j] <= space[i])
            {
                space[i] -= files[j];
                files_used[j] = true;
                for (int k = 0; k<files[j]; ++k) v.push_back(j);
            }
        }
        for (int j = 0; j<space[i]; ++j) v.push_back(0);
    }

    for (int i = 0; i<v.size(); ++i)
        ans += i*v[i];
    cout << v << endl;
    cout << ans << endl;
    return ans;
}

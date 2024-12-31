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
   
    ifstream file("input.txt");
    unordered_map<string, set<string>> map;

    while (getline(file, line)) {
        string a = line.substr(0,2), b = line.substr(3,2);
        map[a].insert(b);
        map[b].insert(a);
    }

    unordered_set<string> seen;
    for (auto [k,v] : map)
    {
        // want to see if we can find a loop of len 3 starting at k
        for (auto n1 : v)
        {
            auto v1 = map[n1];

            vector<string> intersection;
            set_intersection(v.begin(), v.end(), v1.begin(), v1.end(), back_inserter(intersection));
            for (auto n2 : intersection)
            {
                vector<string> temp = {n1, n2, k};
                sort(temp.begin(), temp.end());
                string hash = temp[0] + temp[1] + temp[2];
                if (!seen.contains(hash))
                {
                    if (temp[0][0] == 't' || temp[1][0] == 't' ||temp[2][0] == 't'  )
                    {
                        ans++;
                    }
                    seen.insert(hash);
                }
            }
        }
    }

    cout << ans << endl;
    return ans;
}

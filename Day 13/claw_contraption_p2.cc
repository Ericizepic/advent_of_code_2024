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

    #ifndef NDEBUG
    ifstream file("input_test.txt");
    #endif
    #ifdef NDEBUG
    ifstream file("input.txt");
    #endif

    auto process = [](string line, bool isprize)->pair<ll,ll>
    {
        string tx, ty, t;
        istringstream iss(line);
        if (!isprize)
            iss >> t >> t >> tx >> ty;
        else
            iss >> t >> tx >> ty;

        tx.pop_back();
        return {stoll(tx.substr(2)), stoll(ty.substr(2))};
    };

    while (getline(file, line)) {
        auto [ax, ay] = process(line, false);   
        getline(file,line);
        auto [bx, by] = process(line, false);   
        getline(file,line);
        auto [px, py] = process(line, true);   
        getline(file, line);

        px += 10000000000000LL;
        py += 10000000000000LL;

        if (ax*by != ay*bx)//might be a valid unique solution
        {
            ll det = ax*by - ay*bx;
            ll u = by*px-bx*py, v = ax*py-ay*px;
            if (u%det == 0 && v%det == 0 && u/det >= 0 && v/det >= 0)
            {
                ans += 3*u/det + v/det;
            }
        }
        else if (ax*py == ay*px)// might be valid infinite solution
        {
            cout << ax << " " << bx << " " << px << endl;
        }
        
    }

    cout << ans << endl;

    return ans;
}

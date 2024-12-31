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
    while (getline(file, line)) {
        int ax, ay, bx, by, px, py;
        string tx, ty, t;

        istringstream iss(line);
        iss >> t >> t >> tx >> ty;
        tx.pop_back();
        ax = stoll(tx.substr(2));
        ay = stoll(ty.substr(2));

        getline(file,line);
        iss.str(line);
        iss.clear();

        iss >> t >> t >> tx >> ty;
        tx.pop_back();
        bx = stoll(tx.substr(2));
        by = stoll(ty.substr(2));

        getline(file,line);
        iss.str(line);
        iss.clear();
        iss >> t >> tx >> ty;
        tx.pop_back();
        px = stoll(tx.substr(2));
        py = stoll(ty.substr(2));

        getline(file, line);

        int best = 1000;
        for (int i = 0; i<=100;++i)
            for (int j = 0; j<=100; ++j)
            {
                if (i*ax + j*bx == px && i*ay + j*by == py)
                {
                    best = min(best, 3*i + j);
                }
            }

        if (best != 1000)
            ans += best;
    }

    cout << ans << endl;

    return ans;
}

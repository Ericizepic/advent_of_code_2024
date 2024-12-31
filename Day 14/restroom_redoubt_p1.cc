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
    vector<ll> q(4,0);
    int N = 103, M = 101, sim = 100;
    while (getline(file, line)) {
        istringstream iss(line);
        ll xi,yi, vx, vy; char c; string s;
        iss >> c >> c >> xi >> c >> yi >> c >> c >> vx >> c >> vy;
        // cout << xi << " " << yi << " " << vx << " " << vy << endl;
        ll xf = ((xi + M + sim*vx)%M + M)%M, yf = ((yi + sim*vy)%N + N)%N;
        if (xf < M/2 && yf < N/2)
            q[0]++;
        if (xf < M/2 && yf > N/2)
            q[1]++;
        if (xf > M/2 && yf < N/2)
            q[2]++;
        if (xf > M/2 && yf > N/2)
            q[3]++;

    }
    ans = accumulate(q.begin(), q.end(), 1, [](int a, int b) {
        return a * b;
    });
    cout << q << endl;
    cout << ans << endl;
    return ans;
}

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string line;
	ll ans = 0;
	vector<ll> v;
    ifstream file("input.txt");

	while (getline(file, line)) {
		istringstream iss(line);
		int x;
        bool issafe = true;
        v.clear();
        while (iss >> x)
        {
            v.push_back(x);
        }

        for (int i = 0; i<v.size(); i++)
        {
            if (i > 0 && (v[i] - v[i-1])*(v[1] - v[0]) <= 0)
            {
                issafe = false;
                // cout << ans << " " << i << " " << v[i] << endl;
            }
            if (i > 0 && (abs(v[i] - v[i-1]) < 1 || abs(v[i] - v[i-1]) > 3))
            {
                issafe = false;
                // cout << ans << " " << i << " " << v[i] << endl;
            }
        }


        if (issafe)
            ans += 1;
	}
	cout << ans << '\n';
}
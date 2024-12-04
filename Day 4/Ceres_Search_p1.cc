#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <regex>

using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string line;
	ll ans = 0;
	// vector<ll> v;
    ifstream file("input.txt");
    bool enabled = true;
    vector<string> v;
	while (getline(file, line)) {
        v.push_back(line);
	}

    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i<n-2; i++)
    {
        for (int j = 0; j<m-2; j++)
        {
            if (v[i+1][j+1] == 'A')
            {
                bool cond1 = (v[i][j] == 'M' && v[i+2][j+2] =='S') || (v[i][j] == 'S' && v[i+2][j+2] =='M');
                bool cond2 = (v[i][j+2] == 'M' && v[i+2][j] =='S') || (v[i][j+2] == 'S' && v[i+2][j] =='M');
                if (cond1 && cond2)
                    ans++;
            }
        }
    }
	cout << ans << '\n';
}
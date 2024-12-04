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
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m-3; j++)
        {
            if (v[i].substr(j, 4) == "XMAS")
                ans++;
            if (v[i].substr(j, 4) == "SAMX")
                ans++;
        }
    }
    cout << ans << endl;
    for (int i = 0; i<n-3; i++)
    {
        for (int j = 0; j<m; j++)
        {
            if (v[i][j] == 'X' && v[i+1][j] == 'M' && v[i+2][j] == 'A' &&v[i+3][j] == 'S')
                ans++;
            if (v[i][j] == 'S' && v[i+1][j] == 'A' && v[i+2][j] == 'M' &&v[i+3][j] == 'X')
                ans++;
        }
    }
    cout << ans << endl;

    for (int i = 0; i<n-3; i++)
    {
        for (int j = 0; j<m-3; j++)
        {
            if (v[i][j] == 'X' && v[i+1][j+1] == 'M' && v[i+2][j+2] == 'A' &&v[i+3][j+3] == 'S')
                ans++;
            if (v[i][j] == 'S' && v[i+1][j+1] == 'A' && v[i+2][j+2] == 'M' &&v[i+3][j+3] == 'X')
                ans++;
        }
    }
    cout << ans << endl;

    for (int i = 0; i<n-3; i++)
    {
        for (int j = 3; j<m; j++)
        {
            if (v[i][j] == 'X' && v[i+1][j-1] == 'M' && v[i+2][j-2] == 'A' &&v[i+3][j-3] == 'S')
                ans++;
            if (v[i][j] == 'S' && v[i+1][j-1] == 'A' && v[i+2][j-2] == 'M' &&v[i+3][j-3] == 'X')
                ans++;
        }
    }
    cout << m << " " << n << endl;
	cout << ans << '\n';
}
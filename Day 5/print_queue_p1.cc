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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string line;
	ll ans = 0;
	vector<vector<ll>> v;
    ifstream file("input.txt");
	while (getline(file, line)) {
        if (line == "")
            break;
        replace(line.begin(), line.end(), '|', ' ');
        istringstream iss(line);
        int a, b; iss >> a >> b;
        v.push_back({a,b});
	}

    while (getline(file, line)) {
        istringstream iss(line);
        string token;
        vector<ll> temp;
        unordered_set<ll> seen;
        bool isvalid = true;
        while (getline(iss, token, ',') && isvalid) {
            int t = stoi(token);
            temp.push_back(t);
            for (auto p : v)
            {
                if (p[1] == t && seen.find(p[0]) == seen.end() && line.find(to_string(p[0])) != line.npos)
                {
                    isvalid = false;
                    // cout << t <<  " " << p[0] << " " << to_string(p[1]) << " " << line << endl;
                }
            }
            seen.insert(t);
        }

        if (isvalid)
        {
            ans += temp[temp.size()/2];
        }

    }
	cout << ans << '\n';
}
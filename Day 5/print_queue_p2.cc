#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <regex>
#include <unordered_set>
#include <functional>

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

    sort(v.begin(), v.end(), [](auto a, auto b) {
        return a[1] > b[1]; // Custom comparison: higher values come first
    });


    while (getline(file, line)) {
        istringstream iss(line);
        string token;
        vector<ll> temp;
        unordered_set<ll> seen;
        bool isvalid = true;
        while (getline(iss, token, ',')) {
            int t = stoi(token);
            temp.push_back(t);
            for (auto p : v)
            {
                if (p[1] == t && seen.find(p[0]) == seen.end() && line.find(to_string(p[0])) != line.npos)
                {
                    isvalid = false;
                }
            }
            seen.insert(t);
        }
        if (!isvalid)
        {
            vector<ll> correct_order;
            vector<bool> visited(100, false);
            
            function<void(int)> resolve_order = [&](int n) -> void {
                if (visited[n] || find(temp.begin(), temp.end(), n) == temp.end())
                {
                    return;
                }

                for (auto p : v)
                {
                    if (p[1] == n && find(temp.begin(), temp.end(), p[0]) != temp.end())
                    {
                        if (find(correct_order.begin(), correct_order.end(), p[0]) == correct_order.end())
                        {
                            resolve_order(p[0]);
                        }
                    }
                }
                correct_order.push_back(n);
                visited[n] = true;
            };

            for (int i = 0; i<100; i++)
                resolve_order(i);

            ans += correct_order[correct_order.size()/2];
        }

    }
	cout << ans << '\n';
}

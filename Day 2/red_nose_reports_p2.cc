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
    int t = 0;
	while (getline(file, line)) {
		istringstream iss(line);
		int x;
        bool issafe = true;
        int skip = -2;
        v.clear();
        while (iss >> x)
        {
            v.push_back(x);
        }


        auto check = [](vector<ll> v)
        {
            for (int i = 0; i<v.size(); i++)
            {
                bool cond1 = i > 0 && (v[i] - v[i-1])*(v[1] - v[0]) <= 0;
                bool cond2 = i > 0 && (abs(v[i] - v[i-1]) < 1 || abs(v[i] - v[i-1]) > 3);
                if (cond1 || cond2)
                {
                    return false;
                }
            }

            return true;
        };

        if (check(v))
        {
            ans+=1;
        }
        else{
            for (int skip = 0; skip<v.size(); skip++)
            {
                vector<ll> cp = v;
                cp.erase(cp.begin() + skip);
                if (check(cp))
                {
                    ans+=1;
                    break;
                }
            }
        }
	}
    
	cout << ans << '\n';
}
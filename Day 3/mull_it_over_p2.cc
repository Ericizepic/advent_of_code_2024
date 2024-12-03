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
	vector<ll> v;
    ifstream file("input.txt");
	regex pattern(R"(mul\(\d+,\d+\)|don't\(\)|do\(\))");
    bool enabled = true;

	while (getline(file, line)) {
        auto matches_begin = std::sregex_iterator(line.begin(), line.end(), pattern);
        auto matches_end = std::sregex_iterator(); // Default-constructed iterator is the end iterator
        for (sregex_iterator it = matches_begin; it != matches_end; ++it) {
            string match = (*it).str();
            if (match == "don't()")
                enabled = false;
            else if (match == "do()")
                enabled = true;
            else if (enabled)
            {
                int n = match.length();
                int ci = match.find(",");
                int a = stoi(match.substr(4, ci - 4));
                int b = stoi(match.substr(ci + 1, n - 2 - ci));
                ans += a*b;
            }
        }
	}
	cout << ans << '\n';
}
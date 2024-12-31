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
using pll = pair<ll, ll>;

vector<pll> dir = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};



auto render = [](vector<string>& map)
{
    for (auto row : map)
        cout << row << endl;
    cout << endl;
};

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
    vector<string>map;

    #ifndef NDEBUG
    ifstream file("input_test.txt");
    #endif
    #ifdef NDEBUG
    ifstream file("input.txt");
    #endif

    vector<ll> instructions = {2,4,1,2,7,5,0,3,1,7,4,1,5,5,3,0};
    reverse(instructions.begin(), instructions.end());
    vector<ll> vals;
    ll currA = 0;
    for (ll val : instructions)
    {
        currA = currA << 3;
        for (int a = 0; a <8; a++)
        {
            if ((a^5^((currA + a)>>(a^2)))%8 == val)
            {
                currA += a;
                break;
            }
        }
        cout << currA << endl;
    }
    
    cout << currA << endl;


    return ans;
}



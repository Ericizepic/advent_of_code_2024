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


    for (ll init_a = 0; init_a < 1000; init_a++)
    {
        ll a = init_a, b = 0, c = 0, opcode, operand;
        auto resolve_combo_operand = [&](ll o) -> ll
        {
            if (o <= 3)
                return o;
            if (o == 4)
                return a;
            if (o == 5)
                return b;
            if (o == 6)
                return c;
            
            throw invalid_argument("7 should not appear");
        };

        for (int i = 0; i <instructions.size(); i+= 2)
        {
            opcode = instructions[i];
            operand = instructions[i+1];

            if (opcode == 0)
            {
                a = a/(1<<resolve_combo_operand(operand));
            }
            if (opcode == 1)
            {
                b = b^operand;
            }
            if (opcode == 2)
            {
                b = resolve_combo_operand(operand)%8;
            }
            if (opcode == 3)
            {
                if (a != 0)
                    i = operand - 2;
            }
            if (opcode == 4)
            {
                b = b^c;
            }
            if (opcode == 5)
            {
                cout << resolve_combo_operand(operand)%8 << ",";
            }
            if (opcode == 6)
            {
                b = a/(1<<resolve_combo_operand(operand));
            }
            if (opcode == 7)
            {
                c = a/(1<<resolve_combo_operand(operand));
            }
        }
    }
    cout << endl;
    return ans;
}

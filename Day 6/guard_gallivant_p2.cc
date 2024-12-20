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
	vector<string> v;
    ifstream file("input.txt");
    int n = 0, m = 0;
    int init_row = -1, init_col = -1, curr_movement = 2;
    vector<pair<int,int>> movements = {{1,0}, {0,-1}, {-1,0}, {0,1}};
	while (getline(file, line)) {
        n++;
        v.push_back(line);
        if (find(line.begin(), line.end(), '^') != line.end())
        {
            init_row = n;
            init_col = find(line.begin(), line.end(), '^') - line.begin();
        }
	}

    m = v[0].size();
    v[0][0] = '#';

    for (int i = 0; i<n; i++)
        for (int j = 0;j<m; j++)
        {   
            if (v[i][j] == '.')
            {    
                cout << i << " " << j << endl;
                int curr_row = init_row, curr_col = init_col, curr_movement = 2;
                vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(4, false)));
                visited[curr_row][curr_col][curr_movement] = true;

                while (true)
                {
                    auto d = movements[curr_movement];
                    if (curr_row + d.first < 0 || curr_row + d.first >= n || curr_col + d.second < 0 || curr_col + d.second >= m)
                    {
                        break;
                    }
                    if (v[curr_row + d.first][curr_col + d.second] == '#' || (curr_row + d.first == i && curr_col + d.second == j))
                    {
                        curr_movement = (curr_movement + 1)%4;
                    }
                    else
                    {
                        if (visited[curr_row + d.first][curr_col + d.second][curr_movement])
                        {
                            ans++;
                            break;
                        }
                        visited[curr_row + d.first][curr_col + d.second][curr_movement] = true;
                        curr_row += d.first;
                        curr_col += d.second;
                    }
                }
            }
        }
    


	cout << ans << '\n';
}

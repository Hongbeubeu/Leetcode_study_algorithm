#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define ll long long
using namespace std;

void findMultiple(int max_value, unordered_map<int, ll> *temp_map)
{
    int pre_index = 3;
    temp_map->insert({3, 3});
    for (int i = 3; i <= max_value; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            temp_map->insert({i, temp_map->at(pre_index) + i});
            pre_index = i;
        }
    }
}

int main()
{
    int t;
    int max_value = 0;
    cin >> t;
    vector<int> numbers;
    for (int a0 = 0; a0 < t; a0++)
    {
        int n;
        cin >> n;
        numbers.push_back(n);
        if (n > max_value)
        {
            max_value = n;
        }
    }
    unordered_map<int, ll> *temp_map = new unordered_map<int, ll>;
    findMultiple(max_value, temp_map);
    unordered_map<int, ll>::iterator it;
    for (it = temp_map->begin(); it != temp_map->end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
    for (int i = 0; i < numbers.size(); i++)
    {
        unordered_map<int, ll>::iterator it;
        unordered_map<int, ll>::iterator pre_it = it;
        for (it = temp_map->begin(); it != temp_map->end(); it++)
        {
            if (numbers[i] == it->first)
            {
                cout << it->second << endl;
                break;
            }
            if (numbers[i] < it->first)
            {
                cout << pre_it->second << endl;
                break;
            }
            pre_it = it;
        }
    }

    return 0;
}

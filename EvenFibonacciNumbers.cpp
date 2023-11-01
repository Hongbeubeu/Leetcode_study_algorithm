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

int main()
{
    int t;
    cin >> t;
    vector<ll> fibonacies = {1, 2, 3, 5};
    ll max_fibo = 5;
    for (int a0 = 0; a0 < t; a0++)
    {
        long n;
        cin >> n;

        if (n < 2)
        {
            cout << 0 << endl;
            continue;
        }
        if (n >= 2 && n < 8)
        {
            cout << 2 << endl;
            continue;
        }

        ll sum = 2;
        ll s = 0;
        long i = 3;
        while (s < n)
        {
            s = fibonacies[i] + fibonacies[i - 1];
            if (s > max_fibo)
            {
                max_fibo = s;
                fibonacies.push_back(s);
            }
            i++;
            if (s >= n)
                break;

            if ((s & 1) == 0)
            {
                sum += s;
            }
        }
        cout << sum << endl;
    }
    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem?isFullScreen=true
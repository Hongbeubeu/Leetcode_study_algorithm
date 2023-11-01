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
#include <map>

#define ll long long
using namespace std;

ll SumOfMultiples(int k, int n)
{
    ll m = n / k;
    return k * m * (m + 1) / 2;
}

int main()
{
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++)
    {
        int n;
        cin >> n;

        ll sum = SumOfMultiples(3, n - 1) + SumOfMultiples(5, n - 1) - SumOfMultiples(15, n - 1);
        cout << sum << endl;
    }

    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem?isFullScreen=true
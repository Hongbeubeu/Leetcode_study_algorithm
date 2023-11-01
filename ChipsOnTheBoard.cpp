#include <iostream>
#define ll long long
using namespace std;
int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        ll x = 0, y = 0, u = 1e9, v = 1e9, c;
        for (int i = 0; i < n; i++)
            cin >> c, v = min(v, c), x += c;
        for (int i = 0; i < n; i++)
            cin >> c, u = min(u, c), y += c;
        cout << min((ll)(v * n + y), (ll)(u * n + x)) << endl;
    }
}
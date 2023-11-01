#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    int count = 0;
    int score_at_k = -1;
    for (int i = 0; i < n; i++)
    {
        int score;
        cin >> score;
        if (score > 0)
        {
            if (count < k)
                count++;
            else if (score >= score_at_k)
                count++;
            if (count == k && score_at_k == -1)
            {
                score_at_k = score;
            }
        }
    }
    cout << count;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define _GLIBCXX_DEBUG
using namespace std;

int bubbleSort(vector<int> &a, int n)
{
    bool flag = true;
    int count = 0;
    while (flag)
    {
        flag = false;
        for (int j = n - 1; j > 0; j--)
        {
            if (a.at(j) < a.at(j - 1))
            {
                swap(a.at(j), a.at(j - 1));
                count++;
                flag = true;
            }
        }
    }
    return count;
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N)
    {
        cin >> a.at(i);
    }

    int counts = bubbleSort(a, N);

    for (int i = 0; i < N; i++)
    {
        if (i == a.size() - 1)
        {
            cout << a.at(i) << endl;
        }
        else
        {
            cout << a.at(i) << " ";
        }
    }

    cout << counts << endl;

    return 0;
}

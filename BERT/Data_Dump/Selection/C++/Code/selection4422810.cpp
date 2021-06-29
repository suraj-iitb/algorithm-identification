#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define _GLIBCXX_DEBUG
using namespace std;

int selectionSort(vector<int> &a, int n)
{
    int count = 0;

    rep(i, n)
    {
        int minj = i;
        for (int j = i; j < n; j++)
        {
            if (a.at(j) < a.at(minj))
            {
                minj = j;
            }
        }
        if (i != minj)
        {
            swap(a.at(i), a.at(minj));
            count++;
        }
    }
    //cout <<"counts:" << count << endl;
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

    int counts = selectionSort(a, N);

    for (int i = 0; i < N; i++)
    {
        if (i)
        {
            cout << " ";
        }

        cout << a.at(i);
    }
    cout << endl;
    cout << counts << endl;
    return 0;
}

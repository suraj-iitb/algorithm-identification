// Bubble Sort
#include <bits/stdc++.h>
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
                auto temp = a.at(j);
                a.at(j) = a.at(j - 1);
                a.at(j - 1) = temp;
                flag = true;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a.at(i);

    int count = bubbleSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a.at(i);
        if (i == n - 1)
            cout << endl;
        else
            cout << ' ';
    }
    cout << count << endl;
}

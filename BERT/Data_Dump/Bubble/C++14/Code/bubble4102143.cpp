#include <cmath>
#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void printArr(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        if (i != A.size() - 1)
            cout << A[i] << " ";
        else
            cout << A[i];
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool flag = true;
    int count = 0;
    while (flag)
    {
        flag = false;
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] < a[i - 1])
            {
                int v = a[i];
                a[i] = a[i - 1];
                a[i - 1] = v;
                flag = true;
                count++;
            }
        }
    }
    printArr(a);
    cout << count << endl;

    return 0;
}


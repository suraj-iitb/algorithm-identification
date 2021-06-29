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
    int minv = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        minv = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[minv])
                minv = j;
        }
        if (i != minv)
        {
            swap(a[i], a[minv]);
            count++;
        }
    }
    printArr(a);
    cout << count << endl;
    return 0;
}


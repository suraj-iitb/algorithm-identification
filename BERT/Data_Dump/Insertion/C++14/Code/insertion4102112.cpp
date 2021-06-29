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
    printArr(a);
    for (int i = 1; i < n; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        printArr(a);
    }
    return 0;
}

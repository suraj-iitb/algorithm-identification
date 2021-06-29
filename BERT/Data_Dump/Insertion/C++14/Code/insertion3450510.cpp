/**
 * @file main.cpp
 * @author tarotene (tarotene@gmail.com)
 * @brief Insertion Sort (ALDS1_1_A)
 * @version 0.1
 * @date 2019-03-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <bits/stdc++.h>
using namespace std;

static const int MAX = 100000;

int main(int argc, char const *argv[])
{
    vector<int> A(MAX, 0);

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    cout << A[0];
    for (int k = 1; k < n; ++k)
    {
        cout << " " << A[k];
    }
    cout << endl;

    for (int i = 1; i < n; ++i)
    {
        int v = A[i];

        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        cout << A[0];
        for (int k = 1; k < n; ++k)
        {
            cout << " " << A[k];
        }
        cout << endl;
    }

    return 0;
}

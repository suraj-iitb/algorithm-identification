#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <cmath>
#include <vector>
#include <numeric>
#include <cstdio>
#include <bitset>
#include <map>
#include <string>
#include <valarray>
// #include <cctype>

using namespace std;

int main()
{   
    vector<int> sequence;
    int n;
    cin >> n;

    sequence.resize(n);

    int i = 0;
    while (i < n)
    {
        cin >> sequence[i];
        i++;
    }

    for (int i = 0; i < n; i++)
        cout << (i? " ": "") << sequence[i];
    cout << endl;

    for (int i = 1; i < n; i++)
    {
        int temp = sequence[i];

        int j = i-1;
        while (j >= 0 && temp < sequence[j])
        {
            sequence[j+1] = sequence[j];    
            j--;
        }
        sequence[j+1] = temp;

        for (int i = 0; i < n; i++)
            cout << (i? " ": "") << sequence[i];
        cout << endl;
    }
}

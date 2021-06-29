#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>

#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;
void printarray(int *a, int n)
{
    REP(i, n)
    {
        if (i > 0)
            cout << " ";
        cout << a[i];
    }
    cout << endl;
}

void insertionSort(int *a, int n)
{
    printarray(a, n);
    rep(i, 1, n)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        printarray(a, n);
    }
}
int main(void)
{
    int n;
    cin >> n;
    int a[101];
    REP(i, n)
    {
        cin >> a[i];
    }
    insertionSort(a, n);
}

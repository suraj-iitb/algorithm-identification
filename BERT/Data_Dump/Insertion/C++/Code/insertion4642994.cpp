#include <iostream>
#include <string>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>
#include <math.h>
#include <stack>
#include <queue>
#include <cstdio>
#include <iomanip>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
// #define req(j, n) for (ll j = 1; j < (n+1); j++)
// #define rer(k, n) for (ll k = 1; k < (n+1); k++)


int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) {
        cin >> A[i];
    }
    int v;
    int j;
    rep(i,N) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        rep(i,N) {
            if (i<N-1) {
                cout << A[i] << " ";
            } else {
                cout << A[i] << endl;
            }
        }
    }
    return 0;
}

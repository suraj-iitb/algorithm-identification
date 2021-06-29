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
    vector<int> A(100);
    rep(i,N) {
        cin >> A[i];
    }
    bool flag = 1;
    int count = 0;
    for (int i = 0; flag; i++) {
        flag = 0;
        for (int j = N - 1; j >= i+1; j--) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                flag = 1;
                count += 1;
            }
        }
    }
    rep(i,N) {
        if (i<N-1) {
            cout << A[i] << " ";
        } else {
            cout << A[i] << endl;
        }
    }
    cout << count << endl;
}

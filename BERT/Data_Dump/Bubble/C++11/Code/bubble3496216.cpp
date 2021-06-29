#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int bubblesort(int A[], int n) {

    int cnt = 0;

    for (int i = 1; i < n; i++) {
        int v;
        int j = i-1;
        bool can = true;

        while (can && j >= 0) {
            
            if (A[j] > A[j+1]) {
                v = A[j];
                A[j] = A[j+1];
                A[j+1] = v;
                j--;
                cnt++;
            }

            else 
                can = false;
        }
    }

    return cnt;
}

int main()
{   
    int n;
    cin >> n;

    int A[105];
    REP(i, n)   cin >> A[i];

    int cnt = bubblesort(A, n);

    REP(i, n-1)   cout << A[i] << " ";
                  cout << A[n-1] << endl;
                  
    cout << cnt << endl;
}

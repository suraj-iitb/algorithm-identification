#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int selectionSort(int A[], int n) {

    int cnt = 0;

    for (int i = 0; i < n-1; i++) {
        int mini = A[i];
        int j_tmp = i;

        for (int j = i+1; j < n; j++) {
            if (mini > A[j]) {
                mini = A[j];
                j_tmp = j;
            }
        }

        if (j_tmp != i) {
            swap(A[i], A[j_tmp]);
            cnt++;
        }
    }

    return cnt;
}

int main() 
{
    int N;
    cin >> N;

    int A[105];
    REP(i, N)   cin >> A[i];

    int ss = selectionSort(A, N);

    REP(i, N) {
        if (i)  cout << " ";
        cout << A[i];
    }

    cout << endl << ss << endl;
}

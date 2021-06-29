#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << "\n"
#define INF 1000000000
#define MAX 500000
#define SENTINEL 2000000000
typedef long long ll;

using namespace std;

int cnt = 0;
int n;
int S[MAX], SortedS[MAX];
int L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left, n2 = right - mid;
    REP(i, n1) { L[i] = A[left + i]; }
    REP(i, n2) { R[i] = A[mid + i]; }
    L[n1] = R[n2] = SENTINEL;
    int i = 0, j = 0;
    FOR(k, left, right)
    {
        cnt++;
        if ( L[i] <= R[j])
            A[k] = L[i++];
        else
        {
            A[k] = R[j++];
        }
    }
}

void mergeSort(int A[], int left, int right)
{
    if (left+1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    int A[MAX];
    cin >> n;
    REP(i, n) { cin >> A[i]; }
    mergeSort(A, 0, n);

    REP(i, n)
    {
        if (i)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
}


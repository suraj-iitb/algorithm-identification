#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000
int Left[MAX/2+2];
int Right[MAX/2+2];
int cnt;

void merge(int A[], int left, int right, int mid)
{
     int n1 = mid - left;
     int n2 = right - mid;
     for ( int i = 0; i < n1; i++ ) Left[i] = A[i+left];
     Left[n1] = SENTINEL;
     for ( int i = 0; i < n2; i++ ) Right[i] = A[i+mid];
     Right[n2] = SENTINEL;

     int i = 0;
     int j = 0;
     for ( int k = left; k < right; k++ ) {
            cnt++;
            if ( Left[i] <= Right[j] ) A[k] = Left[i++];
            else A[k] = Right[j++];
     }
}

void mergeSort(int A[], int left, int right)
{
    if(left + 1 < right) {
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, right, mid);
    }
}

int main() {
    int A[MAX], n ,i;
    cnt = 0;

    cin >> n;
    for ( i = 0; i < n; i++ ) cin >> A[i];

    mergeSort(A,0,n);

    for ( i = 0; i < n; i++ ) {
        if ( i ) cout << " ";
        cout << A[i];
    }
    cout << endl;

    cout << cnt << endl;

    return 0;
}


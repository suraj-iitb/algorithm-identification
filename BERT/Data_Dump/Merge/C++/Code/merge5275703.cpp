#include <iostream>
#include <bits/stdc++.h>
int L[10000000], R[10000000];
int comparisons=0;
int n;
using namespace std;
#define SENTINEL 1000000000
void merge(int A[], int l, int m, int r) 
{ 
  int n1 = m-l;
  int n2 = r-m;
  for ( int i = 0; i <=n1-1; i++ ) 
  {
      L[i] = A[l+i];
  }
  for ( int i = 0; i <=n2-1; i++ ) 
  {
      R[i] = A[m+i];
  }
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  int i, j;
  i = 0;
  j = 0;
  for ( int k = l; k < r; k++ ) 
  {
      comparisons++;
      if ( L[i] <= R[j] ) 
      {
        A[k] = L[i++];
      } 
      else 
      {
        A[k] = R[j++];      
      }
  }
}

void mergeSort(int A[], int l, int r) {
  if ( l+1 <=r-1 ) 
  {
    int m = (l+r)/2;
    mergeSort(A, l, m);
    mergeSort(A, m, r);
    merge(A, l, m, r);
  }
}

int main() 
{
  int A[2000000]; 
  comparisons = 0;

  cin >> n;
  for ( int i = 0; i < n; i++ ) 
  {
      cin >> A[i];
  }
  //call the function to sort the array
  mergeSort(A, 0, n);
  //print the array
    for ( int p = 0; p <=n-1; p++ ) 
    {
    if ( p ) 
    {
        cout << " ";
    }
    cout << A[p];
    }
    cout << endl<< comparisons << endl;
  
  return 0;
}

#include<bits/stdc++.h>

using namespace std;

int _count = 0;
int Arr[500000];
int L[500000];
int R[500000];
const int MAX = 999999999;

void merge(int A[], int l, int m, int r)
{
  int n1 = m - l;
  int n2 = r - m;

  for(int i = 0; i < n1; i++)
    L[i] = A[l + i];

  for(int i = 0; i < n2; i++)
    R[i] = A[m + i];
    L[n1] = MAX;
    R[n2] = MAX;

  int a = 0;
  int b = 0;
  for(int i = l; i < r; i++)
  {
    _count++;
    if(L[a] <= R[b])
    {
      A[i] = L[a];
      a++;
    }
    else
    {
      A[i] = R[b];
      b++;
    }
  }
}

void M_Sort(int A[], int l, int r)
{
  if(l + 1 < r){
    int m = (l + r) / 2;
    M_Sort(A, l, m);
    M_Sort(A, m, r);
    merge(A, l, m ,r);
  }
}

void printArr(int A[], int n)
{
  for(int i = 0; i < n-1 ; i++) cout << A[i] << " ";
  cout << A[n-1] << endl;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> Arr[i];


  M_Sort(Arr, 0, n);
  printArr(Arr, n);
  cout << _count << endl;
  return 0;
}


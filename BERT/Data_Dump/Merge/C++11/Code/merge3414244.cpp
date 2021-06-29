#include<cstdio>
//#include<iostream>
#include<climits>
using namespace std;
#define MAX 500000
int cnt = 0;
int A[MAX], L[MAX/2 + 2], R[MAX/2 + 2];
void Merge(int A[], int left, int mid, int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  for(int i=0; i<n1; i++)
  {
    L[i] = A[left+i]; //from left to mid-1
  }
  for(int i=0; i<n2; i++)
  {
    R[i] = A[mid+i];// from mid to right-1
  }
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  int i = 0, j = 0;
  for(int k=left; k<right; k++)
  {
    cnt++;
    if(L[i] <= R[j])
    {
      A[k] = L[i];
      i++;
    }
    else
    {
      A[k] = R[j];
      j++;
    }
  }
}

void MergeSort(int A[], int left, int right)
{
  if(left + 1 < right)
  {
    int mid = (left+right)/2 ;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    Merge(A,left, mid, right);
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
  }
  MergeSort(A, 0, n);
  for(int i=0; i<n; i++)
  {
    if(i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", cnt);

  return 0;
}


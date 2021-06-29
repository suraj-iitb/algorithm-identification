#include<cstdio>
#include<climits>
#include<iostream>
#define MAX 100000
using namespace std;

struct Card{ char s; int num;};
Card L[MAX/2 + 2], R[MAX/2 + 2];

int partition(Card C[], int p, int r)
{
  int i, j;
  i = j = p;
  int x = C[r].num;
  for(j=p; j<r; j++)
  {
    if(C[j].num <= x)
    {
      swap(C[j], C[i]);
      i++;
    }
  }
  swap(C[i], C[r]);
  return i;
}

void quickSort(Card C[], int p, int r)
{
  if(p < r)
  {
    int q = partition(C, p, r);
    quickSort(C, p, q-1);
    quickSort(C, q+1, r);
  }
}

void Merge(Card C[], int left, int mid, int right)
{
  int n1, n2;
  n1 = mid - left;
  n2 = right - mid;
  for(int i=0; i<n1; i++)
  {
    L[i] = C[left+i];
  }
  for(int i=0; i<n2; i++)
  {
    R[i] = C[mid+i];
  }
  L[n1].num = R[n2].num = INT_MAX;
  int i, j;
  i = j = 0;
  for(int k = 0; k < right-left; k++)
  {
    if(L[i].num <= R[j].num)
    {
      C[left+k] = L[i];
      i++;
    }
    else
    {
      C[left+k] = R[j];
      j++;
    }
  }
}

void MergeSort(Card C[], int left, int right)
{
  if(left < right - 1)
  {
    int mid = (left + right) / 2;
    MergeSort(C, left, mid);
    MergeSort(C, mid, right);
    Merge(C, left, mid, right);
  }
}
int main()
{
  struct Card A[MAX], B[MAX];
  int n;
  scanf("%d", &n);
  char s; int v;
  for(int i=0; i<n; i++)
  {
    getchar();
    scanf("%c %d", &s, &v);
    B[i].s = A[i].s = s;
    B[i].num = A[i].num = v;
  }
  MergeSort(B, 0, n);
  quickSort(A,0, n-1);
  int flag = 1;
  for(int i=0; i<n; i++)
  {
    if(B[i].s != A[i].s)
      flag = 0;
  }
  if(flag) printf("Stable\n");
  else printf("Not stable\n");
  for(int i=0; i<n; i++)
  {
    printf("%c %d\n", A[i].s, A[i].num);
  }

  return 0;
}


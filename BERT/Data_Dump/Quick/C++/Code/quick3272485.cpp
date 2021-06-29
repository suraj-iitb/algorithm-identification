#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;



typedef struct card
{
  char mark;
  int num;
}card;



/***** merge sort *****/
#define MAX 500000
#define INFINITY INT_MAX

card L[MAX/2+2], R[MAX/2+2];
int cnt;

void merge(card A[], int n, int left, int mid, int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  for(int i = 0; i < n1; i++) L[i] = A[left + i];
  for(int i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1].num = R[n2].num = INFINITY;
  for(int i = 0, j = 0, k = left; k < right; k++)
  {
    cnt++;
    if(L[i].num <= R[j].num) A[k] = L[i++];
    else A[k] = R[j++];
  }
}

void mergeSort(card A[], int n, int left, int right)
{
  if(left+1 < right)
  {
    int mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}



/***** quick sort *****/
int partition(card A[], int p, int r)
{
  int x = A[r].num;
  int i = p-1; // -1 ?

  for(int j = p; j < r; j++)
  {
    if(A[j].num <= x)
    {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i+1], A[r]);
  return i+1;
}

void quickSort(card A[], int p, int r)
{
  if(p < r)
  {
    int q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}





int main()
{
  int n;
  cin >> n;

  card A[100000];
  for(int i = 0; i < n; i++) cin >> A[i].mark >> A[i].num;

  card B[100000];
  for(int i = 0; i < n; i++) B[i] = A[i];

  //int q = partition(A, 0, n-1);
  quickSort(A, 0, n-1);
  mergeSort(B, n, 0, n);

  int isStable = 1;
  for(int i = 0; i < n; i++) if(A[i].mark != B[i].mark) isStable = 0;
  if(isStable == 0) cout << "Not stable" << endl;
  else cout << "Stable" << endl;

  for(int i = 0; i < n; i++) cout << A[i].mark << " " << A[i].num << endl;

  return 0;
}


#include <iostream>

using namespace std;

int com_count = 0;

void merge(int A[], int left, int mid, int right)
{
  int i ,j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[500000],R[500000];

  for(i = 0;i < n1;i++){
    L[i] = A[left + i];
  }
  for(i = 0;i < n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] = R[n2] = 1000000000;
  i = j = 0;

  for(k = left;k < right;k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
    com_count++;
  }
}

void mergeSort(int A[], int left, int right){
  if(left + 1 < right){
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}


int main(void)
{
  int i,n, A[500000];

  cin >> n;

  for(i = 0;i < n;i++){
    cin >> A[i];
  }

  mergeSort(A, 0, n);

  for(i = 0;i < n - 1;i++){
    cout << A[i] << ' ';
  }
  
  cout << A[i] << endl << com_count << endl;
  
  return 0;
}


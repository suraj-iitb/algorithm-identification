#include<bits/stdc++.h>
using namespace std;

#define MAX 500000
#define SENTINEL 2000000000

int num = 0;
void merge(int A[],int left,int mid,int right);
void mergesort(int A[],int left,int right);

int main() {
  int n;
  cin >> n;

  int A[n];
  for(int i = 0;i < n;i++) {
    cin >> A[i];
  }

  
  mergesort(A,0,n);

  for(int i = 0;i < n; i++) {
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << num << endl;

 
}

  void merge(int A[],int left,int mid, int right) {
    int n1 = right - mid;
    int n2 = mid - left;
    int L[MAX / 2 + 2],R[MAX / 2 + 2];
    for(int i = 0; i < n1;i ++) {
      R[i] = A[mid + i];
    }
    for(int i = 0;i < n2; i++) {
      L[i] = A[left + i];
    }

    R[n1] = SENTINEL;
    L[n2] = SENTINEL;
    int i = 0,j = 0;
    for(int k = left; k < right; k++) {
      num++;
      if(L[i] <= R[j]) {
        A[k] = L[i];
        i++;
      }else {
        A[k] = R[j];
        j++;
      }
    }


  }

  void mergesort(int A[],int left,int right) {
    if(left + 1 < right) {
      int mid = (left + right) / 2;
      mergesort(A,left,mid);
      mergesort(A,mid,right);
      merge(A,left,mid,right);
    }
  }


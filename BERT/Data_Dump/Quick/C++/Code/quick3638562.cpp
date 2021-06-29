#include<bits/stdc++.h>
using namespace std;

#define MAX 100000
#define SENTINEL 2000000000


typedef struct card {
  char ch;
  int num;
}Card;

int n;
Card A[MAX],B[MAX];
Card L[MAX / 2 + 2],R[MAX / 2 + 2];

void merge(Card A[],int left,int mid,int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1;i++) {
      L[i] = A[left + i];
    }
    for(int i = 0; i < n2;i++) {
      R[i] = A[mid + i];
    }

    L[n1].num = R[n2].num = SENTINEL;
    int i = 0,j = 0;
    for(int k = left; k < right; k++) {
      if(L[i].num <= R[j].num) {
        A[k] = L[i++];
      }else {
        A[k] = R[j++];
      }
    }
  }

  void mergesort(Card A[],int left,int right) {
    if(left + 1 < right) {
      int mid = (right + left) / 2;
      mergesort(A,left,mid);
      mergesort(A,mid,right);
      merge(A,left,mid,right);
    }
  }
    


int partition(Card A[],int p,int r) {
  int i = p - 1;
  Card t,x = A[r];
  for(int j = p; j < r; j++) {
    if(A[j].num <= x.num) {
      i++;
      t = A[i]; A[i] = A[j];A[j] = t;
    }
  }
  t = A[i + 1]; A[i + 1] = A[r]; A[r] = t;
  return i + 1;
}

void quicksort(Card A[],int p,int r) {
  int q;
  if(p < r) {
  q = partition(A,p,r);
  quicksort(A,p,q - 1);
  quicksort(A,q + 1,r);
  }
}


int main() {

 
  cin >> n;
  string ans = "Stable";
  
  for(int i = 0; i < n; i++) {
    cin >> A[i].ch >> A[i].num;
    B[i].ch = A[i].ch;
    B[i].num = A[i].num;
  }

  quicksort(A,0,n - 1);
  mergesort(B,0,n);

  for(int i = 0;i < n; i++) {
    if(A[i].ch != B[i].ch) {
      ans = "Not stable";
    }
  }
  
  cout << ans << endl;
  for(int i = 0;i < n; i++) {
    cout << A[i].ch << " " << A[i].num << endl;
  }

}

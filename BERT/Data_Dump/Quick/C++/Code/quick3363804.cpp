#include <iostream>
using namespace std;
#define MAX 100000
#define SENTINEL 2000000000

typedef struct {
  char suit;
  int value;
}card;

card L[MAX/2 +2],R[MAX/2 +2];

void merge(card A[],int n,int left,int mid,int right){
int  n1 = mid - left;
int  n2 = right - mid;
  for(int i = 0; i<n1; i++) L[i] = A[left + i];
  for(int i = 0; i<n2; i++) R[i] = A[mid + i];
  L[n1].value = R[n2].value = SENTINEL;
  int i = 0,j = 0;
  for(int k = left; k < right ; k++){
    if(L[i].value <= R[j].value){
      A[k] = L[i++];
    }else{
      A[k] = R[j++];
    }
  }
}

void mergeSort(card A[],int n,int left,int right){
  if(left+1 < right){
    int mid = (left + right)/2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}


int partition(card A[],int n,int p,int r){
  card x = A[r];
  int i = p - 1;
  for(int j = p ; j < r ; j++){
    if(A[j].value <= x.value){
      i=i +1;
      swap(A[i],A[j]);
    }
  }
  swap(A[i+1],A[r]);
  return i + 1;
}

void quicksort(card A[],int n,int p,int r){
  int q;
  if(p < r){
    q = partition(A,n,p,r);
    quicksort(A,n,p,q-1);
    quicksort(A,n,q+1,r);
  }
}

int main(){
  int n,v;
  card A[MAX],B[MAX];
  char S[10];
  int stable = 1;

  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> S >> v;
    A[i].suit = B[i].suit = S[0];
    A[i].value = B[i].value = v;
  }
  mergeSort(A,n,0,n);
  quicksort(B,n,0,n-1);
  for(int i = 0;i < n;i++){
    if(A[i].suit != B[i].suit) stable = 0;
  }
  if(stable == 1) cout << "Stable" << "\n";
  else cout << "Not stable" << "\n";
  for(int i = 0;i < n;i++){
    cout << B[i].suit << " " <<B[i].value<< "\n";
  }
  return 0;
}


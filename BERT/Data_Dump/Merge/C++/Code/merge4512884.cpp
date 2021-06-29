#include <iostream>
#include <cstdlib> 
#include <cmath>   
#define MAX 2500000  
using std::cout;   
using std::cin;    
using std::endl;


int n, cnt=0;
int L[MAX], R[MAX];
int S[MAX];
void merge(int *a, int left, int mid, int right){
  int n1=mid-left;
  int n2=right-mid;
  for(int i=0;i<n1;i++)
    L[i]=a[left+i];
  for(int i=0;i<n2;i++)
    R[i]=a[mid+i];
  L[n1]=(int)INFINITY;
  R[n2]=(int)INFINITY;  int i=0,j=0;
  for(int k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      a[k]=L[i++];
    }else{
      a[k]=R[j++];
    }
  }
}

void mergeSort(int *a, int left, int right){
  if(left+1 < right){
    //cnt++;
    int mid=(left+right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}

int main(){
  cin >> n;
  for(int i=0;i<n;i++)
    cin >> S[i];
  mergeSort(S,0,n);
  for(int i=0;i<n;i++){
    if(i) cout << " ";
    cout << S[i];
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}


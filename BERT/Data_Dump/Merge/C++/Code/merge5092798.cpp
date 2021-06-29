#include <bits/stdc++.h>
using namespace std;
#define MAX 500000
#define INF 1000000000
int cnt=0;
vector<int>A(MAX);
 vector<int>L(MAX);
  vector<int>R(MAX);

void merge(int left, int mid, int right){
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;
 
  //L[0...n1], R[0...n2] を生成
  
  for(i=0;i<n1;i++)
    L[i] = A[left + i];
  
  for(i=0;i<n2;i++)
    R[i] = A[mid + i];
  
  L[n1] =  R[n2] = INF;
  i = j = 0;
  
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
	}
    else {
      A[k]=R[j];
      j++;
	}
  }
}

void mergeSort(int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

int main(){
  int i,n;
  cin >> n;
  for(i=0;i<n;i++)cin >> A[i];
  mergeSort(0,n);

  for(i=0;i<n-1;i++)cout << A[i] << " ";
  cout << A[n-1] << endl;

  cout << cnt << endl;
  
  return 0;
}


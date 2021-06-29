#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& A,int left,int mid,int right,int& counter){
  int n1 = mid - left,n2 = right - mid;
  vector<int> L,R;
  L.resize(n1+1);
  R.resize(n2+1);
  for(int i=0;i<n1;i++){
    L[i] = A[left + i];
  }
  for(int i=0;i<n2;i++){
    R[i] = A[mid + i];
  }
  L[n1-1] > R[n2-1] ? L[n1] = R[n2] = L[n1-1]+1 : L[n1] = R[n2] = R[n2-1]+1;
  for(int i=0,j=0,k=left;k<right;k++){
    counter++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(vector<int>& A,int left,int right,int& counter){
  if(left+1<right){
    int mid = (left + right)/2;
    mergeSort(A,left,mid,counter);
    mergeSort(A,mid,right,counter);
    merge(A,left,mid,right,counter);
  }
}

int main(){
  vector<int> A;
  int n,counter=0;

  cin >> n;
  A.resize(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }

  mergeSort(A,0,n,counter);
  cout << A[0];
  for(int i=1;i<n;i++){
    cout << " " << A[i];
  }
  cout << endl << counter << endl;
}

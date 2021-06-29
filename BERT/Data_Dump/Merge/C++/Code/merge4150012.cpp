#include<iostream>
#include<vector>

#define MAX 1000000001
#define M    500000
using namespace std;

int count=0;
vector<int> L(M/2+2);
vector<int> R(M/2+2);

  void merge(int A[],int n,int left,int mid, int right){
    int  n1 = mid - left;
    int  n2 = right - mid;

    for(int i=0;i< n1;i++){
      L[i]= A[left+i];
    }
    for(int i=0;i< n2; i++){
      R[i]=A[mid + i];
    }
    L[n1]=MAX;
    R[n2]=MAX;
    int i=0;
    int j=0;
    for(int k= left ; k< right ; k++){
      count++;
      if(L[i]<=R[j]){
        A[k] = L[i];
        i++;
      }
      else {
        A[k] = R[j++];
      }
    }
  }


void mergeSort(int A[], int n,int left, int right){
  if ((left+ 1)< right){
    int    mid = (left + right)/2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}

int main(){
  int n=0;
  cin>>n;
  int A[M];
  for(int i=0;i<n;i++){
    cin>> A[i];
  }

  mergeSort(A,n, 0, n);

  for(int i=0;i< n; i++){
    cout<< A[i];
    if(i != n-1){
      cout<<" ";
    }
  }
  cout<< endl;
  cout<< count<<endl;

  return 0;
}


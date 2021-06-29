#include<iostream>

using namespace std;
#define N 500001

int counter=0;

void Merge(int A[],int left,int mid,int right){
  
  int n1,n2,i,j;
  int L[N],R[N];

  n1=mid-left;
  n2=right-mid;

  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }

  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1]=999999998;
  R[n2]=999999998;

  i=0;
  j=0;
  for(int k=left;k<right;k++){
    counter++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
  }

}

void MergeSort(int A[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    MergeSort(A,left,mid);
    MergeSort(A,mid,right);
    Merge(A,left,mid,right);
  }

}


int main(){

  int num,i;
  int data[N];
 
  cin >>num;

  for(i=0;i<num;i++){
    cin >>data[i];
  }

  MergeSort(data,0,num);

  for(i=0;i<num;i++){
    cout <<data[i];
    if(i!=num-1)cout <<" ";
  }
  cout <<endl;
  cout <<counter<<endl;
  return 0;

}

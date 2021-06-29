#include<iostream>
#include<stdio.h>
using namespace std;

#define N 100

int n;

void print(int A[]){
  int i;
  for(i=0; i<n-1; i++) printf("%d ",A[i]);
  cout<<A[i]<<endl;
}

int main(){
  int i,key,A[N],j;

  cin >> n;
  for(i=0; i<n; i++){
    cin >> A[i];
  }
  print(A);
  for(i=1; i<n; i++){
    key = A[i];
    j = i-1;
    while(j>=0 && A[j]>key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    print(A);
  }
  return 0;
}

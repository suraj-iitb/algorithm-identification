#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;

void argCout(int A[],int N){
  cout<<A[0];
  for(int i=1;i<N;i++){
    printf(" %d",A[i]);
  }
  cout<<endl;
}

void insertionSort(int A[],int N){
  for(int i=1;i<N;i++){
    int v=A[i];
    int k=i-1;
    while(k>=0 && A[k]>v){
      A[k+1]=A[k];
      k--;
    }
    A[k+1]=v;
    argCout(A,N);
  }
  
}

int  main(){
  int n;
  int A[1000];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  argCout(A,n);
  insertionSort(A,n);

  
  return 0;
}


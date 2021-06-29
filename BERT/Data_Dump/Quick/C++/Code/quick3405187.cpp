#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include <math.h>
#include<algorithm>
using namespace std;
#define MAX 100000
#define INFTY 1000000001

struct Card{
  char suit;
  int value;
};

Card A[MAX],B[MAX],L[MAX/2+1],R[MAX/2+1];


void merge(int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  for(int i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(int i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1].value=INFTY;
  R[n2].value=INFTY;
  int i=0;
  int j=0;
  for(int k=left;k<right;k++){
    if(L[i].value<=R[j].value){
      A[k]=L[i];
      i++;
    }else{
      A[k]=R[j];
      j++;
    }
  }

}

void mergeSort(int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  }
}


int partition(Card B[],int p,int r){
  int x=B[r].value;
  int i=p-1;
  for(int j=p;j<r;j++){
    if(B[j].value<=x){
      i++;
      swap(B[i],B[j]);
    }
  }
  swap(B[i+1],B[r]);
  return i+1;
}

void quickSort(Card B[],int p,int r){
  if(p<r){
    int q=partition(B,p,r);
    quickSort(B,p,q-1);
    quickSort(B,q+1,r);
  }
}

int main(){
  int n,stable=0;
  cin>>n;
  for(int i=0;i<n;i++){
    int value;
    char suit;
    cin>>suit>>value;
    A[i].suit=B[i].suit=suit;
    A[i].value=B[i].value=value;
  }
  mergeSort(0,n);
  quickSort(B,0,n-1);
  for(int i=0;i<n;i++){
    if(A[i].suit!=B[i].suit) stable++;
  }
  if(stable) cout<<"Not stable"<<endl;
  else cout<<"Stable"<<endl;

  for(int i=0;i<n;i++){
    printf("%c %d\n",B[i].suit,B[i].value);
  }



}


#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

void print(int n,int *X){

  for(int i=0;i<n;i++){
    cout<<X[i];
    if(i!=n-1)cout<<" ";
  }
  cout<<endl;

}

void insertion_sort(int n,int *X){

  print(n,X);
  
  for(int i=1;i<n;i++){
    int v = X[i];
    int j=i-1;
    while(j>=0 && v<X[j]){
      X[j+1]=X[j];
      j--;
    }
    X[j+1] = v;
    print(n,X);
  }
}

int bubble_sort(int n, int *X){

  int ch=0;
  //bool flag=false;
  int j=0;
  
  while(j<n-1){
    
    for(int i=0;i<n-j-1;i++){
      if(X[i]>X[i+1]){
	swap(X[i],X[i+1]);
	ch++;
      }
    }
    j++;
  }
  print(n,X);
  return ch;
}


int main(){

  int A[101];
  int N;
  
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>A[i];

  //insertion_sort(N,A);
  cout<<bubble_sort(N,A)<<endl;
  
  
 
  return 0;
}

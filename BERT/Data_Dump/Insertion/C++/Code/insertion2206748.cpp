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
   if(i!=n-1) cout<<" ";
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


int main(){

  int A[101];
  int N;
  
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>A[i];

  insertion_sort(N,A);
 

  
 
  return 0;
}

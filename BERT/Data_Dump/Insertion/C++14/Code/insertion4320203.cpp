#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
 	int N;cin >>N; 
 	int A[N]; 
 	for(int i=0;i<N;i++){
 	cin >>A[i];
 	}
  
  for(int i=0;i<N;i++){
  	int v=A[i];
    int j=i-1;
  	while(j>=0&&A[j]>v){
  	A[j+1]=A[j];
    j--;
    A[j+1]=v;
  	}
   for(int k=0;k<N;k++){
 	if(k==N-1&&i==N-1){cout <<A[k]<<endl;}
    else if(i<N-1&&k==N-1){cout <<A[k]<<endl;}
    else{cout<<A[k]<<' ';}
   }
  }
}
 

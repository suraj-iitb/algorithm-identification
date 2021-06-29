#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
  cin >>N;
  int A[N];
  for(int i=0;i<=N-1;i++){
  	cin >>A[i];
  }
   bool flag=1;
  int count=0;
  
  for(int i=0;flag;i++){
  	flag=0;
    for(int j=N-1;j>=0;j--){
    	if(A[j]<A[j-1]){
		swap(A[j],A[j-1]);
        count++;
        flag=1;}
    }
  }
  for(int i=0;i<=N-1;i++){
  	if(i==N-1){cout <<A[i];}
   	else{cout<<A[i]<<' ';}
  } 
  cout<<endl<<count<<endl;
}

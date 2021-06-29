#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
     long long N,A[10000];
     long long i;
     cin>>N;
     for( i=0;i<N;i++){
		cin>>A[i];
	
     if(i==N-1){
		cout<<A[i]<<endl;
	}
	else{
		cout<<A[i]<<" ";
	}
}
		if(i==N-1){
			cout<< endl;
		}
	 for(long long i=1;i<N;i++){
		 long long v=A[i];
		 long long j=i-1;
		 while(j>=0&&A[j]>v){
			 A[j+1]=A[j];
			 j--;
		 }
		 A[j+1]=v;
		 
	 for(long long i=0;i<N;i++){
		 if(i==N-1){
		 cout<<A[i];
	 }
	 else{
		 cout<<A[i]<<" " ;
	 }
   }
   cout<<endl; 
 }
}


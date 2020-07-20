#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000],i,j,flag=0,c=0;
int main(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	while(n>c){
	     for(j=n-1;j>=1;j--){
		     if(a[j]<a[j-1]){
			    swap(a[j],a[j-1]);
			    flag++;
		     }
		 }
		 c++;
		 j=n-1;
	 } 
	    for(i=0;i<n;i++){
		   if(i==n-1){
		      cout<<a[i]<<endl;
		       cout<<flag<<endl;
		   }
		   else{
			   cout<<a[i]<<" ";
		   }
	    }
}	 


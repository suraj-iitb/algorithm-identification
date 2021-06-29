#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[101],v,j,t=0;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<n; i++)
      for (int j=n-1; j>=i+1; j--){
      	  if (a[j]<a[j-1]){
      	      t++;
			  v=a[j];
			  a[j]=a[j-1];
			  a[j-1]=v;	
		  }
	  }
	cout<<a[0];
	for (int i=1; i<n; i++)
	    cout<<' '<<a[i];
	cout<<endl;
	cout<<t<<endl;
    return 0;
} 

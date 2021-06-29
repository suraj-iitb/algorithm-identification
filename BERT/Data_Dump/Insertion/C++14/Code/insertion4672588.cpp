#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[101],v,j,t=0;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    cout<<a[0];
	for (int i=1; i<n; i++){
		cout<<' '<<a[i];
	}
	cout<<"\n";
    for (int i=1; i<n; i++){
    	v=a[i];
    	j=i-1;
    	while (j>=0 && a[j]>v){
    		  a[j+1]=a[j];
    		  a[j]=v;
			  j--;
		}
		cout<<a[0];
	    for (int k=1; k<n; k++){
		    cout<<' '<<a[k];
	    }
	    cout<<"\n";
	} 
	
    return 0;
} 

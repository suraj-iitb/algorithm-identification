#include<bits/stdc++.h>
using namespace std;
static const int N = 105; 
int cont;
int n;
void SelectionSort(int *a){
	int mini;
	for(int i=0;i<n;i++){
		mini=i;
		for(int j=i+1;j<n;j++)
			if(a[j]<a[mini]){
				mini=j;
			}
	    if(i!=mini){
	      swap(a[i],a[mini]);
		    cont++;	
    	}
	}
}
int main(){
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	SelectionSort(a); 
	for(int i=0;i<n;i++){
		if(i!=n-1)
			cout<<a[i]<<" ";
		else
			cout<<a[i]<<endl;
	}
	cout<<cont<<endl;
	return 0;
}

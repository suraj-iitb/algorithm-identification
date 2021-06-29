#include <iostream>
using namespace std;



int insertionSort(int a[],int n){
    int v,j;
	for(int i=1;i<=n-1;i++){
		for(int ii=0;ii<n;ii++){
			if(ii!=n-1){
				cout<<a[ii]<<" ";
			}
			else{cout<<a[ii]<<endl;}
		}
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j--;
			a[j+1]=v;
		}
		/*
		for(int ii=0;ii<n;ii++){
			if(ii!=n-1){
				cout<<a[ii]<<" ";
			}
			else{cout<<a[ii]<<endl;}
		}
		*/
	}
	for(int i=0;i<n;i++){
		if(i!=n-1){
			cout<<a[i]<<" ";
		}else{
			cout<<a[i]<<endl;
		}
	}
		return 0;
}
int main(){
	int N,A[1001];
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
    insertionSort(A,N);
	int aa;cin>>aa;
	
	return 0;
}

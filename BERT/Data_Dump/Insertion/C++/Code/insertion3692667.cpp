#include<iostream>
using namespace std;
int a[101];
int j,v;
void sort(int N){
	for(int i=1;i<N;i++){
		v=a[i];
		j=i-1;
		while(a[j]>v&&j>=0){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for(int k=0;k<N;k++){
			if(k>0) cout<<" ";
			cout<<a[k];
		} 
		cout<<"\n";
	}
	
}
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	for(int k=0;k<N;k++){
			if(k>0) cout<<" ";
			cout<<a[k];
		}
	cout<<"\n"; 
	sort(N);
	
	
} 

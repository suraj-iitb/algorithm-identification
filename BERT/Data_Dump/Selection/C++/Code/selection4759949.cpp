#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
	int *n=a;
	a=b;
	b=n;
}

int SelectionSort(int a[],int n){
	int sum=0;
	int min;
	for(int i=0;i<n;i++){
		min=i;
		for(int j=i;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		} 
		if(a[i]!=a[min]){
			swap(a[i],a[min]);
			sum++;
		}
	}
	return sum;
}



int main(){
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++)cin>>a[i];
	
	int x=SelectionSort(a,n);
	for(int i=0;i<n;i++){
		if(i>0)cout<<" ";
		cout<<a[i]; 
	}
	cout<<endl<<x<<endl;
} 

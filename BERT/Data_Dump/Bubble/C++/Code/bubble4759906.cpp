#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
	int *n=a;
	a=b;
	b=n;
}

int BubbleSort(int a[],int n){
	int flag=1;
	int sum=0;
	int i=0;
	while(flag){
		flag=0;
		for(int j=n-1;j>=i+1;j--){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
				flag=1;
				sum++;
			}
		}
		i++;
	}
	return sum;
}



int main(){
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++)cin>>a[i];
	
	int x=BubbleSort(a,n);
	for(int i=0;i<n;i++){
		if(i>0)cout<<" ";
		cout<<a[i]; 
	}
	cout<<endl<<x<<endl;
} 

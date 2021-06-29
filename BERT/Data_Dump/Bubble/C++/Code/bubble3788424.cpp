#include<iostream>
using namespace std;

int bubbleSort(int a[],int n){
	int flag = 1;
	int num = 0;
	while(flag){
		flag = 0;
		for(int j=n-1;j>0;j--){
			if(a[j]<a[j-1]){
				int t;
				t = a[j];
				a[j] = a[j-1];
				a[j-1] = t;
				num++;
				flag = 1;
			}
		}
	}
	return num;
}

int main(){
	int n;
	cin>>n;
	int A[n],as;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	as = bubbleSort(A,n);
	for(int i=0;i<n;i++){
		if(i){
			cout<<" ";
		}
		cout<<A[i];
	}
	cout<<endl;
	cout<<as<<endl;
	return 0;
} 

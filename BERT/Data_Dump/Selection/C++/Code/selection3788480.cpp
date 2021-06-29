#include<iostream>
#include<algorithm>
using namespace std;

int selectionSort(int A[],int n){
	int num = 0;
	for(int i=0;i<n;i++){
		int min_num = i;
		for(int j=i+1;j<n;j++){
			if(A[min_num]>A[j]){
				min_num = j;
			}
		}
		if(i!=min_num){
			swap(A[i],A[min_num]);
			num++;
		}
	}
	return num;
}

int main(){
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	int as = selectionSort(A,n);
	for(int i=0;i<n;i++){
		if(i)
			cout<<" ";
		cout<<A[i];
	}
	cout<<endl;
	cout<<as<<endl;
	return 0;
}

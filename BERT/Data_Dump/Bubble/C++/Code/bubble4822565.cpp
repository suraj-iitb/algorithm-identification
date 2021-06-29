#include<iostream>
using namespace std;

int bubble_sort(int a[], int n){
	int sw = 0;
	bool flag = 1;
	for(int i = 0; flag; i++){
		flag = 0;
		for(int j = n -1; j >= i + 1; j--){
			if(a[j] < a[j-1]){
				swap(a[j],a[j-1]);
				sw++;
				flag = 1;
			}
		}
	}
	return sw;
}

void myPrint(int a[], int n){
	for(int i = 0; i < n; i++){
		if(i > 0)	cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
}

int main(){
	int a[100];
	int n;
	int sw;
	cin>>n;
	for(int i = 0; i < n; i++)	cin>>a[i];
	sw = bubble_sort(a,n);
	myPrint(a,n);
	cout<<sw<<endl;
	return 0;
}

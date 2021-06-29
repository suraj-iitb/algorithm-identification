#include<iostream>
#define SIZE 100
using namespace std;

int bubblesort(int a[],int size); 

int main(void){
	int a[SIZE];
	int size,i=0,time=0;
	cin>>size;
	for(i=0;i<size;i++){
		cin>>a[i];
	}
	time=bubblesort(a,size);
	for(i=0;i<size;i++){
		if(i) cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	cout<<time<<endl;	
	return 0;
}

int bubblesort(int a[],int size){
	int i,j,times=0;
	int key;
	while(size>1){
		for(i=0;i<size-1;i++){
			if(a[i]>a[i+1]){
				key=a[i];
				a[i]=a[i+1];
				a[i+1]=key;
				times++;
			}
		}
		size--;
	}
	return times;
}

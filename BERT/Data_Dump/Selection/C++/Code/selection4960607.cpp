#include<iostream>
#define SIZE 100
using namespace std;

int selectsort(int a[],int size); 

int main(void){
	int a[SIZE];
	int size,i=0,time=0;
	cin>>size;
	for(i=0;i<size;i++){
		cin>>a[i];
	}
	time=selectsort(a,size);
	for(i=0;i<size;i++){
		if(i) cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	cout<<time<<endl;
	return 0;
}
int selectsort(int a[],int size){
	int i,j,pos,times=0;
	int pivot;
	for(i=0;i<size;i++){
		pos=i;
		for(j=i;j<size;j++){
			if(a[pos]>a[j]){
				pos=j;
			}
		}
		if(pos!=i){
			pivot=a[i];
			a[i]=a[pos];
			a[pos]=pivot;
			times++;			
		}

	}
	return times;
}

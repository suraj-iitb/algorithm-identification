#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX=1e2+5;

//显示数组 
void showArray(int a[],int n){
	for(int i=0;i<n;i++){
		if(i>0){
			printf(" ");
		}
		printf("%d",a[i]);
	}
	printf("\n");
}
//冒泡排序 
void bubbleSort(int bs[],int n){
	int t=0;
	for(int i=n-1;i>0;i--){
		for(int j=n-1;j>n-i-1;j--){
			if(bs[j]<bs[j-1]){
				int temp=bs[j];
				bs[j]=bs[j-1];
				bs[j-1]=temp;
				t++;
			}
		}
	} 
	showArray(bs,n);
	printf("%d\n",t);
}

int main(){
	int n;
	int num[MAX];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	bubbleSort(num,n);
	return 0;
}

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
//插入排序 
void insertSort(int is[],int n){
	for(int i=1;i<n;i++){
		showArray(is,n);
		int t=is[i]; 
		int j;
		for(j=i-1;j>=0;j--){
			if(t<is[j]){
				is[j+1]=is[j];
				continue;
			}
			break;
		}
		is[j+1]=t;
	}
	showArray(is,n);
}

int main(){
	int n;
	int num[MAX];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	insertSort(num,n);
	return 0;
}

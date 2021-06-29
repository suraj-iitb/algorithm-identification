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
//选择排序 
void selectSort(int ss[],int n){
	int te=0;
	for(int i=0;i<n-1;i++){
		int tep=ss[i];
		int mmi=i;
		for(int j=i+1;j<n;j++){
			if(ss[j]<ss[mmi]){
				mmi=j;
				tep=ss[j];
			}
		}
		if(mmi!=i){
			ss[mmi]=ss[i];
			ss[i]=tep;
			te++;
		}
	}
	showArray(ss,n); 
	printf("%d\n",te);
}
int main(){
	int n;
	int num[MAX];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	selectSort(num,n);
	return 0;
}

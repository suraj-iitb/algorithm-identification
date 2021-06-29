#include <stdio.h>
using namespace std;
void trace(int a[],int n){//按顺序输出数组元素 
	int i;
	for(i=0;i<n;i++){
		if(i>0)	printf(" ");//在相邻元素之间输出一个空格
		printf("%d",a[i]); 
	}
	printf("\n");
}
void insertionSort(int a[],int n){
	int i,j,v;
	for(i=1;i<n;i++){
		v=a[i];//临时保存正待插入排序的元素 
		j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		trace(a,n);
	}
}
int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	trace(a,n);
	insertionSort(a,n);
	return 0;
} 

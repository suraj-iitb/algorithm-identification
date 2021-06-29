#include "stdio.h"

/*使用数组标记的方法，加快循环效率*/
int search(int A[],int n, int key){
	int i=0;
	A[n] = key;
	while(A[i]!=key) i++; /*当i=n时，相等跳出循环*/
	return i!=n; /*当i不等于n意思有相等的值*/
} 

int main(){

	int i,n,A[10001],q,key;
	int sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&key);
		if(search(A,n,key)) sum++;
	}
	printf("%d\n",sum);
	
	return 0;

} 

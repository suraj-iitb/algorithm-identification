#include <stdio.h>

//Bubble sort
void Bubble_sort(int A[],int n){
	int i,j,k,sum=0;
	int temp;
	for(i=0;i<n-1;i++) {
		for(j=0; j<n-i-1;j++){
			if(A[j]>A[j+1]) {
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				sum++;
			}
		}
	}
	
	//输出排序好的数组 
	for(k=0;k<n-1;k++){
		printf("%d ",A[k]);
	}	
	printf("%d\n",A[k]);
	printf("%d\n",sum);
	
} 


int main(int argc, char *argv[]) {
	int i,n;
	int newStr[100];	
	scanf("%d",&n);	
	for(i=0;i<n;i++){
		scanf("%d",&newStr[i]);
	} 		
	//调用冒泡函数
	Bubble_sort(newStr,n);
	return 0;
}

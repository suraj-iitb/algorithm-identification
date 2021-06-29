//1_2_B ???????????????3.4
#include<stdio.h>
#include<iostream>
#include<algorithm>

//spap??¢??°
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
	return ;
}

//??????????????¢??°
int printArray(int data[],int num){
	int i;
	for(i=0;i<num;i++){
		if(i!=0)printf(" ");
		printf("%d",data[i]);
	}
	printf("\n");
	return 0;
}

int main(){
	int i,j,k,A[100]={0},count=0;
	int n,min,minI;
	
	scanf("%d",&n);
	//??\???
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	//?????????
	for(j=0;j<n-1;j++){
		minI=j;
		for(i=j;i<n;i++){
			if(A[i]<A[minI]){
				minI=i;
			}
		}
		swap(&A[j],&A[minI]);	//??????
		if(A[j]!=A[minI])count++;
		//printArray(A,n);
	}
	
	printArray(A,n);
	std::cout<<count<<"\n";
	
	return 0;
}

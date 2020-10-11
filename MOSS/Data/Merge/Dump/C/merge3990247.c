#include<stdio.h> 
#define INFTY 1000000000

int cnt;


void merge(int A[],int left,int mid,int right){
	int n1=mid-left;		//左側の要素数
	int n2=right-mid;		//右側の要素数
	
	int L[n1],R[n2];
	
	int i,j,k;
	for(i=0;i<n1;i++){		//左半分の要素代入
		L[i]=A[left+i];
	}
	for(i=0;i<n2;i++){		//右半分の要素代入
		R[i]=A[mid+i];
	}
	L[n1]=INFTY;
	R[n2]=INFTY;
	i=0;
	j=0;
	for(k=left;k<right;k++){
		cnt++;
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}
	}
}


void mergeSort(int A[],int left,int right){
	int mid;
	if(right-left>1){	//両端の交差の有無で判断
		mid=(left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}


int main(void){
	int n;
	scanf("%d",&n);
	int i;
	int A[500000];
	cnt=0;
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	mergeSort(A,0,n);
	
	for(i=0;i<n;i++){
		if(i!=0){printf(" ");}
		printf("%d",A[i]);
	}
	
	printf("\n%d\n",cnt);
}
		
		
			

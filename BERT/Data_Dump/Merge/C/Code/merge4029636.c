#include <stdio.h>

int cnt=0;

void merge(int s[],int n,int left,int mid,int right){
	int i,j,k;
	int L[n];
	int R[n];
	int n1 = mid - left;
	int n2 = right - mid;
	
	for(i = 0;i<n1;i++){
		L[i] = s[left + i];
	}
	for(i = 0;i<n2;i++){
		R[i] = s[mid+i];
	}
	L[n1]=10000000000;
	R[n2]=10000000000;
	i = 0;
	j = 0;
	for(k = left;k<right;k++){
		cnt++;
		if(L[i]<=R[j]){
			s[k] = L[i++];
		}
		else{ 
			s[k] = R[j++];
		}
	}
}
	
void mergeSort(int s[],int n,int left,int right){
	if(left+1< right){
		int mid; 
		mid= (left + right)/2;
		mergeSort(s,n,left, mid);
		mergeSort(s,n,mid, right);
		merge(s,n,left,mid, right);
	}
}
	
int main(void){
	int i,n;
	int s[500000];
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	
	mergeSort(s,n,0,n);
	
	for(i=0;i<n;i++){
		if(i==n-1){
			printf("%d\n",s[i]);
		}
		else{
			printf("%d ",s[i]);
		}
	}
	
	printf("%d\n",cnt);
	
	return 0;
}

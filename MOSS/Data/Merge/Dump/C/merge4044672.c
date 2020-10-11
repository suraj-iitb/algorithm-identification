#include <stdio.h>
#define MAX 500000
#define INFTY 1000000000

int L[MAX / 2+2];
int R[MAX / 2 +2];
int cnt;

void merge(int s[], int left,int mid,int right){
	int i,j,k,n1,n2;
	
	n1 = mid - left;
	n2 = right - mid;
	
	//L[0...n1], R[0...n2] を生成
	for (i = 0;i< n1;i++){
		L[i] = s[left + i];
	}
	for (i = 0 ;i< n2;i++){
		R[i] = s[mid + i];
	}
	
	L[n1] = INFTY;
	R[n2] = INFTY;
	
	i = 0;
	j = 0;
	
	for (k = left; k< right;k++){
		cnt++;
		if (L[i] <= R[j]){
			s[k] = L[i];
			i = i + 1;
		}else {
			s[k] = R[j];
			j = j + 1;
		}
	}
}

void mergeSort(int s[],int left,int right){
	if(left+1 < right){
		int mid;
		mid = (left + right)/2;
		mergeSort(s, left, mid);
		mergeSort(s, mid, right);
		merge(s, left, mid, right);
	}
}

int main(){
	int n,i;
	int s[MAX];
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	
	mergeSort(s,0,n);
	
	for(i=0;i<n-1;i++){
		printf("%d ",s[i]);
	}
	printf("%d\n",s[n-1]);
	printf("%d\n",cnt);
	
	return 0;
}

#include <stdio.h>

#define NMAX 500001
#define SMAX 1000000000

int L[(NMAX/2)+2],R[(NMAX/2)+2];
int c;

void merge(int A[], int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	int i,j,k;
	for (i = 0; i < n1; i++){
		L[i] = A[left + i];
	}
	for (i = 0; i < n2; i++){
		R[i] = A[mid + i];
	}
	L[n1] = SMAX;
	R[n2] = SMAX;
	i = 0;
	j = 0;
	for(k = left; k < right; k++){
		c++;
		if(L[i] <= R[j]){
      		A[k] = L[i];
      		i = i + 1;
		}
		else{
      		A[k] = R[j];
      		j = j + 1;
		}
	}
}

void mergeSort(int A[], int n, int left, int right){
	int mid;
	if(left + 1 < right){
    	mid = (left + right) / 2;
   		mergeSort(A,n,left,mid);
    	mergeSort(A,n,mid,right);
    	merge(A,left,mid,right);
	}
}

int main(void){
	int i,n,zero=0;
	int S[NMAX];
	scanf("%d" ,&n);
	for(i = 0; i < n; i++){
		scanf("%d" ,&S[i]);
	}
	mergeSort(S,n,zero,n);
	for(i = 0; i < n; i++){
		if(i < n-1){
			printf("%d ",S[i]);
		}
		else{
			printf("%d\n",S[i]);
		}
	}
	printf("%d\n",c);
	
	return 0;
}

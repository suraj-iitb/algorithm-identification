#include<stdio.h>

int mergesort(int A[], int left, int right, int count[]);
int merge(int A[], int left, int mid, int right, int count[]);


int main(void){
	
	int n;
	scanf("%d", &n);
	
	int S[n], i, count[1]={0};
	for(i=0; i<n; i++){
		scanf("%d", &S[i]);
	}
	
	count[0]=mergesort(S, 0, n, count);
	
	for(i=0; i<n-1; i++){
		printf("%d ", S[i]);
	}
	printf("%d\n", S[i]);
	
	printf("%d\n", count[0]);
	
	return 0;
}
int merge(int A[], int left, int mid, int right, int count[]){
	int n1, n2;
	
	n1 = mid - left;//左配列の長さ
	n2 = right - mid;//右配列の長さ
	
	/*L[0...n1], R[0...n2] を生成*/
	int L[n1], R[n2];
	int i;
	for(i = 0; i<n1; i++) {
		L[i] = A[left + i];//生成
	}
	for(i = 0; i<n2; i++) {
		R[i] = A[mid + i];//生成
	}
	int j, k;
	
	i=0;
	j=0;
	for(k=left; k<right; k++){//全体回数
		if(n1==i){
			A[k]=R[j];
			j++;
			count[0]++;
		}
		else if(n2==j){
			A[k]=L[i];
			i++;
			count[0]++;
		}
		else if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
			count[0]++;
		}
		else if(R[j] <= L[i]){
			A[k] = R[j];
			j++;
			count[0]++;
		}
	}
	return count[0];
}

int mergesort(int A[], int left, int right, int count[]) {
	int mid;
	int c;
	if(2<=right-left){
		mid=(left+right)/2;
		mergesort(A, left, mid, count);//分ける
		mergesort(A, mid, right, count);
		c=merge(A, left, mid, right, count);
	}
	return c;
}


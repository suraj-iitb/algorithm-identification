#include<stdio.h>

#define SIZE 500000
#define MERGESIZE (SIZE/2+1)
#define SENTINEL (1000000000+1)

int S[SIZE];
int L[MERGESIZE], R[MERGESIZE];

int Merge(int A[], int left, int mid, int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  int i, j, k;
  
  for(i = 0; i <= n1-1; i++){
    L[i] = A[left + i];
  }
  for(i = 0; i <= n2-1; i++){
    R[i] = A[mid + i];
  }
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;

  i = 0;
  j = 0;
  for(k = left; k <= right-1; k++){
    if(L[i] <= R[j]){
		A[k] = L[i];
		i = i + 1;
	}else{
		A[k] = R[j];
		j = j + 1;
	}
  }

  return(right - left);
}

int Merge_Sort(int A[], int left, int right)
{
	int mid, c = 0;
	if(left+1 < right){
		mid = (left + right)/2;
		c += Merge_Sort(A, left, mid);
		c += Merge_Sort(A, mid, right);
		c += Merge(A, left, mid, right);
	}else{
		c = 0;
	}
	return(c);
}

int main()
{
	int n, i, c;

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &S[i]);
	}

	c = Merge_Sort(S, 0, n);
	for(i = 0; i < n-1; i++){
		printf("%d ", S[i]);
	}
	printf("%d\n%d\n", S[i], c);

	return(0);
}

#include<stdio.h>
#include<math.h>

int bubbleSort(int A[100], int n)
{
	int c, flag = 1, j, m; // ????????£??\????´?????????¨??????
	while(flag){
		flag = 0;
		for(j = n-1; j > 0; j--){ 
		if(A[j] < A[j-1]){
		 	m = A[j];
		 	A[j] = A[j-1];
		 	A[j-1]=m;
			flag = 1;
			A[n+1]++;
			}
		}
	}
	c = A[n+1];
	return c;
}

int main (void)
{
	int n, A[100]={0}, i, c;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
	
	c = bubbleSort(A,n);
	
	for(i=0; i<n; i++){
		printf("%d", A[i]);
		if(i != n-1) printf(" ");
		if(i == n-1) printf("\n");
	}
	
	printf("%d\n", c);
	
  return 0;
}


#include <stdio.h>

int main(void)
{
	int n,i,m[1000];
	
	 scanf("%d",&n);
	 for(i=0;i<n;i++)
	 scanf("%d",&m[i]);
	 
	 trace(m,n);
    insertionSort(m,n);
	
	return 0;
}
int insertionSort(int A[], int N){
	int i,j,v;
  for(i=1;i<N;i++)
   {
     v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v){
      A[j+1] = A[j];
     j--;
    }
   A[j+1] = v;
   trace(A,N);
}
}
void trace(int A[],int N){
	int i;
	for(i=0;i<N;i++){
		if(i>0)putchar(' ');
		printf("%d",A[i]);
	}
	printf("\n");

}

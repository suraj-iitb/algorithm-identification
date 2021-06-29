#include <stdio.h>
void selectionSort(int A[],int N){ 
   int i,j,count=0;
   int minj,v;
   for(i=0;i<=N-1;i++){
    	minj = i;
    	for(j=i;j<=N-1;j++){
       		if (A[j] < A[minj])
         		minj = j;
 		}
 		if(minj!=i) count++;
    	v=A[i];
    	A[i]=A[minj];
    	A[minj]=v;
    }
    for(i=0;i<N-1;i++){
    	printf("%d ",A[i]);
    }
    printf("%d\n",A[N-1]);
    printf("%d\n",count++);
}

int main(){
	int i,j,n;
	int num[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	selectionSort(num,n);
	return 0;
}
